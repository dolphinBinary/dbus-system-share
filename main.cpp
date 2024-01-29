#include <QCoreApplication>
#include "FileOpenListener.h"
#include "FileFormatRegistry.h"
#include "DBusInterface.h"

int main(int argc, char* argv[])
{
    QCoreApplication application(argc, argv);

    // Создание экземпляров классов
    FileOpenListener fileOpenListener;
    FileFormatRegistry fileFormatRegistry;
    DBusInterface dbusInterface;

    // Логика отслеживания директории и обработки файлов
    fileOpenListener.addPath("Documents");
    QObject::connect(&fileOpenListener, &FileOpenListener::fileOpened, [&](const QString& path, const QString& format)
    {
        QStringList applications = dbusInterface.getRegisteredApplications(format);
        if (applications.isEmpty())
        {
            // Вывод диалогового окна для выбора приложений
            qDebug() << "Выберите приложение для открытия файла" << path;
            // Регистрация связки формат - приложение
            fileFormatRegistry.registerApplication("Приложение", QStringList() << format);
        }
        else
        {
            // Запуск приложения
            QString appName = applications.first();
            DBusInterface::openFileWithApplication(appName, path);
        }
    });

    return QCoreApplication::exec();
}