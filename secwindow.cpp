#include "secwindow.h"
#include "ui_secwindow.h"

SecWindow::SecWindow(const Book& book, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::SecWindow)
{
    ui->setupUi(this);
    ui->lineEdit->setText(book.link);
    ui->lineEdit_3->setText(book.reviewCount);
    ui->lineEdit_2->setText(book.rate5);
    ui->lineEdit_4->setText(book.rate4);
    ui->lineEdit_5->setText(book.rate3);
    ui->lineEdit_6->setText(book.rate2);
    ui->lineEdit_7->setText(book.rate1);
    ui->lineEdit_8->setText(book.author);
    ui->lineEdit_9->setText(book.title);
}

SecWindow::~SecWindow()
{
    delete ui;
}
