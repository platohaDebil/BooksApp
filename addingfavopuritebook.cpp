#include "addingfavopuritebook.h"
#include "ui_addingfavopuritebook.h"
#include <QFile>
#include <QTextStream>
#include <QMessageBox>

addingfavopuritebook::addingfavopuritebook(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::addingfavopuritebook)
    , model(new QStandardItemModel(this))
{
    ui->setupUi(this);
    ui->tableView65->setModel(model);

    QString filePath = "//Users//german_hse//Desktop//mansur.csv";
    loadCSVData(filePath);
    for (int i : {1, 2, 3, 5, 6, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23})
        ui->tableView65->setColumnHidden(i, true);
}

addingfavopuritebook::~addingfavopuritebook()
{
    delete ui;
}

void addingfavopuritebook::on_buttonBox_accepted()
{
    // Эта функция может быть пустой, если она не используется
}

void addingfavopuritebook::on_pushButton_clicked()
{
    QString filePath = "//Users//german_hse//Desktop//mansur.csv";
    loadCSVData(filePath);
}

void addingfavopuritebook::on_tableView65_activated(const QModelIndex &index)
{
    QStringList bookDetails;
    for (int column = 0; column < model->columnCount(); ++column) {
        bookDetails << model->data(model->index(index.row(), column)).toString();
    }
    emit bookSelected(bookDetails);
}

void addingfavopuritebook::loadCSVData(const QString &filePath)
{
    QFile file(filePath);
    if (!file.open(QIODevice::ReadOnly)) {
        QMessageBox::critical(this, "Ошибка", "Не удалось открыть файл: " + file.errorString());
        return;
    }

    QTextStream in(&file);
    model->clear();  // Очистка старых данных
    QStringList headers = in.readLine().split(",");  // Чтение заголовков
    model->setHorizontalHeaderLabels(headers);

    while (!in.atEnd()) {
        QStringList fields = in.readLine().split(",");
        // Удаляем кавычки из всех колонок
        for (QString &field : fields) {
            field.remove("\"");
        }
        // Проверяем и модифицируем данные в колонке 8
        if (fields.size() > 8) {
            fields[8].remove(".0"); // Убираем '.0'
        }
        QList<QStandardItem *> items;
        for (const QString &field : fields) {
            items.append(new QStandardItem(field));
        }
        model->appendRow(items);
    }
    file.close();
}

void addingfavopuritebook::on_lineEdit65_editingFinished()
{
    QString bookId = ui->lineEdit65->text().trimmed();
    bool found = false;
    if (!bookId.isEmpty()) {
        for (int row = 0; row < model->rowCount(); ++row) {
            QString currentBookId = model->data(model->index(row, 0)).toString(); // Колонка book_id предполагается первой
            if (currentBookId == bookId) {
                QStringList bookDetails;
                for (int column = 0; column < model->columnCount(); ++column) {
                    bookDetails << model->data(model->index(row, column)).toString();
                }
                emit bookSelected(bookDetails);
                found = true;
                break;
            }
        }
        if (!found) {
            QMessageBox::information(this, "Результат поиска", "Книга с ID \"" + bookId + "\" не найдена.");
        }
    }
}

