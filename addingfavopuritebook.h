#ifndef ADDINGFAVOPURITEBOOK_H
#define ADDINGFAVOPURITEBOOK_H

#include <QDialog>
#include <QStandardItemModel>
#include <QStringList>

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

signals:
    void bookSelected(const QStringList &bookDetails);

private slots:
    void on_buttonBox_accepted();
    void on_pushButton_clicked();
    void on_tableView65_activated(const QModelIndex &index);
    void on_lineEdit65_editingFinished();

private:
    Ui::addingfavopuritebook *ui;
    QStandardItemModel *model;
};

#endif // ADDINGFAVOPURITEBOOK_H
