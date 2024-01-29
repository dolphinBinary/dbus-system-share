#include "FileFormatRegistry.h"

FileFormatRegistry::FileFormatRegistry(QObject* parent)
        : QObject(parent)
{
    QDBusConnection::sessionBus().registerObject("/", this);
}

void FileFormatRegistry::registerApplication(const QString& appName, const QStringList& fileFormats)
{
    m_registry[appName] = fileFormats;
}