#include "batterylevelwidget.h"
#include "ui_batterylevelwidget.h"

BatteryLevelWidget::BatteryLevelWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::BatteryLevelWidget)
{
    ui->setupUi(this);
}

BatteryLevelWidget::~BatteryLevelWidget()
{
    delete ui;
}

int BatteryLevelWidget::value() const {
    return m_value;
}

void BatteryLevelWidget::setValue(int value){
    m_value = value;
    if(value < 25){
        ui->soc_progressBar->setStyleSheet("selection-background-color:rgb(255, 127, 127);");
    }
    else if(value < 60){
        ui->soc_progressBar->setStyleSheet("selection-background-color:rgb(255, 255, 127);");
    }
    else{
        ui->soc_progressBar->setStyleSheet("selection-background-color:rgb(0, 255, 127);");
    }
    ui->soc_progressBar->setValue(value);

    ui->soc_lcd->display(value);
}
