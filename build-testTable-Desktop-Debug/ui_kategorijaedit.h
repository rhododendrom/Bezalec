/********************************************************************************
** Form generated from reading UI file 'kategorijaedit.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_KATEGORIJAEDIT_H
#define UI_KATEGORIJAEDIT_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QTextEdit>

QT_BEGIN_NAMESPACE

class Ui_KategorijaEdit
{
public:
    QDialogButtonBox *buttonBox;
    QTextEdit *textEdit;

    void setupUi(QDialog *KategorijaEdit)
    {
        if (KategorijaEdit->objectName().isEmpty())
            KategorijaEdit->setObjectName(QStringLiteral("KategorijaEdit"));
        KategorijaEdit->resize(400, 300);
        buttonBox = new QDialogButtonBox(KategorijaEdit);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setGeometry(QRect(30, 240, 341, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        textEdit = new QTextEdit(KategorijaEdit);
        textEdit->setObjectName(QStringLiteral("textEdit"));
        textEdit->setGeometry(QRect(10, 10, 371, 221));

        retranslateUi(KategorijaEdit);
        QObject::connect(buttonBox, SIGNAL(accepted()), KategorijaEdit, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), KategorijaEdit, SLOT(reject()));

        QMetaObject::connectSlotsByName(KategorijaEdit);
    } // setupUi

    void retranslateUi(QDialog *KategorijaEdit)
    {
        KategorijaEdit->setWindowTitle(QApplication::translate("KategorijaEdit", "Dialog", 0));
    } // retranslateUi

};

namespace Ui {
    class KategorijaEdit: public Ui_KategorijaEdit {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_KATEGORIJAEDIT_H
