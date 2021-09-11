/********************************************************************************
** Form generated from reading UI file 'izpispodatkov.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_IZPISPODATKOV_H
#define UI_IZPISPODATKOV_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextBrowser>

QT_BEGIN_NAMESPACE

class Ui_izpispodatkov
{
public:
    QGroupBox *groupBox;
    QCheckBox *checkBoxSpol;
    QCheckBox *checkBoxKategorija;
    QPushButton *pushButton;
    QTextBrowser *textBrowser;

    void setupUi(QDialog *izpispodatkov)
    {
        if (izpispodatkov->objectName().isEmpty())
            izpispodatkov->setObjectName(QStringLiteral("izpispodatkov"));
        izpispodatkov->resize(893, 601);
        groupBox = new QGroupBox(izpispodatkov);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(740, 20, 101, 111));
        checkBoxSpol = new QCheckBox(groupBox);
        checkBoxSpol->setObjectName(QStringLiteral("checkBoxSpol"));
        checkBoxSpol->setGeometry(QRect(10, 20, 85, 21));
        checkBoxKategorija = new QCheckBox(groupBox);
        checkBoxKategorija->setObjectName(QStringLiteral("checkBoxKategorija"));
        checkBoxKategorija->setGeometry(QRect(10, 40, 85, 21));
        pushButton = new QPushButton(groupBox);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(10, 80, 81, 23));
        textBrowser = new QTextBrowser(izpispodatkov);
        textBrowser->setObjectName(QStringLiteral("textBrowser"));
        textBrowser->setGeometry(QRect(30, 10, 691, 571));

        retranslateUi(izpispodatkov);

        QMetaObject::connectSlotsByName(izpispodatkov);
    } // setupUi

    void retranslateUi(QDialog *izpispodatkov)
    {
        izpispodatkov->setWindowTitle(QApplication::translate("izpispodatkov", "Dialog", 0));
        groupBox->setTitle(QApplication::translate("izpispodatkov", "Filtri", 0));
        checkBoxSpol->setText(QApplication::translate("izpispodatkov", "Spol", 0));
        checkBoxKategorija->setText(QApplication::translate("izpispodatkov", "Kategorija", 0));
        pushButton->setText(QApplication::translate("izpispodatkov", "Prika\305\276i", 0));
    } // retranslateUi

};

namespace Ui {
    class izpispodatkov: public Ui_izpispodatkov {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_IZPISPODATKOV_H
