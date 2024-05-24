/********************************************************************************
** Form generated from reading UI file 'secdialogue.ui'
**
** Created by: Qt User Interface Compiler version 6.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SECDIALOGUE_H
#define UI_SECDIALOGUE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAbstractButton>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_SecDialogue
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QLineEdit *lineEdit;
    QLabel *label_2;
    QLineEdit *lineEdit_2;
    QLabel *label_3;
    QLineEdit *lineEdit_3;
    QLabel *label_4;
    QLineEdit *lineEdit_4;
    QLabel *label_5;
    QLineEdit *lineEdit_5;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *SecDialogue)
    {
        if (SecDialogue->objectName().isEmpty())
            SecDialogue->setObjectName("SecDialogue");
        SecDialogue->resize(400, 317);
        verticalLayout = new QVBoxLayout(SecDialogue);
        verticalLayout->setObjectName("verticalLayout");
        label = new QLabel(SecDialogue);
        label->setObjectName("label");

        verticalLayout->addWidget(label);

        lineEdit = new QLineEdit(SecDialogue);
        lineEdit->setObjectName("lineEdit");

        verticalLayout->addWidget(lineEdit);

        label_2 = new QLabel(SecDialogue);
        label_2->setObjectName("label_2");

        verticalLayout->addWidget(label_2);

        lineEdit_2 = new QLineEdit(SecDialogue);
        lineEdit_2->setObjectName("lineEdit_2");

        verticalLayout->addWidget(lineEdit_2);

        label_3 = new QLabel(SecDialogue);
        label_3->setObjectName("label_3");

        verticalLayout->addWidget(label_3);

        lineEdit_3 = new QLineEdit(SecDialogue);
        lineEdit_3->setObjectName("lineEdit_3");

        verticalLayout->addWidget(lineEdit_3);

        label_4 = new QLabel(SecDialogue);
        label_4->setObjectName("label_4");

        verticalLayout->addWidget(label_4);

        lineEdit_4 = new QLineEdit(SecDialogue);
        lineEdit_4->setObjectName("lineEdit_4");

        verticalLayout->addWidget(lineEdit_4);

        label_5 = new QLabel(SecDialogue);
        label_5->setObjectName("label_5");

        verticalLayout->addWidget(label_5);

        lineEdit_5 = new QLineEdit(SecDialogue);
        lineEdit_5->setObjectName("lineEdit_5");

        verticalLayout->addWidget(lineEdit_5);

        buttonBox = new QDialogButtonBox(SecDialogue);
        buttonBox->setObjectName("buttonBox");
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        verticalLayout->addWidget(buttonBox);


        retranslateUi(SecDialogue);
        QObject::connect(buttonBox, &QDialogButtonBox::accepted, SecDialogue, qOverload<>(&QDialog::accept));
        QObject::connect(buttonBox, &QDialogButtonBox::rejected, SecDialogue, qOverload<>(&QDialog::reject));

        QMetaObject::connectSlotsByName(SecDialogue);
    } // setupUi

    void retranslateUi(QDialog *SecDialogue)
    {
        SecDialogue->setWindowTitle(QCoreApplication::translate("SecDialogue", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("SecDialogue", "Title:", nullptr));
#if QT_CONFIG(whatsthis)
        lineEdit->setWhatsThis(QCoreApplication::translate("SecDialogue", "<html><head/><body><p><br/></p></body></html>", nullptr));
#endif // QT_CONFIG(whatsthis)
        lineEdit->setText(QString());
        label_2->setText(QCoreApplication::translate("SecDialogue", "Author:", nullptr));
        lineEdit_2->setText(QString());
        label_3->setText(QCoreApplication::translate("SecDialogue", "Year:", nullptr));
        lineEdit_3->setText(QString());
        label_4->setText(QCoreApplication::translate("SecDialogue", "Language:", nullptr));
        lineEdit_4->setText(QString());
        label_5->setText(QCoreApplication::translate("SecDialogue", "Rating:", nullptr));
        lineEdit_5->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class SecDialogue: public Ui_SecDialogue {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SECDIALOGUE_H
