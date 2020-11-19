#ifndef CREATE_NOTE_H
#define CREATE_NOTE_H

#include <QWidget>

namespace Ui {
class create_note;
}

class create_note : public QWidget
{
    Q_OBJECT

public:
    explicit create_note(QWidget *parent = nullptr);
    ~create_note();

private slots:
    void on_create_clicked();

private:
    Ui::create_note *ui;
};

#endif // CREATE_NOTE_H
