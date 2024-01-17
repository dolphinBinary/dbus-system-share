#include "DBusInterface.h"

DBusInterface::DBusInterface(QObject* parent)
    : QObject(parent), m_interface("org.freedesktop.DBus", "/", "org.freedesktop.DBus", QDBusConnection::sessionBus())
{
}

QStringList DBusInterface::getRegisteredApplications(const QString& fileFormat)
{
    QDBusMessage message = m_interface.call("GetRegisteredApplications", fileFormat);
    return message.arguments().first().toStringList();
}

void DBusInterface::openFileWithApplication(const QString& appName, const QString& filePath)
{
    QDBusInterface appInterface(appName, "/", "", QDBusConnection::sessionBus());
    appInterface.call("OpenFile", filePath);
}