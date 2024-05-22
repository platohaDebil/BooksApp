#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "secdialogue.h"
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow),
      // list(new QStringListModel),
      // filmList(new Netflix),
    //  proxy(new ProxyModel),
      tableModel(new tablemodel) // dynamic memory
{
    ui->setupUi(this);

    // list->setStringList(filmList->stringList);
    // ui->listView->setModel(list);
     ui->tableView->setModel(tableModel);
     for (int i: {0,1,2,3,4,5,6,9,13,14,15,16,17,18,19,20,21,22,23})
         ui->tableView->hideColumn(i);
    //proxy->setSourceModel(tableModel);
    //ui->tableView->setModel(proxy);
    // ui->comboBox->addItem("all");

    //  for (const QString &i: tableModel->getGenres())
    //      ui->comboBox->addItem(i);
}

MainWindow::~MainWindow()
{
    delete ui;
    // delete list;
    // delete filmList;
    delete tableModel;
    //delete proxy;
}

// void MainWindow::on_pushButton_clicked()
// {
//     ui->searchLineEdit->setText("Pushed");
// }


// void MainWindow::on_listView_clicked(const QModelIndex &index)
// {
//     QList <QString> row = filmList->list[index.row()];
//     ui->countryLineEdit->setText(row[2]);
//     ui->countryLineEdit->setEnabled(false);
//     ui->dateLineEdit->setText(row[4]);
//     ui->dateLineEdit->setEnabled(false);
//     ui->ratingLineEdit->setText(row[5]);
//     ui->ratingLineEdit->setEnabled(false);
// }


// void MainWindow::on_comboBox_currentIndexChanged(int index)
// {

// }


// void MainWindow::on_comboBox_currentTextChanged(const QString &arg1)
// {
//     proxy->setGenre(arg1);

// }


void MainWindow::on_pushButton_clicked()
{
    SecDialogue sec;
    if (sec.exec())
    {
        // for (QString field: sec.getFields())
        Book book =  sec.getFields();
            qDebug() << book.title << " " << book.author << " " << book.year << " " << book.lang << " " << book.rate;
     tableModel->addBook(book);

    }
    // sec.setModal(true);



}

