#pragma once
#include <QCanBus>

class ICANManager {
public:
    virtual bool handle_can_frame(const QCanBusFrame &message) = 0;
    virtual ~ICANManager() = default;
};
