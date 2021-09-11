#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSignalMapper>
#include <QDebug>
#include <QLabel>
#include <QTableView>
#include <QTableWidget>
#include <QTableWidgetItem>
#include <QFile>
#include <iostream>
#include <algorithm>
#include "kategorijaedit.h"
#include "izpispodatkov.h"

class TableIntItem : public QTableWidgetItem
{
public:
    TableIntItem(const QString & text):QTableWidgetItem(text){}

    TableIntItem(int num):QTableWidgetItem(QString::number(num)){}

    bool operator< (const QTableWidgetItem &other) const
    {
        return text().toInt() < other.text().toInt();
    }
};

class TableDateItem : public QTableWidgetItem
{
public:
    TableDateItem(const QString & text):QTableWidgetItem(text){}

    TableDateItem(int num):QTableWidgetItem(QString::number(num)){}

    bool operator< (const QTableWidgetItem &other) const
    {
        QStringList sep1 = text().split(":");
        if (sep1.length() == 1) {
            sep1.clear();
            sep1.push_back("99");
            sep1.push_back("99");
            sep1.push_back("99");
        }
        QStringList sep2 = other.text().split(":");
        if (sep2.length() == 1) {
            sep2.clear();
            sep2.push_back("99");
            sep2.push_back("99");
            sep2.push_back("99");
        }
        int num1=0;
        int num2=0;

        std::vector<int> mult={3600,60,1};
        int ind = 0;
        std::for_each(sep1.begin(),sep1.end(),[&num1,mult,&ind](QString x){num1+=x.toInt()*mult[ind];ind++;});
        ind = 0;
        std::for_each(sep2.begin(),sep2.end(),[&num2,mult,&ind](QString x){num2+=x.toInt()*mult[ind];ind++;});

        return num1 > num2;
    }
};


struct Tekmovalec {
    Tekmovalec(QStringList l) {
        startnaStevilka = l[0].toInt();
        imeTekmovalca = l[1];
        poklicTekmovalca = l[2];
        klubTekmovalca = l[3];
        katergorijaTekmovalca = l[4].toInt();
        spolTekmovalca = l[5];

        if (l[6] == "hh:mm:ss") casTekmovalca = "";
        else {
            casTekmovalca = l[6];
            std::cout << "v konstruktorju "<<casTekmovalca.toStdString()<<" => "<<l[6].toStdString()<<std::endl;
            qDebug()<< casTekmovalca;
        }
    }
    Tekmovalec(int startnaStevilka,QString imeTekmovalca,QString poklicTekmovalca,QString klubTekmovalca,int katergorijaTekmovalca, QString spolTekmovalca, QString casTekmovalca){
        this->startnaStevilka = startnaStevilka;
        this->imeTekmovalca = imeTekmovalca;
        this->poklicTekmovalca = poklicTekmovalca;
        this->klubTekmovalca = klubTekmovalca;
        this->katergorijaTekmovalca = katergorijaTekmovalca;
        this->spolTekmovalca = spolTekmovalca;

        this->casTekmovalca = casTekmovalca;
    }

    int startnaStevilka;
    QString imeTekmovalca;
    QString poklicTekmovalca;
    QString klubTekmovalca;
    int katergorijaTekmovalca;
    QString spolTekmovalca;
    QString casTekmovalca;
};

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    QStringList kategorijeFullDesc;


    ~MainWindow();
protected:
    KategorijaEdit* katEdit;
    Izpispodatkov* izpis;

private slots:

    void on_pushButtonReg_clicked();
    void on_pushButtonComp_clicked();

public slots:


     void onActionOdpriFile();
     void onActionShraniFile();
     void onActionKategorije();
     void onActionIzpisPodatkov();

     void pushRemoveEntry(int row);

private:
    Ui::MainWindow *ui;

    void inputData();
    void insertOneRow(int numRow, Tekmovalec tekmovalec);
    void populateCategories();
};

#endif // MAINWINDOW_H
