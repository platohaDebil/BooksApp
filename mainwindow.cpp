#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "secdialogue.h"
#include <QDebug>
#include <QStandardItemModel>
#include <QFile>
#include <QTextStream>
#include <QMessageBox>
MainWindow::MainWindow(QWidget *parent): QMainWindow(parent)
    , ui(new Ui::MainWindow)
    ,

    proxy(new ProxyModel)
    , tableModel(new tablemodel) // dynamic memory
    , favouriteDialog(new Favourite(this))
{
    ui->setupUi(this);

    // QString filePath = "C:\\Users\\Alex\\QT\\BooksApp1\\data\\books.csv";
    // loadCsvData(filePath);


    ui->comboBox->addItem("year");
    for (const QString &i : tableModel->getYear())
        ui->comboBox->addItem(i);

    proxy->setSourceModel(tableModel);
    ui->tableView->setModel(proxy);

    for (int i : {1, 2, 3, 5, 6, 9, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23})
        ui->tableView->hideColumn(i);



    // connect(ui->lineEdit, &QLineEdit::textEdited, this, &MainWindow::on_lineEdit_textEdited);
}

MainWindow::~MainWindow()
{
    delete ui;

    delete tableModel;
    delete proxy;
    delete favouriteDialog;
}

void MainWindow::on_comboBox_currentTextChanged(const QString &arg1)
{
    proxy->setYear(arg1);
}

void MainWindow::on_pushButton_clicked()
{
    SecDialogue sec;
    if (sec.exec()) {
        // for (QString field: sec.getFields())
        Book book =  sec.getFields();
            //qDebug() << book.title << " " << book.author << " " << book.year << " " << book.lang << " " << book.rate;
     tableModel->addBook(book);

    }
    // sec.setModal(true);
}

void MainWindow::on_lineEdit_textEdited(const QString &arg1)
{
    proxy->setAuthor(arg1);
}




void MainWindow::on_tableView_doubleClicked(const QModelIndex &index)
{
    QList<QModelIndex> indexes = ui->tableView->selectionModel()->selectedIndexes();
    //QList<QString> row = _data.at(index.row());
    QList<QString> row;
    for (QModelIndex i: indexes)
    {
        row.push_back(i.data().toString());
    }
    Book book;
    book.author = row[7];
    book.title = row[9];
    book.link = row[21];
    book.rate1 = row[16];
    book.rate2 = row[17];
    book.rate3 = row[18];
    book.rate4 = row[19];
    book.rate5 = row[20];
    book.reviewCount = row[15];
    secwindow = new SecWindow(book, this);

    secwindow ->show();
    //if (secwindow->show())
}


void MainWindow::on_favouriteButton_clicked()
{
    favouriteDialog->show();
}

