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

QStringList FileFormatRegistry::getApplicationsForFormat(const QString& fileFormat)
{
    QStringList apps;
    for (auto it = m_registry.begin(); it != m_registry.end(); ++it)
    {
        if (it.value().contains(fileFormat))
        {
            apps.append(it.key());
        }
    }
    return apps;
}