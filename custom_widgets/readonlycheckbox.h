#ifndef READONLYCHECKBOX_H
#define READONLYCHECKBOX_H

#include <QCheckBox>
#include <QMouseEvent>

class ReadOnlyCheckBox : public QCheckBox {
    Q_OBJECT
public:
    explicit ReadOnlyCheckBox(QWidget *parent = nullptr)
        : QCheckBox(parent) {}

protected:
    void mousePressEvent(QMouseEvent *) override {
        // ignora clique do usuário
    }

    void mouseReleaseEvent(QMouseEvent *) override {
        // ignora clique do usuário
    }
};

#endif // READONLYCHECKBOX_H
