#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "networkmanager.h"
#include "can/cancontroller.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void processTextResponse(const QString text);

private:
    Ui::MainWindow *ui;

    NetworkManager *network;
    CanController *can;
    SettingsManager *settings;
};

#endif // MAINWINDOW_H
