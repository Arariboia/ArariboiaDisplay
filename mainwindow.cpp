#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "propulsionwindow.h"
#include "settingswindow.h"
#include "batterywindow.h"
#include "mpptwindow.h"
#include <QLabel>
#include <QTime>

const QString MainWindow::STYLE_DARK_MODE = QStringLiteral(R"(
QWidget {
    background-color: #000000;
    color: #FFFFFF;
}

QDoubleSpinBox {
    background-color: #111111;
    color: #FFFFFF;
}

QSpinBox {
    background-color: #111111;
    color: #FFFFFF;
}

QLineEdit {
    background-color: #111111;
    color: #FFFFFF;
}

QProgressBar {
    background-color: #111111;
}

QLCDNumber {
    background-color: #111111;
    color: #FFFFFF;
}

QSpinBox::up-button {
        width: 40px;
}
QSpinBox::down-button {
        width: 40px;
}
QDoubleSpinBox::up-button {
        width: 40px;
}
QDoubleSpinBox::down-button {
        width: 40px;
}

QPushButton:pressed {
    background-color: #222222;
}

QFrame[frameShape="4"], /* HLine */
QFrame[frameShape="5"]  /* VLine */ {
    background-color: #555555;
}
)");

const QString MainWindow::STYLE_LIGHT_MODE = QStringLiteral(R"(
QSpinBox::up-button {
        width: 40px;
    }
QSpinBox::down-button {
        width: 40px;
    }
QDoubleSpinBox::up-button {
        width: 40px;
    }
QDoubleSpinBox::down-button {
        width: 40px;
}
)");

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Deletar tabs padrão
    QWidget *tab1 = ui->tab;
    QWidget *tab2 = ui->tab_2;
    ui->tabWidget->removeTab(ui->tabWidget->indexOf(tab1));
    ui->tabWidget->removeTab(ui->tabWidget->indexOf(tab2));
    delete tab1;
    delete tab2;


    // Create managers and controllers (Dependency Injection)
    can = new CanController(this);
    settings = new SettingsManager(this);
    network = new NetworkManager(settings, this);

    // Adicionar tabs
    QWidget *propulsionWindow = new PropulsionWindow(can, network);
    ui->tabWidget->addTab(propulsionWindow, "Propulsão");

    QWidget *batteryWindow = new BatteryWindow(can, settings);
    ui->tabWidget->addTab(batteryWindow, "Bateria");

    QWidget *mpptWindow = new MpptWindow(can);
    ui->tabWidget->addTab(mpptWindow, "Geração");

    QWidget *settingsWindow = new SettingsWindow(settings, network);
    ui->tabWidget->addTab(settingsWindow, "Configurações");

    connect(network, &NetworkManager::textResponse, this, &MainWindow::processTextResponse);
    connect(network, &NetworkManager::erroOcurred, this, &MainWindow::networkErrorResponse);

    QWidget *container = new QWidget();
    QLayout *statusLayout = new QHBoxLayout(container);
    statusLayout->setSpacing(10);
    clock = new QLabel("00:00");
    clock->setFont(QFont("SansSerif", 11));

    QLabel *teamName = new QLabel("Equipe Arariboia");
    teamName->setFont(QFont("SansSerif", 11));

    QFrame *line = new QFrame();
    line->setFrameShape(QFrame::VLine);

    statusLayout->addWidget(clock);
    statusLayout->addWidget(line);
    statusLayout->addWidget(teamName);
    ui->statusBar->addPermanentWidget(container);
    startClock();
}

void MainWindow::startClock(){
    QTimer *timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, [this]{
        QTime time = QTime::currentTime();
        QString text = time.toString("hh:mm");
        if ((time.second() % 2) == 0)
            text[2] = ' ';
        clock->setText(text);

        static bool isDarkMode = false;

        // Dark mode at 18h
        int currentHour = time.hour();
        if(!isDarkMode && (currentHour >= 18 || currentHour < 7)){
            this->setStyleSheet(STYLE_DARK_MODE);
            isDarkMode = true;
        }
        else if(isDarkMode && (currentHour >= 7 && currentHour < 18)){
            this->setStyleSheet(STYLE_LIGHT_MODE);
            isDarkMode = false;
        }
    });
    timer->start(1000);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::networkErrorResponse(const QString &error){
    ui->statusBar->showMessage("Erro: " + error, 5000);
}

void MainWindow::processTextResponse(const QString &text){
    ui->statusBar->showMessage("Status: " + text, 3000);
}

void MainWindow::on_spinBox_valueChanged(int arg1)
{
    ui->widget->setValue(arg1);
}
