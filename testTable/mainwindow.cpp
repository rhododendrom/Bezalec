#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <iostream>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->actionOdpri,SIGNAL(triggered()),this,SLOT(onActionOdpriFile()));
    connect(ui->actionShrani,SIGNAL(triggered()),this,SLOT(onActionShraniFile()));
    connect(ui->actionKategorije,SIGNAL(triggered()),this,SLOT(onActionKategorije()));
    connect(ui->actionPripravi_izpis,SIGNAL(triggered()),this,SLOT(onActionIzpisPodatkov()));

    inputData();
    populateCategories();

}




MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButtonReg_clicked()
{
    /*if (ui->lineEditRegIme->text().isEmpty() || ui->lineEditRegKlub->text().isEmpty() ||
            ui->comboBoxRegKat->currentIndex() < 0 || ui->comboBoxRegSpol->currentIndex() < 0)
    {
        std::cout << "Napaka pri vnosu" << std::endl;
        return;
    }*/
    int numRows = ui->tableWidgetRegVnos->rowCount(); //Prešteje število vrstic v kodi

    QString startnaStevilka = ui->lineEditRegNumber->text();
    QString imeTekmovalca = ui->lineEditRegIme->text();
    QString poklicTekmovalca = "Test";//ui->lineEditRegPoklic->text();
    QString klubTekmovalca = ui->lineEditRegKlub->text();
    QString kategorijaTekmovalca = ui->comboBoxRegKat->currentText();
    QString spolTekmovalca = ui->comboBoxRegSpol->currentText();

    Tekmovalec tekmovalec(startnaStevilka.toInt(),imeTekmovalca,poklicTekmovalca,klubTekmovalca,kategorijaTekmovalca.toInt(),spolTekmovalca,"");
    insertOneRow(numRows,tekmovalec);

    //now clear everything
    ui->lineEditRegNumber->setText("");
    ui->lineEditRegIme->setText("");
    ui->lineEditRegKlub->setText("");
    ui->comboBoxRegKat->setCurrentIndex(-1);
    ui->comboBoxRegSpol->setCurrentIndex(-1);

}

void MainWindow::onActionOdpriFile()
{
    QString data;
    QFile importedCSV("name.txt");
    QStringList rowOfData;
    QStringList rowData;
    if (importedCSV.open(QFile::ReadOnly)){
        data = importedCSV.readAll();
        rowOfData = data.split("\n");
        importedCSV.close();
    }

    ui->tableWidgetCompVnos->setRowCount(0);
    ui->tableWidgetRegVnos->setRowCount(0);
    //TODO PREVERI ZADNJO VRSTICO V FILE-U!!!!!!!!!!!!!
    for (int x = 1; x < rowOfData.size()-1; x++)  //rowOfData.size() gives the number of row
    {
        int numRows = ui->tableWidgetRegVnos->rowCount();
        rowData = rowOfData.at(x).split(";");
        Tekmovalec tekmovalec(rowData);
        std::cout << tekmovalec.casTekmovalca.toStdString()<<std::endl;
        qDebug() << rowData;
        insertOneRow(numRows,tekmovalec);

    }
    statusBar()->showMessage(tr("File successfully loaded."), 3000);



}

void MainWindow::populateCategories()
{
    katEdit = new KategorijaEdit();
    QStringList kategorije = katEdit->getKategorije();
    ui->comboBoxRegKat->addItems(kategorije);
}

void MainWindow::onActionKategorije()
{
    katEdit = new KategorijaEdit();
    katEdit->exec();

    QStringList kategorije = katEdit->getKategorije();
    int numOfItems = ui->comboBoxRegKat->count();
    while (numOfItems > 0)
    {
        ui->comboBoxRegKat->removeItem(0);
        numOfItems--;
    }
    kategorijeFullDesc = kategorije;
    for (int i = 0; i < kategorije.count(); i++) {
        QString katName = kategorije[i].split(";")[0];
        kategorije[i] = katName;
    }
    ui->comboBoxRegKat->addItems(kategorije);

}

void MainWindow::onActionIzpisPodatkov()
{
    qDebug() << "test";
    izpis = new Izpispodatkov(this);
    izpis->show();
}

void MainWindow::onActionShraniFile()
{
    QFile file("name.txt");

    QTextStream data( &file );
    if (file.open(QFile::WriteOnly | QFile::Truncate))
    {
        QStringList strList;
        for( int c = 0; c < ui->tableWidgetCompVnos->columnCount()-1; ++c ){
                qDebug() << c;
                strList <<  ui->tableWidgetCompVnos->horizontalHeaderItem(c)->data(Qt::DisplayRole).toString() ;
                qDebug() << strList;
        }
        data << strList.join(";") << "\n";



        for (int i = 0; i < ui->tableWidgetCompVnos->rowCount(); i++) {
            strList.clear();
            if (ui->tableWidgetCompVnos->isRowHidden(i)) continue;

            for (int j = 0; j < ui->tableWidgetCompVnos->columnCount(); j++) {
                QTableWidgetItem* checkVnos = ui->tableWidgetCompVnos->item(i,j);
                if(!checkVnos || checkVnos->text().isEmpty()){
                    qDebug() << "Empty??"<<j;
                    if (j == 6) strList.append("hh:mm:ss");
                }

                else {
                    //qDebug() << "Nisem prazen zapiši me v file";
                    strList << ui->tableWidgetCompVnos->item( i, j )->text();
                    //qDebug() << ui->tableWidgetCompVnos->item( i, j )->text();
                }
            }

            data << strList.join( ";" )+"\n";

        }
        //qDebug() << "End Shrani File";
    }
    statusBar()->showMessage(tr("File saved successfully."), 3000);
    file.close();

}
void MainWindow::pushRemoveEntry(int row)
{
    std::cout<<row<<std::endl;
    ui->tableWidgetRegVnos->hideRow(row);
    ui->tableWidgetCompVnos->hideRow(row);
}


