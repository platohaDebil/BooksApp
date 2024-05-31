#ifndef SECWINDOW_H
#define SECWINDOW_H

#include <QMainWindow>
#include "supplementary.h"

namespace Ui {
class SecWindow;
}

class SecWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit SecWindow(const Book& book, QWidget *parent = nullptr);
    ~SecWindow();

private:
    Ui::SecWindow *ui;

};

#endif // SECWINDOW_H
