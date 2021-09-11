#ifndef IZPISPODATKOV_H
#define IZPISPODATKOV_H

#include <QDialog>
#include <QDebug>
#include <QTableWidget>
#include <QFile>
#include <QComboBox>


namespace Ui {
class izpispodatkov;
}

class Izpispodatkov : public QDialog
{
    Q_OBJECT

public:
    explicit Izpispodatkov(QWidget *parent = 0);
    ~Izpispodatkov();

private slots:
    void on_pushButton_clicked();

private:
    Ui::izpispodatkov *ui;

    QTableWidget* compTable;
    int stKategorij;
    std::vector<int> kategorijeItems;
    std::vector<QString> kategorijeItemsDesc;

};

#endif // IZPISPODATKOV_H