void MainWindow::inputData()
{

    QString imena[10] = {"tekmovalec1","tekmovalec2","tekmovalec3","tekmovalec4","tekmovalec5","tekmovalec6","tekmovalec7","tekmovalec8","tekmovalec9",
                        "tekmovalec10"};

    QString poklic[10] = {"zdravnik","tehnik","zdravnik","zdravnik","tehnik","policaj","zdravnik","tehnik","zdravnik",
                        "gasilec"};

    QString klub[10] = {"klub1","klub2","klub1","klub3","klub4","klub2","klub2","klub1","klub5",
                        "klub7"};

    int kategorije[10] = {1,2,1,1,1,2,2,1,1,2};

    QString spol[10] = {"moški","ženski","moški","moški","ženski","ženski","moški","moški","ženski",
                        "ženski"};



    for (int i = 0; i < 10; i++) {
        Tekmovalec tekmovalec(i+1,imena[i],poklic[i],klub[i],kategorije[i],spol[i],"");
        int numRows = ui->tableWidgetRegVnos->rowCount();
        insertOneRow(numRows,tekmovalec);
    }
}


void MainWindow::insertOneRow(int numRows,Tekmovalec tekmovalec)
{
    ui->tableWidgetRegVnos->insertRow( numRows );
    ui->tableWidgetCompVnos->insertRow( numRows );

    ui->tableWidgetRegVnos->setItem(numRows, 0, new TableIntItem(tekmovalec.startnaStevilka));
    ui->tableWidgetRegVnos->setItem(numRows, 1, new QTableWidgetItem(tekmovalec.imeTekmovalca));
    ui->tableWidgetRegVnos->setItem(numRows, 2, new QTableWidgetItem(tekmovalec.poklicTekmovalca));
    ui->tableWidgetRegVnos->setItem(numRows, 3, new QTableWidgetItem(tekmovalec.klubTekmovalca));
    ui->tableWidgetRegVnos->setItem(numRows, 4, new TableIntItem(tekmovalec.katergorijaTekmovalca));
    ui->tableWidgetRegVnos->setItem(numRows, 5, new QTableWidgetItem(tekmovalec.spolTekmovalca));


    ui->tableWidgetCompVnos->setItem(numRows, 0, new TableIntItem(tekmovalec.startnaStevilka));
    ui->tableWidgetCompVnos->setItem(numRows, 1, new QTableWidgetItem(tekmovalec.imeTekmovalca));
    ui->tableWidgetCompVnos->setItem(numRows, 2, new QTableWidgetItem(tekmovalec.poklicTekmovalca));
    ui->tableWidgetCompVnos->setItem(numRows, 3, new QTableWidgetItem(tekmovalec.klubTekmovalca));
    ui->tableWidgetCompVnos->setItem(numRows, 4, new TableIntItem(tekmovalec.katergorijaTekmovalca));
    ui->tableWidgetCompVnos->setItem(numRows, 5, new QTableWidgetItem(tekmovalec.spolTekmovalca));
    ui->tableWidgetCompVnos->setItem(numRows, 6, new TableDateItem(tekmovalec.casTekmovalca));




    QWidget* pWidget = new QWidget();

    QPushButton* btn_edit = new QPushButton();
    btn_edit->setText("Briši");
    QHBoxLayout* pLayout = new QHBoxLayout(pWidget);
    pLayout->addWidget(btn_edit);
    pLayout->setAlignment(Qt::AlignCenter);
    pLayout->setContentsMargins(0, 0, 0, 0);
    pWidget->setLayout(pLayout);


    QWidget* pWidget2 = new QWidget();

    QPushButton* btn_edit2 = new QPushButton();
    btn_edit2->setText("Briši");
    QHBoxLayout* pLayout2 = new QHBoxLayout(pWidget2);
    pLayout2->addWidget(btn_edit2);
    pLayout2->setAlignment(Qt::AlignCenter);
    pLayout2->setContentsMargins(0, 0, 0, 0);
    pWidget2->setLayout(pLayout2);

    ui->tableWidgetRegVnos->setCellWidget(numRows, 6, pWidget);
    ui->tableWidgetCompVnos->setCellWidget(numRows, 7, pWidget2);
    QSignalMapper* signalMapper = new QSignalMapper(this);

    connect(btn_edit, SIGNAL(clicked()), signalMapper, SLOT(map()));
    connect(btn_edit2, SIGNAL(clicked()), signalMapper, SLOT(map()));
    signalMapper->setMapping(btn_edit,numRows);
    signalMapper->setMapping(btn_edit2,numRows);
    connect(signalMapper, SIGNAL(mapped(int)), this, SLOT(pushRemoveEntry(int)));
}





void MainWindow::on_pushButtonComp_clicked()
{
    QString cas = ui->lineEditCompCas->text();
    int stTekmovalec = ui->lineEditCompStartna->text().toInt();
    qDebug() << cas << " "<<stTekmovalec;
    int pos = -1;
    for (int i = 0; i < ui->tableWidgetCompVnos->rowCount(); i++) {
        if (ui->tableWidgetCompVnos->item(i,0)->text().toInt() == stTekmovalec) {
            qDebug() << "Našel sem ga na pos "<< i ;
            pos = i;
            break;
        }
    }
    ui->tableWidgetCompVnos->setItem(pos, 6, new TableDateItem(cas));
    ui->lineEditCompCas->setText("");
    ui->lineEditCompStartna->setText("");
}
