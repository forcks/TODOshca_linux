#include "workwithfile.h"
#include <QString>
#include <fstream>
#include <QStringList>

//read text in file
QString workWithFile::getTextInFile(std::string fileName,QString pathToSaveNote){
    //show note
    std::string line;
    QString textInNote = "";
        std::ifstream in(pathToSaveNote.toStdString()+"/"+fileName);
        if (in.is_open())
        {
            while (getline(in, line))
            {
                textInNote += QString::fromStdString(line+"\n");
            }
        }
        in.close();
        return textInNote;
}

void workWithFile::writeInFIle(QString textSaving,QString pathFolderToSave,QString pathFileToSave){
    QStringList strList=textSaving.split('\n');

    std::ofstream out;
        out.open(pathFolderToSave.toStdString()+"/"+pathFileToSave.toStdString());
        if (out.is_open())
        {
            for (int i =0;i<strList.length();i++) {
                out <<strList[i].toStdString()<< std::endl;
            }
        }
}

workWithFile::workWithFile()
{

}
