#include <QtGlobal>
#include <QSqlDatabase>
#include <QSqlTableModel>
 #include <QSqlQueryModel>
#include <QSqlQuery>
#include <QMessageBox>
#include <QSqlRecord>
#include <QDir>
#include "Books.h"
#include "ui_Books.h"
#include "newbook.h"
#include "finddlg.h"
Books::Books(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Books)
{
    ui->setupUi(this);
    QString filename = QDir::homePath() + QDir::separator() + "books.db";
    if(!setupDb(filename))
    {
        QMessageBox::critical(this,
                              tr("Database not found"),
                              tr("Database not found. The application will be closed."),
                              QMessageBox::Ok);
        qApp->exit();
    }
}

bool Books::setupDb(QString dbname)
{
    QTreeView *view = ui->treeView;

    Q_ASSERT(dbname.length()>0);
    Q_CHECK_PTR(view);

    // using MYSQL driver
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName(dbname);
    //db.setHostName("localhost");
       // db.setUserName("root");
        //db.setPassword("fcukoff");


    if(db.open())
    {
        // Try to locate the books database.
        // If it is not available create it.
        bool found = false;
        foreach (QString table, db.tables())
        {
            if(table == "books")
            {
                found = true;
                break;
            }
        }
        if(!found)
        {
            QSqlQuery query(db);
            query.exec("CREATE TABLE Books (name VARCHAR(32), author VARCHAR(16),isbn VARCHAR(32),quantity VARCHAR(16),available VARCHAR(16),studentid VARCHAR(16))");
        }
        // create a new model and use the books table
        model = new QSqlTableModel(this,db);
        model->setTable("Books");
        // All changes to the model will be applied immediately to the database
        model->setEditStrategy(QSqlTableModel::OnFieldChange);
        model->select();
        // creating the model/view association
        view->setModel(model);

    }
    else
        return false;

    return true;
}

Books::~Books()
{
    delete ui;
}

void Books::changeEvent(QEvent *e)
{
    QMainWindow::changeEvent(e);
    switch (e->type()) {
    case QEvent::LanguageChange:
        ui->retranslateUi(this);
        break;
    default:
        break;
    }
}

void Books::on_actionNew_triggered()
{
    // Create a new empty dialog and show it using exec()
    NewBook dlg(this);
    dlg.resetName();
    dlg.resetAuthor();
    dlg.resetIsbn();
    dlg.resetQuantity();
    dlg.resetAvailable();
    dlg.resetStudentid();

    if(dlg.exec() == QDialog::Accepted && dlg.name().length() > 0 )
    {
        // create a record from the current model
        QSqlRecord rec = model->record();
        rec.setValue("name",dlg.name());
        rec.setValue("author",dlg.author());
        rec.setValue("isbn",dlg.isbn());
        rec.setValue("quantity",dlg.quantity());
        rec.setValue("available",dlg.available());
        rec.setValue("studentid",dlg.studentid());
        // insert a new record (-1)
        model->insertRecord(-1,rec);
    }
}

void Books::on_actionEdit_triggered()
{
    // get the current index, if any
    QModelIndex sample = ui->treeView->currentIndex();
    if( sample.row() >= 0 )
    {
        // copy the current record
        QSqlRecord rec = model->record(sample.row());
        NewBook dlg(this);
        dlg.setName(rec.value("name").toString());
        dlg.setAuthor(rec.value("author").toString());
        dlg.setIsbn(rec.value("isbn").toString());
        dlg.setQuantity(rec.value("quantity").toString());
        dlg.setAvailable(rec.value("available").toString());
        dlg.setStudentid(rec.value("studentid").toString());

        if(dlg.exec() == QDialog::Accepted)
        {
            rec.setValue("name",dlg.name());
            rec.setValue("author",dlg.author());
            rec.setValue("isbn",dlg.isbn());
            rec.setValue("quantity",dlg.quantity());
            rec.setValue("available",dlg.available());
            rec.setValue("studentid",dlg.studentid());
            // save modified data
            model->setRecord(sample.row(),rec);
        }
    }
}

void Books::on_actionDelete_triggered()
{
    // get the current index, if any
    QModelIndex sample = ui->treeView->currentIndex();
    if( sample.row() >= 0 )
    {
        QMessageBox::StandardButton dlg;
        dlg = QMessageBox::question(this, tr("Remove Book"),
                                    QString(tr("Remove Book ?")),
                                    QMessageBox::Yes | QMessageBox::No);

        if(dlg == QMessageBox::Yes)
        {
            // remove the current index
            model->removeRow(sample.row());
        }
    }
}
void Books::on_actionQuit_triggered()
{
    close();
}

void Books::on_actionFind_triggered()
{
   finddlg fndl(this);
   if (fndl.exec() == QDialog::Accepted)
   {
       QString sc = fndl.searchtext();
       QString st = fndl.searchfield();

       QTreeView *view = ui->treeView;



           // create a new model and use the books table
           QSqlQueryModel *sqlmodel = new QSqlQueryModel;
           QString sqlq = "select * from books where ";
           sqlq.append(st);
           sqlq.append(" LIKE '%");
           sqlq.append(sc);
           sqlq.append("%'");
        //   qDebug(sqlq.toUtf8().constData());
           sqlmodel->setQuery(sqlq);

           view->setModel(sqlmodel);








   }

}

void Books::on_actionReset_triggered()
{
    QString filename = QDir::homePath() + QDir::separator() + "books.db";
    setupDb(filename);

}
