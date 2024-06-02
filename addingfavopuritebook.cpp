
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

    QString filePath = "C:\\Users\\Alex\\QT\\BooksApp\\BooksApp2\\data\\books.csv";
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
    QString filePath = "C:\\Users\\Alex\\QT\\BooksApp\\BooksApp2\\data\\books.csv";
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
    if (csvDataCache.isEmpty()) {
        QFile file(filePath);
        if (!file.open(QIODevice::ReadOnly)) {
            QMessageBox::critical(this, "Ошибка", "Не удалось открыть файл: " + file.errorString());
            return;
        }

        QTextStream in(&file);
        csvDataCache.clear();
        QStringList headers = in.readLine().split(",");  // Чтение заголовков
        model->setHorizontalHeaderLabels(headers);

        while (!in.atEnd()) {
            QStringList fields = in.readLine().split(",");
            for (QString &field : fields) {
                field.remove("\"");
            }
            if (fields.size() > 8) {
                fields[8].remove(".0");
            }
            csvDataCache.append(fields);
        }
        file.close();
    }

    model->clear();
    model->setHorizontalHeaderLabels(csvDataCache.first());
    for (const QStringList &fields : csvDataCache) {
        QList<QStandardItem *> items;
        for (const QString &field : fields) {
            items.append(new QStandardItem(field));
        }
        model->appendRow(items);
    }

    for (int i : {1, 2, 3, 5, 6, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23}) {
        ui->tableView65->setColumnHidden(i, true);
    }
}

void addingfavopuritebook::on_lineEdit65_editingFinished()
{
    QString bookId = ui->lineEdit65->text().trimmed();
    if (!bookId.isEmpty()) {
        auto it = std::find_if(csvDataCache.begin(), csvDataCache.end(), [&bookId](const QStringList &fields) {
            return fields.first() == bookId; // Assuming book_id is in the first column
        });

        if (it != csvDataCache.end()) {
            emit bookSelected(*it);
        } else {
            QMessageBox::information(this, "Результат поиска", "Книга с ID \"" + bookId + "\" не найдена.");
        }
    }
}
