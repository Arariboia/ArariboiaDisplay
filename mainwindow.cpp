#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "mavlink/arariboat/mavlink.h"
#include <QCanBus>
#include <QDebug>
#include <QProcess>
#include <math.h>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Impede o clique
    ui->cb_charge->setAttribute(Qt::WA_TransparentForMouseEvents);
    ui->cb_discharge->setAttribute(Qt::WA_TransparentForMouseEvents);

    // --- Começar configuração CAN ---
    isCanPLuginAvailable = QCanBus::instance()->plugins().contains(QStringLiteral("socketcan"));

    if(!isCanPLuginAvailable){
        qDebug() << "No CAN plugin available.";
        return;
    }

    QString errorString;
    canDevice = QCanBus::instance()->createDevice(QStringLiteral("socketcan"), QStringLiteral("can0"), &errorString);
    if (!canDevice)
    {
        // Error handling goes here
        qDebug() << errorString;
    }
    else
    {
        qInfo() << "CAN CONECTADO";
        canDevice->connectDevice();
        connect(canDevice, &QCanBusDevice::framesReceived, this, &MainWindow::processReceivedFrames);
        connect(canDevice, &QCanBusDevice::errorOccurred, this, &MainWindow::processErrors);
        connect(&bmsCanManager, &BMSCANManager::DataReceived, this, &MainWindow::ProcessBMSData);
        connect(&motorCanManager, &MotorCANManager::DataLeftReceived, this, &MainWindow::ProcessMotorLeftData);
        connect(&motorCanManager, &MotorCANManager::DataRightReceived, this, &MainWindow::ProcessMotorRightData);
    }

//    // Popular combo box
//    QList<QCanBusDeviceInfo> devices = QCanBus::instance()->availableDevices(pluginName);
//    for(int i = 0; i < devices.length(); i++){
//        ui->cbxCanDevices->addItem(devices[i].name());
//    }
//    ui->cbxCanDevices->setCurrentIndex(0);

//    canDevice = QCanBus::instance()->createDevice(pluginName, ui->cbxCanDevices->currentText());
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::processErrors(QCanBusDevice::CanBusError error) const
{
    switch (error) {
    case QCanBusDevice::ReadError:
    case QCanBusDevice::WriteError:
    case QCanBusDevice::ConnectionError:
    case QCanBusDevice::ConfigurationError:
    case QCanBusDevice::UnknownError:
        qDebug() << canDevice->errorString();
        break;
    default:
        break;
    }
}

//void MainWindow::on_btnConnect_clicked()
//{
//    canDevice->connectDevice();
//    connect(canDevice, &QCanBusDevice::framesReceived, this, &MainWindow::processReceivedFrames);
//}

//void MainWindow::on_btnDisconnect_clicked()
//{
//    canDevice->disconnectDevice();
//}

void MainWindow::processReceivedFrames(){
    if(!canDevice) return;

    while(canDevice->framesAvailable() > 0){
        const QCanBusFrame frame = canDevice->readFrame();
        if(bmsCanManager.handle_can_frame(frame)) continue;
//        if(motorCanManager.handle_can_frame(frame)) continue;

        if (frame.frameType() == QCanBusFrame::ErrorFrame){
            qDebug() << canDevice->interpretErrorFrame(frame);
            return;
        }

        if(frame.frameId() == 0xABC){
            mavlink_status_t status;
            mavlink_message_t msg;
            uint8_t chan = MAVLINK_COMM_2;
            for(int i = 0; i < frame.payload().size(); i++){
                if(mavlink_parse_char(chan, frame.payload().at(i), &msg, &status)){
                    if(msg.msgid == MAVLINK_MSG_ID_MPPT){
                        mavlink_mppt_t mppt;
                        mavlink_msg_mppt_decode(&msg, &mppt);
                        ProcessMPPTData(mppt);
                    }
                    else if(msg.msgid == MAVLINK_MSG_ID_INSTRUMENTATION){
//                        mavlink_instrumentation_t inst;
//                        mavlink_msg_instrumentation_decode(&msg, &inst);
//                        ui->lcd_temp_mppt->display(inst.mppt_current / 100.0);
                    }
                }
            }
        }
    }
}

void MainWindow::ProcessBMSData(const bms_data_t &data){
    ui->lcdNum_bat_voltage->display(data.voltage_data.cumulative_voltage_decivolts / 10.0);
    ui->lcdNum_bat_current->display(data.voltage_data.current_deciamps / 10.0);
    ui->lcdNum_soc->display(data.voltage_data.soc_decipercent / 10.0);
    ui->cb_discharge->setChecked(data.charge_discharge_status.discharge_mos);
    ui->cb_charge->setChecked(data.charge_discharge_status.charge_mos);

    float estimative = -1 * (((data.voltage_data.soc_decipercent / 1000.0f) * 40.0f) / (data.voltage_data.current_deciamps / 10.0f));
    int hour = static_cast<int>(floor(estimative));
    int min = static_cast<int>(floor((estimative - hour) * 60));
    ui->lcd_estimative_h->display(hour);
    ui->lcd_estimative_m ->display(min);

}

void MainWindow::ProcessMotorLeftData(const motor_data_t &data){
//    qInfo() << "Motor BB" << data.state_data.motor_temp_C;
//    qInfo() << "Cont BB" << data.state_data.controller_temp_C;
//    ui->lcdNum_rpm_left->display(data.electrical_data.rpm * -1);
//    ui->lcd_temp_m_1->display(data.state_data.motor_temp_C);
}

void MainWindow::ProcessMotorRightData(const motor_data_t &data){
//    qInfo() << "Motor BR" << data.state_data.motor_temp_C;
//    qInfo() << "Cont BR" << data.state_data.controller_temp_C;
//    ui->lcdNum_rpm_right->display(data.electrical_data.rpm * -1);
//    ui->lcd_temp_m_2->display(data.state_data.motor_temp_C);
}

void MainWindow::ProcessMPPTData(const mavlink_mppt_t &data){
    double pv_voltage = data.pv_voltage / 100.0;
    double pv_current = data.pv_current / 100.0;
    double mppt_bat_curr = data.battery_current / 100.0;
    ui->lcd_panel_volt->display(pv_voltage);
    ui->lcd_panel_curr->display(pv_current);
    ui->lcd_curr_mppt->display((pv_voltage * pv_current * 0.98) / mppt_bat_curr);
}

void MainWindow::on_pushButton_clicked()
{
    qInfo() << "REINICIANDO...";
    QProcess::startDetached("/sbin/reboot");
}
