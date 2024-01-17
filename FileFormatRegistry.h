#include <QObject>
#include <QMap>
#include <QDBusConnection>
#include <QDBusAbstractAdaptor>

class FileFormatRegistry : public QObject
{
 Q_OBJECT
    Q_CLASSINFO("D-Bus Interface", "org.example.FileFormatRegistry")

 public:
    explicit FileFormatRegistry(QObject* parent = nullptr);

 public slots:
    void registerApplication(const QString& appName, const QStringList& fileFormats);
    QStringList getApplicationsForFormat(const QString& fileFormat);

 private:
    QMap<QString, QStringList> m_registry;
};