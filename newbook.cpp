#include "newbook.h"
#include "ui_newbook.h"

NewBook::NewBook(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::NewBook)
{
    ui->setupUi(this);
}

NewBook::~NewBook()
{
    delete ui;
}

void NewBook::setName(const QString n)
{
    ui->nameEdit->setText(n);
}

QString NewBook::name() const
{
    return ui->nameEdit->text();
}

void NewBook::resetName()
{
    setName("");
};

void NewBook::setAuthor(const QString a)
{
    ui->authorEdit->setText(a);
}

QString NewBook::Author() const
{
    return  ui->authorEdit->text();
}

void NewBook::resetAuthor()
{
    setAuthor(tr(""));
}


void NewBook::changeEvent(QEvent *e)
{
    QDialog::changeEvent(e);
    switch (e->type()) {
    case QEvent::LanguageChange:
        ui->retranslateUi(this);
        break;
    default:
        break;
    }
}

void NewBook::on_buttonBox_accepted()
{
    setName(ui->nameEdit->text());
    setAuthor(ui->authorEdit->text());
}
