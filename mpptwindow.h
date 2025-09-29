#ifndef MPPTWINDOW_H
#define MPPTWINDOW_H

#include <QWidget>
#include "can/cancontroller.h"

namespace Ui {
class MpptWindow;
}

class MpptWindow : public QWidget
{
    Q_OBJECT

public:
    explicit MpptWindow(CanController *can, QWidget *parent = nullptr);
    ~MpptWindow();

private:
    Ui::MpptWindow *ui;
    CanController *can;

public slots:
    void processMpptPacket(const mavlink_mppt_t &data);
    void processMpptStringPacket(const mavlink_mppt_strings_t &data);
};

#endif // MPPTWINDOW_H
