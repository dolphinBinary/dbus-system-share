#include "DBusInterface.h"

DBusInterface::DBusInterface(QObject* parent)
        : QObject(parent),
          m_interface("org.example.SystemShare", "/", "org.example.SystemShare", QDBusConnection::sessionBus())
{
    if (!m_interface.isValid())
    {
        qWarning() << "Could not connect to DBus. Please check your DBus settings.";
    }
}

QStringList DBusInterface::getRegisteredApplications(const QString& fileFormat)
{
    QDBusMessage message = m_interface.call("GetRegisteredApplications", fileFormat);
    if (message.type() == QDBusMessage::ErrorMessage)
    {
        qWarning() << "Error calling GetRegisteredApplications:" << message.errorMessage();
        return QStringList();
    }
    return message.arguments().first().toStringList();
}

void DBusInterface::openFileWithApplication(const QString& appName, const QString& filePath)
{
    QDBusInterface appInterface(appName, "/", "", QDBusConnection::sessionBus());
    QDBusMessage message = appInterface.call("OpenFile", filePath);
    if (message.type() == QDBusMessage::ErrorMessage)
    {
        qWarning() << "Error calling OpenFile:" << message.errorMessage();
    }
}