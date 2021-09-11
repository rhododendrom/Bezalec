/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionOdpri;
    QAction *actionShrani;
    QAction *actionIzhod;
    QAction *actionKategorije;
    QAction *actionPripravi_izpis;
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    QTabWidget *tabWidget;
    QWidget *tab;
    QGridLayout *gridLayout_2;
    QComboBox *comboBoxRegSpol;
    QTableWidget *tableWidgetRegVnos;
    QLineEdit *lineEditRegIme;
    QLabel *label_3;
    QLineEdit *lineEditRegKlub;
    QLabel *label_4;
    QPushButton *pushButtonReg;
    QComboBox *comboBoxRegKat;
    QLineEdit *lineEditRegNumber;
    QWidget *tab_2;
    QGridLayout *gridLayout_3;
    QLineEdit *lineEditCompCas;
    QPushButton *pushButtonComp;
    QLineEdit *lineEditCompStartna;
    QTableWidget *tableWidgetCompVnos;
    QMenuBar *menuBar;
    QMenu *menuDatoteka;
    QMenu *menuNastavitve;
    QMenu *menuIzpis;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(926, 665);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        actionOdpri = new QAction(MainWindow);
        actionOdpri->setObjectName(QStringLiteral("actionOdpri"));
        actionShrani = new QAction(MainWindow);
        actionShrani->setObjectName(QStringLiteral("actionShrani"));
        actionIzhod = new QAction(MainWindow);
        actionIzhod->setObjectName(QStringLiteral("actionIzhod"));
        actionKategorije = new QAction(MainWindow);
        actionKategorije->setObjectName(QStringLiteral("actionKategorije"));
        actionPripravi_izpis = new QAction(MainWindow);
        actionPripravi_izpis->setObjectName(QStringLiteral("actionPripravi_izpis"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(centralWidget->sizePolicy().hasHeightForWidth());
        centralWidget->setSizePolicy(sizePolicy1);
        centralWidget->setLayoutDirection(Qt::LeftToRight);
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        tabWidget = new QTabWidget(centralWidget);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tabWidget->setMaximumSize(QSize(908, 588));
        tabWidget->setLayoutDirection(Qt::LeftToRight);
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        gridLayout_2 = new QGridLayout(tab);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        comboBoxRegSpol = new QComboBox(tab);
        comboBoxRegSpol->setObjectName(QStringLiteral("comboBoxRegSpol"));

        gridLayout_2->addWidget(comboBoxRegSpol, 6, 1, 1, 1);

        tableWidgetRegVnos = new QTableWidget(tab);
        if (tableWidgetRegVnos->columnCount() < 7)
            tableWidgetRegVnos->setColumnCount(7);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableWidgetRegVnos->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableWidgetRegVnos->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tableWidgetRegVnos->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        tableWidgetRegVnos->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        tableWidgetRegVnos->setHorizontalHeaderItem(4, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        tableWidgetRegVnos->setHorizontalHeaderItem(5, __qtablewidgetitem5);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        tableWidgetRegVnos->setHorizontalHeaderItem(6, __qtablewidgetitem6);
        tableWidgetRegVnos->setObjectName(QStringLiteral("tableWidgetRegVnos"));
        tableWidgetRegVnos->setShowGrid(true);
        tableWidgetRegVnos->setSortingEnabled(true);
        tableWidgetRegVnos->setRowCount(0);
        tableWidgetRegVnos->setColumnCount(7);
        tableWidgetRegVnos->horizontalHeader()->setVisible(true);

        gridLayout_2->addWidget(tableWidgetRegVnos, 0, 0, 12, 1);

        lineEditRegIme = new QLineEdit(tab);
        lineEditRegIme->setObjectName(QStringLiteral("lineEditRegIme"));
        sizePolicy.setHeightForWidth(lineEditRegIme->sizePolicy().hasHeightForWidth());
        lineEditRegIme->setSizePolicy(sizePolicy);

        gridLayout_2->addWidget(lineEditRegIme, 0, 1, 1, 1);

        label_3 = new QLabel(tab);
        label_3->setObjectName(QStringLiteral("label_3"));
        sizePolicy.setHeightForWidth(label_3->sizePolicy().hasHeightForWidth());
        label_3->setSizePolicy(sizePolicy);

        gridLayout_2->addWidget(label_3, 3, 1, 1, 1);

        lineEditRegKlub = new QLineEdit(tab);
        lineEditRegKlub->setObjectName(QStringLiteral("lineEditRegKlub"));
        sizePolicy.setHeightForWidth(lineEditRegKlub->sizePolicy().hasHeightForWidth());
        lineEditRegKlub->setSizePolicy(sizePolicy);

        gridLayout_2->addWidget(lineEditRegKlub, 1, 1, 1, 1);

        label_4 = new QLabel(tab);
        label_4->setObjectName(QStringLiteral("label_4"));
        sizePolicy.setHeightForWidth(label_4->sizePolicy().hasHeightForWidth());
        label_4->setSizePolicy(sizePolicy);

        gridLayout_2->addWidget(label_4, 5, 1, 1, 1);

        pushButtonReg = new QPushButton(tab);
        pushButtonReg->setObjectName(QStringLiteral("pushButtonReg"));

        gridLayout_2->addWidget(pushButtonReg, 7, 1, 1, 1);

        comboBoxRegKat = new QComboBox(tab);
        comboBoxRegKat->setObjectName(QStringLiteral("comboBoxRegKat"));

        gridLayout_2->addWidget(comboBoxRegKat, 4, 1, 1, 1);

        lineEditRegNumber = new QLineEdit(tab);
        lineEditRegNumber->setObjectName(QStringLiteral("lineEditRegNumber"));
        sizePolicy.setHeightForWidth(lineEditRegNumber->sizePolicy().hasHeightForWidth());
        lineEditRegNumber->setSizePolicy(sizePolicy);
        lineEditRegNumber->setMaxLength(3);
        lineEditRegNumber->setFrame(true);
        lineEditRegNumber->setCursorPosition(0);
        lineEditRegNumber->setCursorMoveStyle(Qt::LogicalMoveStyle);
        lineEditRegNumber->setClearButtonEnabled(false);

        gridLayout_2->addWidget(lineEditRegNumber, 2, 1, 1, 1);

        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QStringLiteral("tab_2"));
        tab_2->setEnabled(true);
        QSizePolicy sizePolicy2(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(tab_2->sizePolicy().hasHeightForWidth());
        tab_2->setSizePolicy(sizePolicy2);
        gridLayout_3 = new QGridLayout(tab_2);
        gridLayout_3->setSpacing(6);
        gridLayout_3->setContentsMargins(11, 11, 11, 11);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        lineEditCompCas = new QLineEdit(tab_2);
        lineEditCompCas->setObjectName(QStringLiteral("lineEditCompCas"));
        sizePolicy.setHeightForWidth(lineEditCompCas->sizePolicy().hasHeightForWidth());
        lineEditCompCas->setSizePolicy(sizePolicy);

        gridLayout_3->addWidget(lineEditCompCas, 2, 2, 1, 1);

        pushButtonComp = new QPushButton(tab_2);
        pushButtonComp->setObjectName(QStringLiteral("pushButtonComp"));
        QSizePolicy sizePolicy3(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(pushButtonComp->sizePolicy().hasHeightForWidth());
        pushButtonComp->setSizePolicy(sizePolicy3);

        gridLayout_3->addWidget(pushButtonComp, 5, 2, 1, 1);

        lineEditCompStartna = new QLineEdit(tab_2);
        lineEditCompStartna->setObjectName(QStringLiteral("lineEditCompStartna"));
        sizePolicy.setHeightForWidth(lineEditCompStartna->sizePolicy().hasHeightForWidth());
        lineEditCompStartna->setSizePolicy(sizePolicy);

        gridLayout_3->addWidget(lineEditCompStartna, 1, 2, 1, 1);

        tableWidgetCompVnos = new QTableWidget(tab_2);
        if (tableWidgetCompVnos->columnCount() < 8)
            tableWidgetCompVnos->setColumnCount(8);
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        tableWidgetCompVnos->setHorizontalHeaderItem(0, __qtablewidgetitem7);
        QTableWidgetItem *__qtablewidgetitem8 = new QTableWidgetItem();
        tableWidgetCompVnos->setHorizontalHeaderItem(1, __qtablewidgetitem8);
        QTableWidgetItem *__qtablewidgetitem9 = new QTableWidgetItem();
        tableWidgetCompVnos->setHorizontalHeaderItem(2, __qtablewidgetitem9);
        QTableWidgetItem *__qtablewidgetitem10 = new QTableWidgetItem();
        tableWidgetCompVnos->setHorizontalHeaderItem(3, __qtablewidgetitem10);
        QTableWidgetItem *__qtablewidgetitem11 = new QTableWidgetItem();
        tableWidgetCompVnos->setHorizontalHeaderItem(4, __qtablewidgetitem11);
        QTableWidgetItem *__qtablewidgetitem12 = new QTableWidgetItem();
        tableWidgetCompVnos->setHorizontalHeaderItem(5, __qtablewidgetitem12);
        QTableWidgetItem *__qtablewidgetitem13 = new QTableWidgetItem();
        tableWidgetCompVnos->setHorizontalHeaderItem(6, __qtablewidgetitem13);
        QTableWidgetItem *__qtablewidgetitem14 = new QTableWidgetItem();
        tableWidgetCompVnos->setHorizontalHeaderItem(7, __qtablewidgetitem14);
        tableWidgetCompVnos->setObjectName(QStringLiteral("tableWidgetCompVnos"));
        tableWidgetCompVnos->setEnabled(true);
        tableWidgetCompVnos->setFocusPolicy(Qt::StrongFocus);
        tableWidgetCompVnos->setLayoutDirection(Qt::LeftToRight);
        tableWidgetCompVnos->setSizeAdjustPolicy(QAbstractScrollArea::AdjustToContents);
        tableWidgetCompVnos->setSortingEnabled(true);
        tableWidgetCompVnos->setColumnCount(8);

        gridLayout_3->addWidget(tableWidgetCompVnos, 0, 1, 2, 1);

        tabWidget->addTab(tab_2, QString());

        gridLayout->addWidget(tabWidget, 0, 1, 1, 1);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 926, 20));
        menuDatoteka = new QMenu(menuBar);
        menuDatoteka->setObjectName(QStringLiteral("menuDatoteka"));
        menuNastavitve = new QMenu(menuBar);
        menuNastavitve->setObjectName(QStringLiteral("menuNastavitve"));
        menuIzpis = new QMenu(menuBar);
        menuIzpis->setObjectName(QStringLiteral("menuIzpis"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menuDatoteka->menuAction());
        menuBar->addAction(menuNastavitve->menuAction());
        menuBar->addAction(menuIzpis->menuAction());
        menuDatoteka->addAction(actionOdpri);
        menuDatoteka->addAction(actionShrani);
        menuDatoteka->addAction(actionIzhod);
        menuNastavitve->addAction(actionKategorije);
        menuIzpis->addAction(actionPripravi_izpis);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(0);
        comboBoxRegSpol->setCurrentIndex(-1);
        comboBoxRegKat->setCurrentIndex(-1);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Be\305\276alec", 0));
        actionOdpri->setText(QApplication::translate("MainWindow", "Odpri", 0));
        actionShrani->setText(QApplication::translate("MainWindow", "Shrani", 0));
        actionIzhod->setText(QApplication::translate("MainWindow", "Izhod", 0));
        actionKategorije->setText(QApplication::translate("MainWindow", "Kategorije", 0));
        actionPripravi_izpis->setText(QApplication::translate("MainWindow", "Pripravi izpis", 0));
        comboBoxRegSpol->clear();
        comboBoxRegSpol->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "Mo\305\241ki", 0)
         << QApplication::translate("MainWindow", "\305\275enski", 0)
        );
        QTableWidgetItem *___qtablewidgetitem = tableWidgetRegVnos->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("MainWindow", "\305\240tartna \305\241tevilka", 0));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidgetRegVnos->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("MainWindow", "Ime in Priimek", 0));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidgetRegVnos->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("MainWindow", "Poklic", 0));
        QTableWidgetItem *___qtablewidgetitem3 = tableWidgetRegVnos->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QApplication::translate("MainWindow", "Klub", 0));
        QTableWidgetItem *___qtablewidgetitem4 = tableWidgetRegVnos->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QApplication::translate("MainWindow", "Kategorija", 0));
        QTableWidgetItem *___qtablewidgetitem5 = tableWidgetRegVnos->horizontalHeaderItem(5);
        ___qtablewidgetitem5->setText(QApplication::translate("MainWindow", "Spol", 0));
        QTableWidgetItem *___qtablewidgetitem6 = tableWidgetRegVnos->horizontalHeaderItem(6);
        ___qtablewidgetitem6->setText(QApplication::translate("MainWindow", "Urejanje", 0));
        lineEditRegIme->setPlaceholderText(QApplication::translate("MainWindow", "Ime in Priimek", 0));
        label_3->setText(QApplication::translate("MainWindow", "Kategorija", 0));
        lineEditRegKlub->setPlaceholderText(QApplication::translate("MainWindow", "Klub", 0));
        label_4->setText(QApplication::translate("MainWindow", "Spol", 0));
        pushButtonReg->setText(QApplication::translate("MainWindow", "Vnesi", 0));
        lineEditRegNumber->setInputMask(QApplication::translate("MainWindow", "999", 0));
        lineEditRegNumber->setPlaceholderText(QApplication::translate("MainWindow", "\305\240tartna \305\241tevilka", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("MainWindow", "Registracija", 0));
        lineEditCompCas->setPlaceholderText(QApplication::translate("MainWindow", "\304\214as (hh:mm:ss)", 0));
        pushButtonComp->setText(QApplication::translate("MainWindow", "Vnesi \304\215as", 0));
        lineEditCompStartna->setPlaceholderText(QApplication::translate("MainWindow", "Tekmovalec", 0));
        QTableWidgetItem *___qtablewidgetitem7 = tableWidgetCompVnos->horizontalHeaderItem(0);
        ___qtablewidgetitem7->setText(QApplication::translate("MainWindow", "\305\240tartna \305\241tevilka", 0));
        QTableWidgetItem *___qtablewidgetitem8 = tableWidgetCompVnos->horizontalHeaderItem(1);
        ___qtablewidgetitem8->setText(QApplication::translate("MainWindow", "Ime in priimek", 0));
        QTableWidgetItem *___qtablewidgetitem9 = tableWidgetCompVnos->horizontalHeaderItem(2);
        ___qtablewidgetitem9->setText(QApplication::translate("MainWindow", "Poklic", 0));
        QTableWidgetItem *___qtablewidgetitem10 = tableWidgetCompVnos->horizontalHeaderItem(3);
        ___qtablewidgetitem10->setText(QApplication::translate("MainWindow", "Klub", 0));
        QTableWidgetItem *___qtablewidgetitem11 = tableWidgetCompVnos->horizontalHeaderItem(4);
        ___qtablewidgetitem11->setText(QApplication::translate("MainWindow", "Kategorija", 0));
        QTableWidgetItem *___qtablewidgetitem12 = tableWidgetCompVnos->horizontalHeaderItem(5);
        ___qtablewidgetitem12->setText(QApplication::translate("MainWindow", "Spol", 0));
        QTableWidgetItem *___qtablewidgetitem13 = tableWidgetCompVnos->horizontalHeaderItem(6);
        ___qtablewidgetitem13->setText(QApplication::translate("MainWindow", "\304\214as", 0));
        QTableWidgetItem *___qtablewidgetitem14 = tableWidgetCompVnos->horizontalHeaderItem(7);
        ___qtablewidgetitem14->setText(QApplication::translate("MainWindow", "Urejanje", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("MainWindow", "Vnos", 0));
        menuDatoteka->setTitle(QApplication::translate("MainWindow", "Datoteka", 0));
        menuNastavitve->setTitle(QApplication::translate("MainWindow", "Nastavitve", 0));
        menuIzpis->setTitle(QApplication::translate("MainWindow", "Izpis", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
