#include "settingswindow.h"
#include "ui_settingswindow.h"
#include <QDebug>

SettingsWindow::SettingsWindow(SettingsManager *settings, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SettingsWindow),
    settings(settings)
{
    ui->setupUi(this);

    ui->propulsionIp_lineEdit->setText(settings->getPropulsionIP());
}

SettingsWindow::~SettingsWindow()
{
    delete ui;
}

void SettingsWindow::on_propulsionIp_lineEdit_editingFinished()
{
    settings->setPropulsionIP(ui->propulsionIp_lineEdit->text());
}
