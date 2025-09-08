#include "mpptwindow.h"
#include "ui_mpptwindow.h"

MpptWindow::MpptWindow(CanController *can, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MpptWindow),
    can(can)
{
    ui->setupUi(this);
}

MpptWindow::~MpptWindow()
{
    delete ui;
}

void MpptWindow::processMpptPacket(mavlink_mppt_t &data){
    double pvVoltage = data.pv_voltage / 100.0;
    double pvCurrent = data.pv_current / 100.0;
    double batteryVoltage = data.battery_voltage / 100.0;
    ui->pvVoltage_lcd->display(pvVoltage);
    ui->pvCurrent_lcd->display(pvCurrent);
    ui->batteryVoltage_lcd->display(batteryVoltage);
    ui->batteryCurrent_lcd->display(data.battery_current / 100.0);

    double mpptCurrent = (pvVoltage * pvCurrent * 0.98) / batteryVoltage;
    ui->currentMppt_lcd->display(mpptCurrent);
}


