#include "propulsionwindow.h"
#include "ui_propulsionwindow.h"
#include <QDebug>

PropulsionWindow::PropulsionWindow(CanController *can, NetworkManager *network, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::PropulsionWindow),
    can(can),
    network(network)
{
    ui->setupUi(this);

    // Setting speedometers
    ui->rpmL_speedometer->setUnit("RPM");
    ui->rpmR_speedometer->setUnit("RPM");
    ui->rpmL_speedometer->setFont(QFont("Sans Serif", 18));
    ui->rpmR_speedometer->setFont(QFont("Sans Serif", 18));

    connect(can, &CanController::MotorDataReceived, this, &PropulsionWindow::processMotorPacket);
}

PropulsionWindow::~PropulsionWindow()
{
    delete ui;
}

void PropulsionWindow::processMotorPacket(const motor_data_t &data){
    if(data.motor == LEFT_MOTOR){
        // left motor
        ui->rpmL_speedometer->setValues(-1 * data.electrical_data.rpm, abs(data.electrical_data.rpm / 4500.0) * 100.0);
        ui->tempMotorL_lcd->display(data.state_data.motor_temp_C);
        ui->tempESCL_lcd->display(data.state_data.controller_temp_C);
    }
    else if(data.motor == RIGHT_MOTOR){
        // right motor
        ui->rpmR_speedometer->setValues(-1 * data.electrical_data.rpm, abs(data.electrical_data.rpm / 4500.0) * 100.0);
        ui->tempMotorR_lcd->display(data.state_data.motor_temp_C);
        ui->tempESCR_lcd->display(data.state_data.controller_temp_C);
    }
}

void PropulsionWindow::processEletronicPropulsionPacket(const mavlink_eletronic_propulsion_t &data){
    ui->direction_progressBar->setValue(data.helm_potentiometer / 3300);
}

void PropulsionWindow::on_graphL_btn_clicked()
{
    if(--graphIndex < 0) graphIndex = graphImageArraySize-1;
    ui->graph_lbl->setText(graphImageArray[graphIndex]);
}

void PropulsionWindow::on_graphR_btn_clicked()
{
    graphIndex = (graphIndex + 1) % graphImageArraySize;
    ui->graph_lbl->setText(graphImageArray[graphIndex]);
}

void PropulsionWindow::on_sendGraph_btn_clicked()
{
    QString functionName = "";
    if(graphIndex == 0) functionName = "linear";
    else if(graphIndex == 1) functionName = "exp";
    else if(graphIndex == 2) functionName = "log";
    network->postPropulsionData(functionName, -1, -1, -1);
}
