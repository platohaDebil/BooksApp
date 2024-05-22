#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

// our class
#include <QStringListModel>

#include "tablemodel.h"
QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

// awaits interaction
private slots:
    // void on_pushButton_clicked();

    // // void on_listView_clicked(const QModelIndex &index); // delegate

    // void on_comboBox_currentIndexChanged(int index);

    // void on_comboBox_currentTextChanged(const QString &arg1);

    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
    // QStringListModel *list; // model
    // Netflix *filmList; // data
    tablemodel *tableModel;
    //ProxyModel *proxy;
};
#endif // MAINWINDOW_H
