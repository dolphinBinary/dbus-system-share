#include <QObject>
#include <QDebug>
#include <QDBusInterface>
#include <QDBusConnection>

class DBusInterface : public QObject
{
Q_OBJECT

public:
    explicit DBusInterface(QObject* parent = nullptr);

    QStringList getRegisteredApplications(const QString& fileFormat);

    static void openFileWithApplication(const QString& appName, const QString& filePath);

private:
    QDBusInterface m_interface;
};