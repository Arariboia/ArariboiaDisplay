#ifndef BATTERYWINDOW_H
#define BATTERYWINDOW_H

#include <QWidget>
#include "can/cancontroller.h"

namespace Ui {
class BatteryWindow;
}

class BatteryWindow : public QWidget
{
    Q_OBJECT

public:
    explicit BatteryWindow(CanController *can, QWidget *parent = nullptr);
    ~BatteryWindow();

private:
    Ui::BatteryWindow *ui;
    CanController *can;
    void setBatterySocValue(int value);

public slots:
    void processBMSPacket(const bms_data_t &data);
    void interceptCheckbox(bool value);
};

#endif // BATTERYWINDOW_H
