#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "proxymodel.h"
#include "tablemodel.h"
#include "secwindow.h"
QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_comboBox_currentTextChanged(const QString &arg1);

    void on_pushButton_clicked();

    void on_tableView_doubleClicked(const QModelIndex &index);

private:
    Ui::MainWindow *ui;
    tablemodel *tableModel;
    ProxyModel *proxy;
    SecWindow *secwindow;
};

#endif // MAINWINDOW_H
