#ifndef PILOTWINDOW_H
#define PILOTWINDOW_H

#include <QWidget>

namespace Ui {
class PilotWindow;
}

class PilotWindow : public QWidget
{
    Q_OBJECT

public:
    explicit PilotWindow(QWidget *parent = nullptr);
    ~PilotWindow();

private:
    Ui::PilotWindow *ui;
};

#endif // PILOTWINDOW_H
