#ifndef WORKWITHFILE_H
#define WORKWITHFILE_H

#include <QString>

class workWithFile
{
public:
    workWithFile();

    QString getTextInFile(std::string fileName,QString pathToSaveNote);
    void writeInFIle(QString textSaving,QString pathDirToSave,QString pathFileToSave);
};

#endif // WORKWITHFILE_H
