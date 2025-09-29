#include "mpptwindow.h"
#include "ui_mpptwindow.h"

MpptWindow::MpptWindow(CanController *can, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MpptWindow),
    can(can)
{
    ui->setupUi(this);
    connect(can, &CanController::MPPTDataReceived, this, &MpptWindow::processMpptPacket);

    connect(can, &CanController::MPPTStringsDataReceived, this, &MpptWindow::processMpptStringPacket);
}

MpptWindow::~MpptWindow()
{
    delete ui;
}

void MpptWindow::processMpptPacket(const mavlink_mppt_t &data){
    double pvVoltage = data.pv_voltage / 100.0;
    double pvCurrent = data.pv_current / 100.0;
    double batteryVoltage = data.battery_voltage / 100.0;
    ui->pvVoltage_lcd->display(pvVoltage);
    ui->pvCurrent_lcd->display(pvCurrent);

    double mpptCurrent = (pvVoltage * pvCurrent * 0.98) / batteryVoltage;
    ui->currentMppt_lcd->display(mpptCurrent);
}

void MpptWindow::processMpptStringPacket(const mavlink_mppt_strings_t &data){
    double string1 = data.string_1 / 1000.0;
    double string2 = data.string_2 / 1000.0;
    double string3 = data.string_3 / 1000.0;
    double string4 = data.string_4 / 1000.0;
    ui->string_1_lcd->display(string1);
    ui->string_2_lcd->display(string2);
    ui->string_3_lcd->display(string3);
    ui->string_4_lcd->display(string4);
}


