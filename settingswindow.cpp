#include "settingswindow.h"
#include "ui_settingswindow.h"
#include <QDebug>

SettingsWindow::SettingsWindow(SettingsManager *settings, NetworkManager *network, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SettingsWindow),
    settings(settings),
    network(network)
{
    ui->setupUi(this);

    if(settings->getPropulsionIP() == "") {
        settings->setPropulsionIP("localhost");
    }
    ui->propulsionIp_lineEdit->setText(settings->getPropulsionIP());

    ui->deadZone_dSpinBox->setValue(settings->getPropulsionDeadZone());
    ui->cutZone_dSpinBox->setValue(settings->getPropulsionCutZone());
    ui->slope_dSpinBox->setValue(settings->getPropulsionSlope());

    if(settings->getBMSPollDelay() == 0){
        settings->setBMSPollDelay(5000);
    }
    ui->bmsPollDelay_spinBox->setValue(settings->getBMSPollDelay());
}

SettingsWindow::~SettingsWindow()
{
    delete ui;
}

void SettingsWindow::on_propulsionIp_lineEdit_editingFinished()
{
    settings->setPropulsionIP(ui->propulsionIp_lineEdit->text());
}

void SettingsWindow::on_bmsPollDelay_spinBox_editingFinished()
{
    settings->setBMSPollDelay(ui->bmsPollDelay_spinBox->value());
}

void SettingsWindow::on_pushButton_clicked()
{
    settings->setPropulsionDeadZone(ui->deadZone_dSpinBox->value());
    settings->setPropulsionCutZone(ui->cutZone_dSpinBox->value());
    settings->setPropulsionSlope(ui->slope_dSpinBox->value());
    network->postPropulsionData("", ui->deadZone_dSpinBox->value(), ui->cutZone_dSpinBox->value(), ui->slope_dSpinBox->value());
}
