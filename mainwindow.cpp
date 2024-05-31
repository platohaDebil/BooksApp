#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "secdialogue.h"
#include <QDebug>
#include <QStandardItemModel>
#include <QFile>
#include <QTextStream>
#include <QMessageBox>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    ,

    proxy(new ProxyModel)
    , model(new QStandardItemModel(this))
    , tableModel(new tablemodel) // dynamic memory
    , favouriteDialog(new Favourite(this))
{
    ui->setupUi(this);

    QString filePath = "//Users//german_hse//Desktop//mansur.csv";
    loadCsvData(filePath);


    ui->comboBox->addItem("year");
    for (const QString &i : tableModel->getYear())
        ui->comboBox->addItem(i);

    proxy->setSourceModel(tableModel);
    ui->tableView->setModel(proxy);

    for (int i : {1, 2, 3, 5, 6, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23})
        ui->tableView->hideColumn(i);



    connect(ui->lineEdit, &QLineEdit::textEdited, this, &MainWindow::on_lineEdit_textEdited);
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
        Book book = sec.getFields();
        qDebug() << book.title << " " << book.author << " " << book.year << " " << book.lang << " "
                 << book.rate;
        tableModel->addBook(book);
    }
    // sec.setModal(true);
}

void MainWindow::on_lineEdit_textEdited(const QString &arg1)
{
     searchBooksByAuthor(arg1);
}

void MainWindow::searchBooksByAuthor(const QString &author)
{

    int authorColumn = 7;
    for (int row = 0; row < model->rowCount(); ++row) {
        QModelIndex index = model->index(row, authorColumn);
        QString itemText = model->data(index).toString();
        bool match = itemText.contains(author, Qt::CaseInsensitive);
        ui->tableView->setRowHidden(row, !match);
    }
}

void MainWindow::loadCsvData(const QString &filePath)
{
    QFile file(filePath);
    if (!file.open(QIODevice::ReadOnly)) {
        QMessageBox::critical(this, "Ошибка", "Не удалось открыть файл");
        return;
    }

    QTextStream in(&file);
    QStringList headers;
    if (!in.atEnd()) {

        QString line = in.readLine();
        headers = line.split(",");
        model->setColumnCount(headers.size());
        for (int i = 0; i < headers.size(); ++i) {
            model->setHeaderData(i, Qt::Horizontal, headers.at(i));
        }
    }


    while (!in.atEnd()) {
        QString line = in.readLine();
        QStringList fields = line.split(",");
        QList<QStandardItem *> items;
        for (const QString &field : fields) {
            items.append(new QStandardItem(field));
        }
        model->appendRow(items);
    }

    file.close();
}


void MainWindow::on_favouriteButton_clicked()
{
    favouriteDialog->show();
}

