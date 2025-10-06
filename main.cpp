#include "mainwindow.h"

#include <QApplication>
#include <QtDebug>
#include <QScreen>
#include <QDebug>
#include <QStyleFactory>

int main(int argc, char *argv[])
{
    qputenv("QT_IM_MODULE", QByteArray("qtvirtualkeyboard")); // ativa o teclado virtual (é necessário para digitar em displays touch)

    QApplication a(argc, argv);
    QApplication::setStyle(QStyleFactory::create("Fusion"));
    MainWindow w;
    QTime time = QTime::currentTime();
    int currentHour = time.hour();
    if(currentHour >= 18 || currentHour < 7){
        w.setStyleSheet(MainWindow::STYLE_DARK_MODE);
    }else{
        w.setStyleSheet(MainWindow::STYLE_LIGHT_MODE);
    }
    w.show();

    return a.exec();
}
