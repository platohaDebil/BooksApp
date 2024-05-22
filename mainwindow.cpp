#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow),

      proxy(new ProxyModel),
      tableModel(new tablemodel) // dynamic memory
{
    ui->setupUi(this);

     ui->tableView->setModel(tableModel);
    for (int i: {1,2,3,5,6,13,14,15,16,17,18,19,20,21,22,23})
        ui->tableView->hideColumn(i);
    proxy->setSourceModel(tableModel);
    ui->tableView->setModel(proxy);
    ui->comboBox->addItem("year");

     for (const QString &i: tableModel->getYear())
         ui->comboBox->addItem(i);
}

MainWindow::~MainWindow()
{
    delete ui;

    delete tableModel;
    delete proxy;
}


void MainWindow::on_comboBox_currentTextChanged(const QString &arg1)
{
    proxy->setYear(arg1);
}

