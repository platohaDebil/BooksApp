#ifndef FAVOURITE_H
#define FAVOURITE_H

#include <QWidget>
#include <QDialog>
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


private slots:
    void on_pushButton_clicked();

    void on_pushButton54_clicked();

private:
    Ui::Favourite *ui;

};

#endif // FAVOURITE_H
