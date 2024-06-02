/********************************************************************************
** Form generated from reading UI file 'addingfavopuritebook.ui'
**
** Created by: Qt User Interface Compiler version 6.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDINGFAVOPURITEBOOK_H
#define UI_ADDINGFAVOPURITEBOOK_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableView>

QT_BEGIN_NAMESPACE

class Ui_addingfavopuritebook
{
public:
    QPushButton *pushButton;
    QTableView *tableView65;
    QLineEdit *lineEdit65;

    void setupUi(QDialog *addingfavopuritebook)
    {
        if (addingfavopuritebook->objectName().isEmpty())
            addingfavopuritebook->setObjectName("addingfavopuritebook");
        addingfavopuritebook->resize(521, 283);
        pushButton = new QPushButton(addingfavopuritebook);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(1000, 0, 100, 32));
        tableView65 = new QTableView(addingfavopuritebook);
        tableView65->setObjectName("tableView65");
        tableView65->setGeometry(QRect(576, 312, 20, 20));
        lineEdit65 = new QLineEdit(addingfavopuritebook);
        lineEdit65->setObjectName("lineEdit65");
        lineEdit65->setGeometry(QRect(150, 10, 211, 21));

        retranslateUi(addingfavopuritebook);
        QObject::connect(pushButton, &QPushButton::clicked, addingfavopuritebook, qOverload<>(&QDialog::close));

        QMetaObject::connectSlotsByName(addingfavopuritebook);
    } // setupUi

    void retranslateUi(QDialog *addingfavopuritebook)
    {
        addingfavopuritebook->setWindowTitle(QCoreApplication::translate("addingfavopuritebook", "Dialog", nullptr));
        pushButton->setText(QCoreApplication::translate("addingfavopuritebook", "Close ", nullptr));
        lineEdit65->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class addingfavopuritebook: public Ui_addingfavopuritebook {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDINGFAVOPURITEBOOK_H
