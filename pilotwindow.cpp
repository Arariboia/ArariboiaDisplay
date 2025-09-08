#include "pilotwindow.h"
#include "ui_pilotwindow.h"

PilotWindow::PilotWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::PilotWindow)
{
    ui->setupUi(this);
}

PilotWindow::~PilotWindow()
{
    delete ui;
}
