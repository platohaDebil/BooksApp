/********************************************************************************
** Form generated from reading UI file 'secwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SECWINDOW_H
#define UI_SECWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SecWindow
{
public:
    QWidget *centralwidget;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QLineEdit *lineEdit_9;
    QLabel *label_2;
    QLineEdit *lineEdit_8;
    QLabel *label_3;
    QLineEdit *lineEdit_7;
    QLabel *label_4;
    QLineEdit *lineEdit_6;
    QLabel *label_5;
    QLineEdit *lineEdit_5;
    QLabel *label_6;
    QLineEdit *lineEdit_4;
    QLabel *label_7;
    QLineEdit *lineEdit_2;
    QLabel *label_8;
    QLineEdit *lineEdit_3;
    QLabel *label_9;
    QLineEdit *lineEdit;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *SecWindow)
    {
        if (SecWindow->objectName().isEmpty())
            SecWindow->setObjectName("SecWindow");
        SecWindow->resize(800, 600);
        centralwidget = new QWidget(SecWindow);
        centralwidget->setObjectName("centralwidget");
        verticalLayoutWidget = new QWidget(centralwidget);
        verticalLayoutWidget->setObjectName("verticalLayoutWidget");
        verticalLayoutWidget->setGeometry(QRect(9, 9, 371, 418));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(verticalLayoutWidget);
        label->setObjectName("label");

        verticalLayout->addWidget(label);

        lineEdit_9 = new QLineEdit(verticalLayoutWidget);
        lineEdit_9->setObjectName("lineEdit_9");
        lineEdit_9->setReadOnly(true);

        verticalLayout->addWidget(lineEdit_9);

        label_2 = new QLabel(verticalLayoutWidget);
        label_2->setObjectName("label_2");

        verticalLayout->addWidget(label_2);

        lineEdit_8 = new QLineEdit(verticalLayoutWidget);
        lineEdit_8->setObjectName("lineEdit_8");
        lineEdit_8->setReadOnly(true);

        verticalLayout->addWidget(lineEdit_8);

        label_3 = new QLabel(verticalLayoutWidget);
        label_3->setObjectName("label_3");

        verticalLayout->addWidget(label_3);

        lineEdit_7 = new QLineEdit(verticalLayoutWidget);
        lineEdit_7->setObjectName("lineEdit_7");
        lineEdit_7->setReadOnly(true);

        verticalLayout->addWidget(lineEdit_7);

        label_4 = new QLabel(verticalLayoutWidget);
        label_4->setObjectName("label_4");

        verticalLayout->addWidget(label_4);

        lineEdit_6 = new QLineEdit(verticalLayoutWidget);
        lineEdit_6->setObjectName("lineEdit_6");
        lineEdit_6->setReadOnly(true);

        verticalLayout->addWidget(lineEdit_6);

        label_5 = new QLabel(verticalLayoutWidget);
        label_5->setObjectName("label_5");

        verticalLayout->addWidget(label_5);

        lineEdit_5 = new QLineEdit(verticalLayoutWidget);
        lineEdit_5->setObjectName("lineEdit_5");
        lineEdit_5->setReadOnly(true);

        verticalLayout->addWidget(lineEdit_5);

        label_6 = new QLabel(verticalLayoutWidget);
        label_6->setObjectName("label_6");

        verticalLayout->addWidget(label_6);

        lineEdit_4 = new QLineEdit(verticalLayoutWidget);
        lineEdit_4->setObjectName("lineEdit_4");
        lineEdit_4->setReadOnly(true);

        verticalLayout->addWidget(lineEdit_4);

        label_7 = new QLabel(verticalLayoutWidget);
        label_7->setObjectName("label_7");

        verticalLayout->addWidget(label_7);

        lineEdit_2 = new QLineEdit(verticalLayoutWidget);
        lineEdit_2->setObjectName("lineEdit_2");
        lineEdit_2->setReadOnly(true);

        verticalLayout->addWidget(lineEdit_2);

        label_8 = new QLabel(verticalLayoutWidget);
        label_8->setObjectName("label_8");

        verticalLayout->addWidget(label_8);

        lineEdit_3 = new QLineEdit(verticalLayoutWidget);
        lineEdit_3->setObjectName("lineEdit_3");
        lineEdit_3->setReadOnly(true);

        verticalLayout->addWidget(lineEdit_3);

        label_9 = new QLabel(verticalLayoutWidget);
        label_9->setObjectName("label_9");

        verticalLayout->addWidget(label_9);

        lineEdit = new QLineEdit(verticalLayoutWidget);
        lineEdit->setObjectName("lineEdit");
        lineEdit->setReadOnly(true);

        verticalLayout->addWidget(lineEdit);

        SecWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(SecWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 17));
        SecWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(SecWindow);
        statusbar->setObjectName("statusbar");
        SecWindow->setStatusBar(statusbar);

        retranslateUi(SecWindow);

        QMetaObject::connectSlotsByName(SecWindow);
    } // setupUi

    void retranslateUi(QMainWindow *SecWindow)
    {
        SecWindow->setWindowTitle(QCoreApplication::translate("SecWindow", "MainWindow", nullptr));
        label->setText(QCoreApplication::translate("SecWindow", "Title", nullptr));
        label_2->setText(QCoreApplication::translate("SecWindow", "Author", nullptr));
        label_3->setText(QCoreApplication::translate("SecWindow", "Rating1", nullptr));
        label_4->setText(QCoreApplication::translate("SecWindow", "Rating2", nullptr));
        label_5->setText(QCoreApplication::translate("SecWindow", "Rating3", nullptr));
        label_6->setText(QCoreApplication::translate("SecWindow", "Rating4", nullptr));
        label_7->setText(QCoreApplication::translate("SecWindow", "Rating5", nullptr));
        label_8->setText(QCoreApplication::translate("SecWindow", "Rewiews Count", nullptr));
        label_9->setText(QCoreApplication::translate("SecWindow", "Image Link", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SecWindow: public Ui_SecWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SECWINDOW_H
