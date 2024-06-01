/********************************************************************************
** Form generated from reading UI file 'favourite.ui'
**
** Created by: Qt User Interface Compiler version 6.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FAVOURITE_H
#define UI_FAVOURITE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Favourite
{
public:
    QPushButton *pushButton54;
    QTableWidget *tableWidget54;

    void setupUi(QWidget *Favourite)
    {
        if (Favourite->objectName().isEmpty())
            Favourite->setObjectName("Favourite");
        Favourite->resize(980, 628);
        pushButton54 = new QPushButton(Favourite);
        pushButton54->setObjectName("pushButton54");
        pushButton54->setGeometry(QRect(19, 1, 951, 61));
        tableWidget54 = new QTableWidget(Favourite);
        tableWidget54->setObjectName("tableWidget54");
        tableWidget54->setGeometry(QRect(20, 61, 951, 561));

        retranslateUi(Favourite);

        QMetaObject::connectSlotsByName(Favourite);
    } // setupUi

    void retranslateUi(QWidget *Favourite)
    {
        Favourite->setWindowTitle(QCoreApplication::translate("Favourite", "Form", nullptr));
        pushButton54->setText(QCoreApplication::translate("Favourite", "Add favourite book", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Favourite: public Ui_Favourite {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FAVOURITE_H
