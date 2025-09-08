#include "batterywindow.h"
#include "ui_batterywindow.h"
#include <QDebug>

BatteryWindow::BatteryWindow(CanController *can, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::BatteryWindow),
    can(can)
{
    ui->setupUi(this);

    // Cells Table configuration
    ui->cells_table->resizeColumnsToContents();
    ui->cells_table->resizeRowsToContents();
    ui->cells_table->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

    ui->cells_table->setRowCount(4);
    ui->cells_table->setColumnCount(4);

    for(int i = 0; i < ui->cells_table->rowCount(); i++){
        for(int j = 0; j < ui->cells_table->columnCount(); j++){
            QTableWidgetItem *item = new QTableWidgetItem(QString::number(0));
            item->setFlags(item->flags() & ~Qt::ItemIsEditable);
            ui->cells_table->setItem(i, j, item);
        }
    }

    connect(can, &CanController::BMSDataReceived, this, &BatteryWindow::processBMSPacket);
}

BatteryWindow::~BatteryWindow()
{
    delete ui;
}

void BatteryWindow::interceptCheckbox(bool value){}

void BatteryWindow::processBMSPacket(const bms_data_t &data){
    ui->voltage_lcd->display(data.voltage_data.cumulative_voltage_decivolts * 0.1);
    ui->current_lcd->display(data.voltage_data.current_deciamps * 0.1);
    ui->temp1_lcd->display(data.temperature_frame[0].raw_temps[0]);
    ui->temp2_lcd->display(data.temperature_frame[0].raw_temps[1]);
    ui->soc_batteryLevel->setValue(int(data.voltage_data.soc_decipercent * 0.1));
    ui->chargeMosfet_checkBox->setChecked(data.charge_discharge_status.charge_mos);
    ui->dischargeMosfet_checkBox->setChecked(data.charge_discharge_status.discharge_mos);
    ui->chargerStatus_checkBox->setChecked(data.bms_status.charger_status);
    ui->loadStatus_checkBox->setChecked(data.bms_status.load_status);
    ui->capacity_lcd->display(int(data.charge_discharge_status.remaining_capacity_raw));
    ui->numCells_lcd->display(data.bms_status.num_strings);
    ui->numTemps_lcd->display(data.bms_status.num_temp_sensors);

    for (int i = 0; i < 16; i++) {
        ui->cells_table->item(i / 4, i % 4)->setText(QString::number(data.cell_voltage_frame[i / 3].voltages_mv[i % 3]));
    }
}
