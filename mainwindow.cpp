#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QDebug"
#include <QString>
#include <applicationdata.h>
#include <workwithfile.h>
#include <QtGui>
#include <create_note.h>
#include <QMessageBox>

ApplicationData _data;
workWithFile _work;

/*
opening note
*/

QString activeNote;

/*
path where saving notes
*/
QString pathToSaveNote;


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    /*
    set path to saving folder
    if folder don't exist than this folder need create
    */
    pathToSaveNote = _data.CreateApplicationFolder("notes");
    /*
        default
    */
    activeNote = "note.txt";

    //folder for saving files
    QDir dirSavingNotes(pathToSaveNote);
    //filter for fing files (.txt)
    QStringList filters;
    filters <<"*.txt";
    //apply filters
    dirSavingNotes.setNameFilters(filters);
    QFileInfoList list = dirSavingNotes.entryInfoList(filters,QDir::Files);

     ui->notesBox->addItem(activeNote);
    //thing to switch between notes
    for (int i = 0;i<list.length();i++) {
        if(list[i].fileName() != "note.txt")
            ui->notesBox->addItem(list[i].fileName());
    }
    ui->Entry_Field->setText(_work.getTextInFile(activeNote.toStdString(),pathToSaveNote));


    QApplication::alert(this,1000);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_SaveButton_clicked()
{
     QString textInNote = ui->Entry_Field->toPlainText();
     _work.writeInFIle(textInNote,pathToSaveNote,activeNote);
     QMessageBox::information(0,"information","note has just saved");
}

void MainWindow::on_notesBox_activated(const QString &arg1)
{
    activeNote = arg1;
    ui->Entry_Field->setText(_work.getTextInFile(arg1.toStdString(),pathToSaveNote));
}

void MainWindow::on_crateNote_clicked()
{
    create_note *createNote = new create_note();
    createNote->show();
    this->close();
}
