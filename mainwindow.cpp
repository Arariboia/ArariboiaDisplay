#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "propulsionwindow.h"
#include "settingswindow.h"

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

    QWidget *settingsWindow = new SettingsWindow(settings, this);
    ui->tabWidget->addTab(settingsWindow, "Configurações");

    connect(network, &NetworkManager::textResponse, this, &MainWindow::processTextResponse);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::processTextResponse(const QString text){
}
