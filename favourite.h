#ifndef FAVOURITE_H
#define FAVOURITE_H

#include <QWidget>
#include <QDialog>
#include <QTableWidget>
#include <QStringList>
#include <QStandardItemModel>

namespace Ui {
class Favourite;
}

class Favourite : public QDialog
{
    Q_OBJECT

public:
    explicit Favourite(QWidget *parent = nullptr);
    ~Favourite();
    void setMainTableModel(QStandardItemModel *model);

public slots:
    void addBookToTable(const QStringList &bookDetails);

private slots:
    void on_pushButton_clicked();
    void on_pushButton54_clicked();

private:
    void loadCSVData(const QString &filePath);
    void hideAllRows();

    Ui::Favourite *ui;
};

#endif // FAVOURITE_H
