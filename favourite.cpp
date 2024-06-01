#include "favourite.h"
#include "ui_favourite.h"
#include "addingfavopuritebook.h"
Favourite::Favourite(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Favourite)
{
    ui->setupUi(this);
}

Favourite::~Favourite()
{
    delete ui;
}


void Favourite::on_pushButton_clicked()
{
    qDebug() << "Work";
}


void Favourite::on_pushButton54_clicked()
{
    addingfavopuritebook dialog(this);
    dialog.exec();
}

