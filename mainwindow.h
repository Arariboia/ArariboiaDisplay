#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "mavlink/arariboat/mavlink.h"
#include <QMainWindow>
#include <QCanBus>
#include "bms_can_manager.h"
#include "motor_can_manager.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void processReceivedFrames();

    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
    const QString pluginName = QStringLiteral("socketcan");
    QCanBusDevice *canDevice;
    bool isCanPLuginAvailable;

    BMSCANManager bmsCanManager;
    MotorCANManager motorCanManager;

    const quint32 motorCanID = 0x1;
    const quint32 instrumentationCanID = 0x2;

    void processErrors(QCanBusDevice::CanBusError error) const;
    void ProcessBMSData(const bms_data_t &data);
    void ProcessMotorLeftData(const motor_data_t &data);
    void ProcessMotorRightData(const motor_data_t &data);
    void ProcessMPPTData(const mavlink_mppt_t &data);
};
#endif // MAINWINDOW_H
