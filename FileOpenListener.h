#include <QObject>
#include <QFileSystemWatcher>

class FileOpenListener : public QObject
{
Q_OBJECT

public:
    explicit FileOpenListener(QObject* parent = nullptr);

    void addPath(const QString& path);

signals:
    void fileOpened(const QString& path, const QString& format);

private slots:
    void onFileOpened(const QString& path);

private:
    QFileSystemWatcher m_watcher;
};