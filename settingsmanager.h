#ifndef SETTINGSMANAGER_H
#define SETTINGSMANAGER_H

#include <QObject>

class SettingsManager : public QObject
{
    Q_OBJECT
public:
    explicit SettingsManager(QObject *parent = nullptr);

    class KeyNames {
    public:
        static const QString propulsionIP;
    };

    QString getPropulsionIP();
    void setPropulsionIP(const QString &ip);

signals:

public slots:
};

#endif // SETTINGSMANAGER_H
