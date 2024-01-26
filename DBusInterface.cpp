#include "DBusInterface.h"

MyDBusInterface::MyDBusInterface(QObject *parent)
        : QDBusAbstractAdaptor(parent) {
    QDBusConnection::sessionBus().registerObject("/", this, QDBusConnection::ExportAllInvokables);
}

QStringList DBusInterface::getRegisteredApplications(const QString &fileFormat) {
    QDBusMessage message = m_interface.call("GetRegisteredApplications", fileFormat);
    return message.arguments().first().toStringList();
}

void DBusInterface::openFileWithApplication(const QString &appName, const QString &filePath) {
    QDBusInterface appInterface(appName, "/", "", QDBusConnection::sessionBus());
    appInterface.call("OpenFile", filePath);
}