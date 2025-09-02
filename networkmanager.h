#ifndef NETWORKMANAGER_H
#define NETWORKMANAGER_H

#include <QNetworkAccessManager>
#include "settingsmanager.h"


class NetworkManager : public QObject
{
    Q_OBJECT
public:
    explicit NetworkManager(SettingsManager *settings, QObject *parent = nullptr);

    void postPropulsionFunction(const QString &functionName);

private:
    QNetworkAccessManager *networkManager;
    SettingsManager *settings;

public slots:
    void processRequest(QNetworkReply *reply);

signals:
    void textResponse(const QString text);

};

#endif // NETWORKMANAGER_H
