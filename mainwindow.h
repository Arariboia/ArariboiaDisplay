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

    const QString STYLE_DARK_MODE = QStringLiteral(R"(
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

    QFrame[frameShape="4"], /* HLine */
    QFrame[frameShape="5"]  /* VLine */ {
        background-color: #555555;
    }
    )");

    const QString STYLE_LIGHT_MODE = QStringLiteral("");
};

#endif // MAINWINDOW_H
