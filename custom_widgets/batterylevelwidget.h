#ifndef BATTERYLEVELWIDGET_H
#define BATTERYLEVELWIDGET_H

#include <QWidget>

namespace Ui {
class BatteryLevelWidget;
}

class BatteryLevelWidget : public QWidget
{
    Q_OBJECT
    Q_PROPERTY(int value READ value WRITE setValue NOTIFY valueChanged)

public:
    explicit BatteryLevelWidget(QWidget *parent = nullptr);
    ~BatteryLevelWidget();

    int value() const;
    void setValue(int v);

private:
    Ui::BatteryLevelWidget *ui;
    int m_value;

signals:
    void valueChanged(int newValue);

};

#endif // BATTERYLEVELWIDGET_H
