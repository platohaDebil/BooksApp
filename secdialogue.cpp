#include "secdialogue.h"
#include "ui_secdialogue.h"

SecDialogue::SecDialogue(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SecDialogue)
{
    ui->setupUi(this);
}

SecDialogue::~SecDialogue()
{
    delete ui;
}

Book SecDialogue::getFields() const
{

    Book book;
    book.title = ui->lineEdit->text();
    book.author = ui->lineEdit_2->text();
    book.year = ui->lineEdit_3->text();
    book.lang = ui->lineEdit_4->text();
    book.rate = ui->lineEdit_5->text();
    return book;
}

