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
    if(reply->error() == QNetworkReply::NoError){
        qInfo() << "GERAL: " << reply->attribute(QNetworkRequest::HttpReasonPhraseAttribute);
        emit NetworkManager::textResponse(reply->attribute(QNetworkRequest::HttpReasonPhraseAttribute).toString());
    }
}

void NetworkManager::postPropulsion(const QByteArray &body){
    QNetworkRequest request = QNetworkRequest(QUrl(QString("http://%1/propulsion").arg(settings->getPropulsionIP())));

    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/x-www-form-urlencoded");
    QNetworkReply *reply = networkManager->post(request, body);

    connect(reply, &QNetworkReply::finished, this, [reply]() {
        reply->deleteLater();
    });

    connect(reply, QOverload<QNetworkReply::NetworkError>::of(&QNetworkReply::error),
            this, [reply, this](){
        qInfo() << "REPLY: " << reply->errorString();
        emit NetworkManager::erroOcurred(reply->errorString());
        reply->deleteLater();
    });
}

void NetworkManager::postPropulsionData(const QString &functionName = "", const double deadZone = -1, const double cutZone = -1, const double slope = -1){

    QByteArray body = QString("function=%1&deadzone=%2&cutzone=%3&slope=%4").arg(functionName).arg(deadZone).arg(cutZone).arg(slope).toUtf8();
    postPropulsion(body);
}



