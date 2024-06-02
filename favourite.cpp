#include "favourite.h"
#include "ui_favourite.h"
#include "addingfavopuritebook.h"
#include <QFile>
#include <QTextStream>
#include <QMessageBox>
#include <QDebug>

Favourite::Favourite(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Favourite)
{
    ui->setupUi(this);
    QString filePath = "//Users//german_hse//Desktop//mansur.csv";
    loadCSVData(filePath); // Загружаем данные из CSV файла при инициализации окна
    hideAllRows(); // Скрываем все строки после загрузки данных
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
    addingfavopuritebook* addingBook = new addingfavopuritebook(this); // Создание диалога
    connect(addingBook, &addingfavopuritebook::bookSelected, this, &Favourite::addBookToTable); // Подключение сигнала к слоту
    addingBook->exec(); // Запуск диалога
    delete addingBook; // Удаление диалога после закрытия
}

void Favourite::addBookToTable(const QStringList &bookDetails)
{
    hideAllRows(); // Скрываем все строки перед добавлением новой строки
    int row = ui->tableWidget54->rowCount();
    ui->tableWidget54->insertRow(row);
    for (int column = 0; column < bookDetails.size(); ++column) {
        ui->tableWidget54->setItem(row, column, new QTableWidgetItem(bookDetails[column]));
    }
    ui->tableWidget54->setRowHidden(row, false); // Отображаем добавленную строку
}

void Favourite::loadCSVData(const QString &filePath)
{
    QFile file(filePath);
    if (!file.open(QIODevice::ReadOnly)) {
        QMessageBox::critical(this, "Ошибка", "Не удалось открыть файл: " + file.errorString());
        return;
    }

    QTextStream in(&file);
    QStringList headers = in.readLine().split(",");  // Чтение заголовков
    ui->tableWidget54->setColumnCount(headers.size());
    ui->tableWidget54->setHorizontalHeaderLabels(headers);

    while (!in.atEnd()) {
        QString s = in.readLine();
        QStringList row = s.split(",");

        // Удаляем ".0" из 8-й колонки и кавычки из всех колонок
        for (QString &field : row) {
            field.remove("\"");
        }
        if (row.size() > 8) {
            row[8].remove(".0");
        }

        int rowNum = ui->tableWidget54->rowCount();
        ui->tableWidget54->insertRow(rowNum);
        for (int column = 0; column < row.size(); ++column) {
            ui->tableWidget54->setItem(rowNum, column, new QTableWidgetItem(row[column]));
        }
    }
    file.close();

    // Скрываем определенные колонки
    for (int i : {1, 2, 3, 5, 6, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23}) {
        ui->tableWidget54->setColumnHidden(i, true);
    }
}

void Favourite::hideAllRows()
{
    for (int i = 0; i < ui->tableWidget54->rowCount(); ++i) {
        ui->tableWidget54->setRowHidden(i, true);
    }
}
