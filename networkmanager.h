#ifndef NETWORKMANAGER_H
#define NETWORKMANAGER_H

#include <QNetworkAccessManager>
#include "settingsmanager.h"


class NetworkManager : public QObject
{
    Q_OBJECT
public:
    explicit NetworkManager(SettingsManager *settings, QObject *parent = nullptr);

    void postPropulsionData(const QString &functionName, const double deadZone, const double cutZone, const double slope);

private:
    QNetworkAccessManager *networkManager;
    SettingsManager *settings;
    void postPropulsion(const QByteArray &body);

public slots:
    void processRequest(QNetworkReply *reply);

signals:
    void textResponse(const QString &text);
    void erroOcurred(const QString &error);
};

#endif // NETWORKMANAGER_H
