#include "applicationdata.h"
#include <QString>
#include <QApplication>
#include <QDir>
#include <QDebug>

QString ApplicationData::CreateApplicationFolder(QString nameFolder){
    //set directory saving
    if(!QDir(nameFolder).exists()){
    QDir().mkdir(nameFolder);
    }
    QString pathToCreateFolder = QApplication::applicationDirPath() + "/"+nameFolder;
    qDebug() << pathToCreateFolder;
    return pathToCreateFolder;
}

ApplicationData::ApplicationData()
{

}
