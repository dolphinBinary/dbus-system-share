#include "FileOpenListener.h"
#include <QFileInfo>
#include <QDebug>

FileOpenListener::FileOpenListener(QObject* parent) : QObject(parent)
{
    connect(&m_watcher, &QFileSystemWatcher::fileChanged, this, &FileOpenListener::onFileOpened);
}

void FileOpenListener::addPath(const QString& path)
{
    m_watcher.addPath(path);
}

void FileOpenListener::onFileOpened(const QString& path)
{
    QFileInfo fileInfo(path);
    qDebug() << "File opened:" << path;
    qDebug() << "File format:" << fileInfo.suffix();
    emit fileOpened(path, fileInfo.suffix());
}