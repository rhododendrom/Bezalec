#include "kategorijaedit.h"
#include "ui_kategorijaedit.h"

KategorijaEdit::KategorijaEdit(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::KategorijaEdit)
{
    ui->setupUi(this);
    loadKategorije();

}

KategorijaEdit::~KategorijaEdit()
{
    delete ui;
}

void KategorijaEdit::loadKategorije()
{
    QString data;
    QFile importedCSV("data/kategorije.txt");
    QStringList rowOfData;
    QStringList rowDataFull;
    if (importedCSV.open(QFile::ReadOnly)){
        data = importedCSV.readAll();
        rowOfData = data.split("\n");
        importedCSV.close();
    }
    qDebug() << "rowOfData"<<rowOfData;
    for (int x = 0; x < rowOfData.size(); x++)
    {
        rowDataFull = rowOfData.at(x).split(";");

        qDebug() << rowDataFull[0];
        qDebug() << rowDataFull[1];
        ui->textEdit->append(rowDataFull[0]+";"+rowDataFull[1]);

        lines.append(rowDataFull[0]);
    }
    //lines = rowOfData;


}
QStringList KategorijaEdit::getKategorije()
{
    return lines;
}

void KategorijaEdit::on_buttonBox_accepted()
{
    //napolni prejšnje podatke
    qDebug() << "Shrani textedit v file, Bom probal napolnit";
    QFile file("data/kategorije.txt");
    QTextStream data( &file );
    QString plainTextEditContents = ui->textEdit->toPlainText();
    lines = plainTextEditContents.split("\n");
    qDebug() << lines;

    if (file.open(QFile::WriteOnly | QFile::Truncate))
    {
        data << lines.join("\n");
    }
    file.close();



}
