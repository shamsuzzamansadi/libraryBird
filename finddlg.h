#ifndef FINDDLG_H
#define FINDDLG_H

#include <QDialog>

namespace Ui {
    class finddlg;
}

class finddlg : public QDialog
{
    Q_OBJECT
    Q_PROPERTY(QString searchtext READ searchtext);
    Q_PROPERTY(QString searchfield READ searchfield);


public:
    explicit finddlg(QWidget *parent = 0);
    ~finddlg();
    QString searchtext() const;
    QString searchfield() const;

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

private:
    Ui::finddlg *ui;
};

#endif // FINDDLG_H
