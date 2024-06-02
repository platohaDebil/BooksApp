#ifndef SECWINDOW_H
#define SECWINDOW_H

#include <QMainWindow>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include "supplementary.h"

namespace Ui {
class SecWindow;
}

class SecWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit SecWindow(const Book &book, QWidget *parent = nullptr);
    ~SecWindow();

private slots:
    void onImageLoaded(QNetworkReply *reply);

private:
    Ui::SecWindow *ui;
    QNetworkAccessManager *networkManager;
};

#endif // SECWINDOW_H
