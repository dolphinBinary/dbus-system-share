#include <QObject>
#include <QDBusAbstractAdaptor>

class MyDBusInterface : public QDBusAbstractAdaptor
{
    Q_OBJECT
    Q_CLASSINFO("D-Bus Interface", "org.example.MyDBusInterface")

public:
    explicit MyDBusInterface(QObject* parent = nullptr);
    Q_INVOKABLE QStringList getRegisteredApplications(const QString& fileFormat);
    Q_INVOKABLE void openFileWithApplication(const QString& appName, const QString& filePath);
};