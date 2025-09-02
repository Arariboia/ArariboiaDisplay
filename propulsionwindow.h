#ifndef PROPULSIONWINDOW_H
#define PROPULSIONWINDOW_H

#include <QWidget>
#include "can/cancontroller.h"
#include "networkmanager.h"

namespace Ui {
class PropulsionWindow;
}

class PropulsionWindow : public QWidget
{
    Q_OBJECT

public:
    explicit PropulsionWindow(CanController *can, NetworkManager *network, QWidget *parent = nullptr);
    ~PropulsionWindow();

private slots:
    void processPropulsionPacket(const motor_data_t &data);

    void on_graphL_btn_clicked();

    void on_graphR_btn_clicked();

    void on_sendGraph_btn_clicked();

    void textResponse(const QString text);

private:
    Ui::PropulsionWindow *ui;
    CanController *can;
    NetworkManager *network;

    QString graphImageArray[3] = {"linear(x)", "exp(x)", "log(x)"};
    int graphImageArraySize = 3;
    int graphIndex = 0;
};

#endif // PROPULSIONWINDOW_H
