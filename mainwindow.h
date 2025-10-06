#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "networkmanager.h"
#include "can/cancontroller.h"
#include <QLabel>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);

    static const QString STYLE_DARK_MODE;

    static const QString STYLE_LIGHT_MODE;

    ~MainWindow();

private slots:
    void processTextResponse(const QString &text);
    void networkErrorResponse(const QString &text);

    void on_spinBox_valueChanged(int arg1);

    void startClock();

private:
    Ui::MainWindow *ui;

    NetworkManager *network;
    CanController *can;
    SettingsManager *settings;

    QLabel *clock;
};

#endif // MAINWINDOW_H
