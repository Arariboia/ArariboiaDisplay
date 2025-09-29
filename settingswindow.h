#ifndef SETTINGSWINDOW_H
#define SETTINGSWINDOW_H

#include <QWidget>
#include "settingsmanager.h"
#include "networkmanager.h"

namespace Ui {
class SettingsWindow;
}

class SettingsWindow : public QWidget
{
    Q_OBJECT

public:
    explicit SettingsWindow(SettingsManager *settings, NetworkManager *network, QWidget *parent = nullptr);
    ~SettingsWindow();

private slots:
    void on_propulsionIp_lineEdit_editingFinished();
    void on_bmsPollDelay_spinBox_editingFinished();

    void on_pushButton_clicked();

private:
    Ui::SettingsWindow *ui;
    SettingsManager *settings;
    NetworkManager *network;
};

#endif // SETTINGSWINDOW_H
