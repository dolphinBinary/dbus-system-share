#include <QCoreApplication>
#include <QInputDialog>
#include "DBusInterface.h"
#include "FileOpenListener.h"
#include "FileFormatRegistry.h"

int main(int argc, char* argv[])
{
    QCoreApplication a(argc, argv);

    MyDBusInterface myDBusInterface;
    FileOpenListener fileOpenListener;
    FileFormatRegistry fileFormatRegistry;

    QObject::connect(&fileOpenListener, &FileOpenListener::fileOpened, [&](const QString& path, const QString& format)
    {
        QStringList apps = myDBusInterface.getRegisteredApplications(format);
        bool ok;
        QString appName = QInputDialog::getItem(nullptr, "Select Application", "Select an application to open the file:", apps, 0, false, &ok);
        if (ok && !appName.isEmpty())
        {
            myDBusInterface.openFileWithApplication(appName, path);
        }
    });

    return QCoreApplication::exec();
}