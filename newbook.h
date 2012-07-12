#ifndef NEWBOOK_H
#define NEWBOOK_H

#include <QDialog>
#include <QMessageBox>

namespace Ui {
    class NewBook;
}

class NewBook : public QDialog {
    Q_OBJECT
    Q_PROPERTY(QString name READ name WRITE setName RESET resetName)
    Q_PROPERTY(QString author READ author WRITE setAuthor RESET resetAuthor)
    Q_PROPERTY(QString isbn READ isbn WRITE setIsbn RESET resetIsbn)
    Q_PROPERTY(QString quantity READ quantity WRITE setQuantity RESET resetQuantity)
    Q_PROPERTY(QString available READ available WRITE setAvailable RESET resetAvailable)
    Q_PROPERTY(QString studentid READ studentid WRITE setStudentid RESET resetStudentid)
public:
    NewBook(QWidget *parent = 0);
    ~NewBook();
    void setName(const QString n);
    QString name() const;
    void resetName();

    void setAuthor(const QString p);
    QString author() const;
    void resetAuthor();

    void setIsbn(const QString i);
    QString isbn() const;
    void resetIsbn();

    void setQuantity(const QString q);
    QString quantity() const;
    void resetQuantity();

    void setAvailable(const QString a);
    QString available() const;
    void resetAvailable();

    void setStudentid(const QString s);
    QString studentid() const;
    void resetStudentid();



protected:
    void changeEvent(QEvent *e);
    void done(int r);
private:
    Ui::NewBook *ui;

private slots:
    void on_buttonBox_accepted();
    void on_buttonBox_rejected();
};

#endif // NEWBOOK_H
