#ifndef BATTERYWINDOW_H
#define BATTERYWINDOW_H

#include <QWidget>
#include <QTimer>
#include "can/cancontroller.h"
#include "settingsmanager.h"

namespace Ui {
class BatteryWindow;
}

class BatteryWindow : public QWidget
{
    Q_OBJECT

public:
    explicit BatteryWindow(CanController *can, SettingsManager *settings, QWidget *parent = nullptr);
    ~BatteryWindow();

private:
    Ui::BatteryWindow *ui;
    CanController *can;
    SettingsManager *settings;
    QTimer pollTimer;
    void setBatterySocValue(int value);

public slots:
    void processBMSPacket(const bms_data_t &data);
    void interceptCheckbox(bool value);
};

#endif // BATTERYWINDOW_H
