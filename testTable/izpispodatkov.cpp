#include "izpispodatkov.h"
#include "ui_izpispodatkov.h"


Izpispodatkov::Izpispodatkov(QWidget *parent) : QDialog(parent), ui(new Ui::izpispodatkov)
{
    compTable = parent->findChild<QTableWidget*>("tableWidgetCompVnos");
    stKategorij = parent->findChild<QComboBox*>("comboBoxRegKat")->count();
    for (int i = 0; i < stKategorij; i++) {
        kategorijeItems.push_back(parent->findChild<QComboBox*>("comboBoxRegKat")->itemText(i).toInt());
    }
    //std::sort(kategorijeItems.begin(),kategorijeItems.end());

    QString data;
    QFile importedCSV("kategorije.txt");
    QStringList rowOfData;
    QStringList rowDataFull;
    if (importedCSV.open(QFile::ReadOnly)){
        data = importedCSV.readAll();
        rowOfData = data.split("\n");
        importedCSV.close();
    }
    for (int x = 0; x < rowOfData.size(); x++)
    {
        rowDataFull = rowOfData.at(x).split(";");
        kategorijeItemsDesc.push_back(rowDataFull[1]);
    }

    std::vector<int> kA;
    std::vector<QString> kD;
    for (int k = 0; k < stKategorij; k++) {

        for (int i = 0; i < compTable->rowCount(); i++) {

            if(compTable->item(i,4)->text().toInt() == kategorijeItems[k]) {

                kA.push_back(kategorijeItems[k]);
                kD.push_back(kategorijeItemsDesc[k]);
                break;
            }
        }
    }
    kategorijeItems = kA;
    kategorijeItemsDesc = kD;
    stKategorij = kategorijeItems.size();


    ui->setupUi(this);
}

Izpispodatkov::~Izpispodatkov()
{
    delete ui;
}

void Izpispodatkov::on_pushButton_clicked()
{
    ui->textBrowser->clear();
    bool spolChecked = ui->checkBoxSpol->isChecked();
    bool katChecked = ui->checkBoxKategorija->isChecked();

    std::vector<int> order = {1,2,3,-1,4,0,6};
    //spolChecked = true;
    //katChecked = true;


    QTableWidget sep[2];
    sep[0].setColumnCount(7);
    sep[1].setColumnCount(7);

    compTable->sortByColumn(6);

    for (int i = 0; i < compTable->rowCount(); i++) {
        if (compTable->isRowHidden(i)) continue;
        int ind = 0;
        if (compTable->item(i,5)->text() == "moški") ind = 0;
        else ind = 1;

        int c = sep[ind].rowCount();
        sep[ind].insertRow(c);
        //Prešteje število vrstic v kodi
        for (int j = 0; j < compTable->columnCount()-1; j++) {
            QTableWidgetItem* dd= new QTableWidgetItem(*compTable->item(i,j));
            sep[ind].setItem(c,j,dd);
        }
    }



    QString htmlCode = "<html> <head><meta http-equiv=\"Content-Type\" content=\"text/html; charset=utf-8\"><style>th,td{text-align: center;} table {width:100%;} </style> </head> <body>";

    QFile file("sample1.html");

    QTextStream data( &file );

    if (spolChecked && !katChecked) {

        for (int s=0; s < 2; s++) {
            if (s == 0) htmlCode.append("<center><b>Rezultat moški</b></center>");
            else htmlCode.append("<center><b>Rezultat ženske</b></center>");
            htmlCode.append("<br/><table><tr><th>Zap. št.</th><th>Ime in priimek</th><th>Poklic</th><th>Ekipa</th><th>Kategorija</th><th>Štartna št.</th><th>Čas</th></tr>");
            for (int i = 0; i < sep[s].rowCount(); i++) {

                htmlCode.append("<tr>");
                htmlCode.append("<td>").append(QString::number(i+1)).append("</td>");
                for (int j = 0; j < sep[s].columnCount(); j++) {
                    if (j == 3) continue;
                    if (j == 6) {
                        htmlCode.append("<td>");
                        if(sep[s].item(i,order[j]) ->text() == "") htmlCode.append("DNF");
                        else htmlCode.append(sep[s].item(i,order[j])->text());
                        htmlCode.append("</td>");
                        continue;
                    }

                    htmlCode.append("<td>");
                    htmlCode.append(sep[s].item(i,order[j])->text());
                    qDebug() << sep[s].item(i,order[j])->text();
                    htmlCode.append("</td>");
                }
                htmlCode.append("</tr>");
            }
            htmlCode.append("</table><br/>");
        }        
    }
    else if (spolChecked && katChecked) {
        qDebug() << "Izpis po spolih in kategorijah";
        //Zdaj je potrebno narediti x tabel s kategorijami
        //Odstani kategorije ki ni v tabeli



        for (int s = 0; s < 2; s++) {
            qDebug() << s;
            for (int kat = 0; kat < stKategorij; kat++) {
                htmlCode.append("<center>"+kategorijeItemsDesc[kat]+"</center>");
                htmlCode.append("<br/><table><tr><th>Zap. št.</th><th>Ime in priimek</th><th>Poklic</th><th>Ekipa</th><th>Kategorija</th><th>Štartna št.</th><th>Čas</th></tr>");
                int c = 1;
                for (int i = 0; i < sep[s].rowCount(); i++) {
                    qDebug() <<kategorijeItems[kat]<<" => "<< s <<sep[s].item(i,4)->text().toInt();
                    if (sep[s].item(i,4)->text().toInt() == kategorijeItems[kat]) {
                        htmlCode.append("<tr>");
                        htmlCode.append("<td>").append(QString::number(c)).append("</td>");
                        c++;
                        for (int j = 0; j < sep[s].columnCount(); j++) {
                            if (j == 3) continue;
                            if (j == 6) {
                                htmlCode.append("<td>");
                                if(sep[s].item(i,order[j]) ->text() == "") htmlCode.append("DNF");
                                else htmlCode.append(sep[s].item(i,order[j])->text());
                                htmlCode.append("</td>");
                                continue;
                            }

                            htmlCode.append("<td>");
                            htmlCode.append(sep[s].item(i,order[j])->text());
                            //qDebug() << sep[s].item(i,order[j])->text();
                            htmlCode.append("</td>");
                        }
                        htmlCode.append("</tr>");
                    }
                }
                htmlCode.append("</table><br/>");
            }
        }
    }

    htmlCode.append("</body></html>");
    if (file.open(QFile::WriteOnly | QFile::Truncate)) data << htmlCode;
    file.close();
    qDebug() << htmlCode;

    ui->textBrowser->setSource(QUrl("sample1.html"));

}
