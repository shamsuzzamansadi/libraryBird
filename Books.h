#ifndef BOOKS_H
#define BOOKS_H

#include <QMainWindow>
#include <QSqlTableModel>
#include <QSqlDatabase>

namespace Ui {
    class Books;
}

class Books : public QMainWindow
{
    Q_OBJECT

public:
    explicit Books(QWidget *parent = 0);
    ~Books();

protected:
    void changeEvent(QEvent *e);

private:
    Ui::Books *ui;
    QSqlTableModel *model;
    QSqlDatabase db;

    bool setupDb(QString dbname);

private slots:
    void on_actionDelete_triggered();
    void on_actionEdit_triggered();
    void on_actionNew_triggered();
    void on_actionQuit_triggered();
    void on_actionFind_triggered();
    void on_actionReset_triggered();
};

#endif // BOOKS_H
