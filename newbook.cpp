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
void NewBook::setIsbn(const QString i)
{
    ui->isbnEdit->setText(i);
}

QString NewBook::isbn() const
{
    return  ui->isbnEdit->text();
}

void NewBook::resetIsbn()
{
    setIsbn(tr(""));
}
void NewBook::setQuantity(const QString q)
{
    ui->quantityEdit->setText(q);
}

QString NewBook::quantity() const
{
    return  ui->quantityEdit->text();
}

void NewBook::resetQuantity()
{
    setQuantity(tr(""));
}
void NewBook::setAvailable(const QString a)
{
    ui->availableEdit->setText(a);
}

QString NewBook::available() const
{
    return  ui->availableEdit->text();
}

void NewBook::resetAvailable()
{
    setAvailable(tr(""));
}
void NewBook::setStudentid(const QString s)
{
    ui->studentidEdit->setText(s);
}

QString NewBook::studentid() const
{
    return  ui->studentidEdit->text();
}

void NewBook::resetStudentid()
{
    setStudentid(tr(""));
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
    setIsbn(ui->isbnEdit->text());
    setQuantity(ui->quantityEdit->text());
    setAvailable(ui->availableEdit->text());
    setStudentid(ui->studentidEdit->text());
}
