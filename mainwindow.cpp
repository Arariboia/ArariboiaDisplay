#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "propulsionwindow.h"
#include "settingswindow.h"
#include "batterywindow.h"
#include "mpptwindow.h"
#include <QLabel>
#include <QTime>

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

        // Dark mode at 18h

        if(time.hour() >= 18){
            this->setStyleSheet(STYLE_DARK_MODE);
        }
        else{
            this->setStyleSheet(STYLE_LIGHT_MODE);
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
