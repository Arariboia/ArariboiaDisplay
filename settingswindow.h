#ifndef SETTINGSWINDOW_H
#define SETTINGSWINDOW_H

#include <QWidget>
#include "settingsmanager.h"

namespace Ui {
class SettingsWindow;
}

class SettingsWindow : public QWidget
{
    Q_OBJECT

public:
    explicit SettingsWindow(SettingsManager *settings, QWidget *parent = nullptr);
    ~SettingsWindow();

private slots:
    void on_propulsionIp_lineEdit_editingFinished();

private:
    Ui::SettingsWindow *ui;
    SettingsManager *settings;
};

#endif // SETTINGSWINDOW_H
