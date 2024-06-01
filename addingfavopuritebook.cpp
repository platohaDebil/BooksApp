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
        ui->tableView65->hideColumn(i);

}

addingfavopuritebook::~addingfavopuritebook()
{
    delete ui;
}

void addingfavopuritebook::on_buttonBox_accepted()
{

}
void addingfavopuritebook::on_pushButton_clicked()
{
    QString filePath = "//Users//german_hse//Desktop//mansur.csv";
    loadCSVData(filePath);
}
void addingfavopuritebook::on_tableView65_activated(const QModelIndex &index)
{
    QString filePath = "//Users//german_hse//Desktop//mansur.csv";
    loadCSVData(filePath);
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
        // Проверяем и модифицируем данные в колонках 7 и 8
        if (fields.size() > 7) {
            fields[7].replace("\"", ""); // Убираем кавычки в 7-й колонке
        }
        if (fields.size() > 8) {
            fields[8] = QString::number(fields[8].toDouble(), 'f', 0); // Форматируем 8-ю колонку, чтобы убрать '.0'
        }
        QList<QStandardItem *> items;
        for (const QString &field : fields) {
            items.append(new QStandardItem(field));
        }
        model->appendRow(items);
    }
    file.close();
}

