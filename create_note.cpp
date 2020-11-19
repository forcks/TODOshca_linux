#include "create_note.h"
#include "ui_create_note.h"
#include "workwithfile.h"
#include "applicationdata.h"
#include <QString>
#include <QtGui>
#include <mainwindow.h>
#include <QMessageBox>

create_note::create_note(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::create_note)
{
    ui->setupUi(this);

}

create_note::~create_note()
{
    delete ui;
}

void create_note::on_create_clicked()
{
    ApplicationData _data;
    workWithFile _workWithFile;
    QString pathToNoteFolder;

    pathToNoteFolder = _data.CreateApplicationFolder("notes");

    QString nameFile = ui->NameNoteEdit->toPlainText();
    _workWithFile.writeInFIle(nullptr,pathToNoteFolder,nameFile+".txt");

    MainWindow *mainwindow = new MainWindow();

    mainwindow->show();

    QMessageBox::information(0,"information","note has just created");
    this->close();
}
