#ifndef MAVLINKCANMANAGER_H
#define MAVLINKCANMANAGER_H

#include <QObject>
#include "can_manager.h"
#include "mavlink/arariboat/mavlink.h"

class MavlinkCanManager : public QObject, public ICANManager
{
    Q_OBJECT
public:
    explicit MavlinkCanManager(QObject *parent = nullptr);

    bool handle_can_frame(const QCanBusFrame &message) override;

signals:
    void MPPTDataReceived(const mavlink_mppt_t &data);
    void InstrumentationDataReceived(const mavlink_instrumentation_t &data);

public slots:
};

#endif // MAVLINKCANMANAGER_H
