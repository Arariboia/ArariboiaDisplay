#include "networkmanager.h"
#include <QNetworkReply>
#include <QDebug>

NetworkManager::NetworkManager(SettingsManager *settings, QObject *parent) :
    QObject(parent),
    settings(settings)
{
    networkManager = new QNetworkAccessManager(this);
    connect(networkManager, &QNetworkAccessManager::finished, this, &NetworkManager::processRequest);
}

void NetworkManager::processRequest(QNetworkReply *reply){
    QByteArray data = reply->readAll();
    emit NetworkManager::textResponse(QString::fromUtf8(data));
}

void NetworkManager::postPropulsionFunction(const QString &functionName){

    QByteArray body = QString("function=%1").arg(functionName).toUtf8();
    QNetworkRequest request = QNetworkRequest(QUrl(QString("http://%1/propulsion").arg(settings->getPropulsionIP())));

    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/x-www-form-urlencoded");
    QNetworkReply *reply = networkManager->post(request, body);

    connect(reply, &QNetworkReply::finished, this, [reply]() {
        reply->deleteLater();
    });

    connect(reply, QOverload<QNetworkReply::NetworkError>::of(&QNetworkReply::error),
            this, [reply](){
        qInfo() << reply->errorString();
    });
}
