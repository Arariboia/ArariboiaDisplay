#ifndef CANCONTROLLER_H
#define CANCONTROLLER_H

#include <QObject>
#include "bms_can_manager.h"
#include "motor_can_manager.h"
#include "mavlinkcanmanager.h"
#include <QQueue>

class CanController : public QObject
{
    Q_OBJECT
public:
    explicit CanController(QObject *parent = nullptr);

private:
    BMSCANManager *_bmsCanManager = nullptr;
    MotorCANManager *_motorCanManager = nullptr;
    MavlinkCanManager *_mavlinkCanManager = nullptr;

    QQueue<QCanBusFrame> frameQueue;
    const QString pluginName = QStringLiteral("socketcan");
    QCanBusDevice *canDevice;
    bool isCanPLuginAvailable;

    void dequeueFrames(qint64 framesCount);
    void writeFrame(const QCanBusFrame &frame);

signals:
    void BMSDataReceived(const bms_data_t &data);
    void MotorDataReceived(const motor_data_t &data);
    void MPPTDataReceived(const mavlink_mppt_t &data);

    void MPPTStringsDataReceived(const mavlink_mppt_strings_t &data);

    void InstrumentatonDataReceived(const mavlink_instrumentation_t &data);

public slots:
    void processReceivedFrames();
    void processErrors(QCanBusDevice::CanBusError error) const;
    void pollBMSData();
};

#endif // CANCONTROLLER_H
