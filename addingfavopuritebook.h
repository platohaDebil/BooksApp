#ifndef ADDINGFAVOPURITEBOOK_H
#define ADDINGFAVOPURITEBOOK_H

#include <QDialog>
#include <QStandardItemModel>

namespace Ui {
class addingfavopuritebook;
}

class addingfavopuritebook : public QDialog
{
    Q_OBJECT

public:
    explicit addingfavopuritebook(QWidget *parent = nullptr);
    ~addingfavopuritebook();
    void loadCSVData(const QString &filePath);

private slots:

    void on_buttonBox_accepted();

    void on_pushButton_clicked();

    void on_tableView65_activated(const QModelIndex &index);


private:
    Ui::addingfavopuritebook *ui;
    QStandardItemModel *model;
};

#endif // ADDINGFAVOPURITEBOOK_H
