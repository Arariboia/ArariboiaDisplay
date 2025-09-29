#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "propulsionwindow.h"
#include "settingswindow.h"
#include "batterywindow.h"
#include "mpptwindow.h"
#include <QLabel>

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


    ui->statusBar->addPermanentWidget(new QLabel("Equipe Arariboia"));
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
