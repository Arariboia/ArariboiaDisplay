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

        canDevice->setParent(this);
        if(!canDevice->connectDevice()) return;
        qInfo() << "CAN CONNECTED!";
        connect(canDevice, &QCanBusDevice::framesReceived, this, &CanController::processReceivedFrames);
        connect(canDevice, &QCanBusDevice::errorOccurred, this, &CanController::processErrors);

        // Creating managers
        _bmsCanManager = new BMSCANManager(canDevice, this);
        _motorCanManager = new MotorCANManager(this);
        _mavlinkCanManager = new MavlinkCanManager(this);

        // Redirect signals
        connect(_bmsCanManager, &BMSCANManager::DataReceived, this, [this](const bms_data_t &data){ emit BMSDataReceived(data); });
        connect(_motorCanManager, &MotorCANManager::DataReceived, this, [this](const motor_data_t &data){ emit MotorDataReceived(data); });
        connect(_mavlinkCanManager, &MavlinkCanManager::MPPTDataReceived, this, [this](const mavlink_mppt_t &data){ emit MPPTDataReceived(data); });
        connect(_mavlinkCanManager, &MavlinkCanManager::InstrumentationDataReceived, this, [this](const mavlink_instrumentation_t &data){ emit InstrumentatonDataReceived(data); });

        connect(_mavlinkCanManager, &MavlinkCanManager::MPPTStringsDataReceived, this, [this](const mavlink_mppt_strings_t &data){ emit MPPTStringsDataReceived(data); });
    }
}

void CanController::processErrors(QCanBusDevice::CanBusError error) const
{
    switch (error) {
    case QCanBusDevice::ReadError:
        qDebug() << "CAN ERROR: " << canDevice->errorString();
    case QCanBusDevice::WriteError:
        qDebug() << "CAN ERROR: " << canDevice->errorString();
    case QCanBusDevice::ConnectionError:
        qDebug() << "CAN ERROR: " << canDevice->errorString();
    case QCanBusDevice::ConfigurationError:
        qDebug() << "CAN ERROR: " << canDevice->errorString();
    case QCanBusDevice::UnknownError:
        qDebug() << "CAN ERROR: " << canDevice->errorString();
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
            qDebug() << "CAN ERROR: " << canDevice->interpretErrorFrame(frame);
            continue;
        }

        if(_bmsCanManager->handle_can_frame(frame)) continue;
        if(_motorCanManager->handle_can_frame(frame)) continue;
        if(_mavlinkCanManager->handle_can_frame(frame)) continue;
    }
}

void CanController::pollBMSData(){
    if(_bmsCanManager){
        _bmsCanManager->poll_bms_data();
    }
}

