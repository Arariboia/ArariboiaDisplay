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
        static const QString propulsionDeadZone;
        static const QString propulsionCutZone;
        static const QString propulsionSlope;
        static const QString propulsionFunction;
        static const QString bmsPollDelay;
    };

    QString getPropulsionIP();
    void setPropulsionIP(const QString &ip);

    int getBMSPollDelay();
    void setBMSPollDelay(const int delay_ms);

    QString getPropulsionFunction();
    void setPropulsionFunction(const QString &func);

    double getPropulsionDeadZone();
    void setPropulsionDeadZone(const double deadZone);

    double getPropulsionCutZone();
    void setPropulsionCutZone(const double cutZone);

    double getPropulsionSlope();
    void setPropulsionSlope(const double slope);


signals:
    void onBMSDelayChanged(const int delay_ms);

public slots:
};

#endif // SETTINGSMANAGER_H
