#include "cancontroller.h"
#include <QCanBus>
#include <QDebug>

CanController::CanController(QObject *parent) : QObject(parent)
{
    // --- Começar configuração CAN ---
    isCanPLuginAvailable = QCanBus::instance()->plugins().contains(QStringLiteral("socketcan"));

    if(!isCanPLuginAvailable){
        qDebug() << "No CAN plugin available.";
        return;
    }

    QString errorString;
    canDevice = QCanBus::instance()->createDevice(QStringLiteral("socketcan"), QStringLiteral("can0"), &errorString);
    if (!canDevice)
    {
        // Error handling goes here
        qDebug() << errorString;
    }
    else
    {
        qInfo() << "CAN CONECTADO";
        canDevice->connectDevice();
        connect(canDevice, &QCanBusDevice::framesReceived, this, &CanController::processReceivedFrames);
        connect(canDevice, &QCanBusDevice::errorOccurred, this, &CanController::processErrors);

        // Redirect signals
        connect(&_bmsCanManager, &BMSCANManager::DataReceived, this, [this](const bms_data_t &data){ emit BMSDataReceived(data); });
        connect(&_motorCanManager, &MotorCANManager::DataReceived, this, [this](const motor_data_t &data){ emit MotorDataReceived(data); });
        connect(&_mavlinkCanManager, &MavlinkCanManager::MPPTDataReceived, this, [this](const mavlink_mppt_t &data){ emit MPPTDataReceived(data); });
        connect(&_mavlinkCanManager, &MavlinkCanManager::InstrumentationDataReceived, this, [this](const mavlink_instrumentation_t &data){ emit InstrumentatonDataReceived(data); });
    }
}

void CanController::processErrors(QCanBusDevice::CanBusError error) const
{
    switch (error) {
    case QCanBusDevice::ReadError:
    case QCanBusDevice::WriteError:
    case QCanBusDevice::ConnectionError:
    case QCanBusDevice::ConfigurationError:
    case QCanBusDevice::UnknownError:
        qDebug() << canDevice->errorString();
        break;
    default:
        break;
    }
}

void CanController::processReceivedFrames()
{
    if(!canDevice) return;

    while(canDevice->framesAvailable() > 0){
        const QCanBusFrame frame = canDevice->readFrame();

        if (frame.frameType() == QCanBusFrame::ErrorFrame){
            qDebug() << canDevice->interpretErrorFrame(frame);
            continue;
        }

        if(_bmsCanManager.handle_can_frame(frame)) continue;
        if(_motorCanManager.handle_can_frame(frame)) continue;
        if(_mavlinkCanManager.handle_can_frame(frame)) continue;
    }
}

