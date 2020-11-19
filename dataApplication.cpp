#include "mainwindow.h"
#include <QString>
#include <QDir>
#include <QApplication>
#include <QDebug>
class dataApplication{
public:
    static QString pathToSaveNote;
    static QString pathToConfigFiles;

public:
     void createApplicationFolder(){
         /*
         if the folder for saving notes does not exist, then you need to create
         */
         pathToSaveNote = createApplicationDir(pathToSaveNote,"notes");

         /*
         if the folder for config files does not exist, then you need to create
         */
         pathToConfigFiles = createApplicationDir(pathToConfigFiles,"config");
    }

    //create folder for application
    QString  createApplicationDir(QString pathToCreateFolder,QString nameFolder){
        //set directory saving
       if(!QDir(nameFolder).exists()){
           QDir().mkdir(nameFolder);
       }
       pathToCreateFolder = QApplication::applicationDirPath() + "/"+nameFolder;
       qDebug()<<pathToCreateFolder;
       return pathToCreateFolder;
    }
};
