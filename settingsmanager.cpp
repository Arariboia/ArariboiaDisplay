#include "settingsmanager.h"
#include <QCoreApplication>
#include <QSettings>

const QString SettingsManager::KeyNames::propulsionIP = QStringLiteral("propulsion/ip");

SettingsManager::SettingsManager(QObject *parent) : QObject(parent)
{
    QCoreApplication::setOrganizationName("Equipe Arariboia");
    QCoreApplication::setApplicationName("Display Cockpit");
}

QString SettingsManager::getPropulsionIP(){
    QSettings settings;
    return settings.value(SettingsManager::KeyNames::propulsionIP).toString();
}

void SettingsManager::setPropulsionIP(const QString &ip){
    QSettings settings;
    settings.setValue(SettingsManager::KeyNames::propulsionIP, ip);
}
