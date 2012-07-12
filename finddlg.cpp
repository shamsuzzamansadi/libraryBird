#include "finddlg.h"
#include "ui_finddlg.h"

finddlg::finddlg(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::finddlg)
{
    ui->setupUi(this);
}

finddlg::~finddlg()
{
    delete ui;
}

QString finddlg::searchfield() const
{
    switch (ui->comboBox->currentIndex())
    {
    case 0:
        return QString("name");
        break;
    case 1:
        return QString("author");
        break;
    case 2:
        return QString("isbn");
        break;
    case 3:
        return QString("quantity");
        break;
    case 4:
        return QString("available");
        break;
    case 5:
        return QString("studentid");
        break;

    }
}
QString finddlg::searchtext() const
{
    return ui->lineEdit->text();
}

void finddlg::on_pushButton_2_clicked()
{
    this->accept();
    this->close();
}

void finddlg::on_pushButton_clicked()
{
    this->reject();
    this->close();
}
