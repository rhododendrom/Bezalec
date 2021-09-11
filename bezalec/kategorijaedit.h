#ifndef KATEGORIJAEDIT_H
#define KATEGORIJAEDIT_H

#include <QDialog>
#include <QFile>
#include <QDebug>

namespace Ui {
class KategorijaEdit;
}

class KategorijaEdit : public QDialog
{
    Q_OBJECT

public:
    explicit KategorijaEdit(QWidget *parent = 0);
    ~KategorijaEdit();
    QStringList getKategorije();


private slots:
    void on_buttonBox_accepted();

private:
    Ui::KategorijaEdit *ui;
    void loadKategorije();
    QStringList lines;
};

#endif // KATEGORIJAEDIT_H
