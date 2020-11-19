#include "dataapp.h"
#include <iostream>
#include <QString>
#include <QDebug>
#include <QApplication>
#include <QDir>

dataApp::dataApp()
{
    class datas{
        public:
             QString pathToSaveNote;
             QString pathToConfigFiles;

       datas(){
           setApplicationFolder();
       }
        public:
        void setApplicationFolder(){
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
        QString createApplicationDir(QString pathToCreateFolder,QString nameFolder){
        //set directory saving
        if(!QDir(nameFolder).exists()){
        QDir().mkdir(nameFolder);
        }
        pathToCreateFolder = QApplication::applicationDirPath() + "/"+nameFolder;
        qDebug() << pathToCreateFolder;
        return pathToCreateFolder;
             }
    };

}
