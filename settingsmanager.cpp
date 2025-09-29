#include "settingsmanager.h"
#include <QCoreApplication>
#include <QSettings>
#include <QDebug>

const QString SettingsManager::KeyNames::propulsionIP = QStringLiteral("propulsion/ip");
const QString SettingsManager::KeyNames::propulsionDeadZone = QStringLiteral("propulsion/deadzone");
const QString SettingsManager::KeyNames::propulsionCutZone = QStringLiteral("propulsion/cutzone");
const QString SettingsManager::KeyNames::propulsionFunction = QStringLiteral("propulsion/function");
const QString SettingsManager::KeyNames::propulsionSlope = QStringLiteral("propulsion/slope");

const QString SettingsManager::KeyNames::bmsPollDelay = QStringLiteral("bms/pollDelay");

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

double SettingsManager::getPropulsionDeadZone(){
    QSettings settings;
    return settings.value(SettingsManager::KeyNames::propulsionDeadZone).toDouble();
}

void SettingsManager::setPropulsionDeadZone(const double deadZone){
    QSettings settings;
    settings.setValue(SettingsManager::KeyNames::propulsionDeadZone, deadZone);
}

double SettingsManager::getPropulsionCutZone(){
    QSettings settings;
    return settings.value(SettingsManager::KeyNames::propulsionCutZone).toDouble();
}

void SettingsManager::setPropulsionCutZone(const double cutZone){
    QSettings settings;
    settings.setValue(SettingsManager::KeyNames::propulsionCutZone, cutZone);
}

double SettingsManager::getPropulsionSlope(){
    QSettings settings;
    return settings.value(SettingsManager::KeyNames::propulsionSlope).toDouble();
}

void SettingsManager::setPropulsionSlope(const double slope){
    QSettings settings;
    settings.setValue(SettingsManager::KeyNames::propulsionSlope, slope);
}

QString SettingsManager::getPropulsionFunction(){
    QSettings settings;
    return settings.value(SettingsManager::KeyNames::propulsionFunction).toString();
}

void SettingsManager::setPropulsionFunction(const QString &func){
    QSettings settings;
    settings.setValue(SettingsManager::KeyNames::propulsionFunction, func);
}

int SettingsManager::getBMSPollDelay(){
    QSettings settings;
    return settings.value(SettingsManager::KeyNames::bmsPollDelay).toInt();
}

void SettingsManager::setBMSPollDelay(const int delay_ms){
    QSettings settings;
    qInfo() << "Editando com valor: " << delay_ms;
    emit onBMSDelayChanged(delay_ms);
    return settings.setValue(SettingsManager::KeyNames::bmsPollDelay, delay_ms);
}
