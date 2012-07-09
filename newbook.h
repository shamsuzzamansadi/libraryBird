#ifndef NEWBOOK_H
#define NEWBOOK_H

#include <QDialog>

namespace Ui {
    class NewBook;
}

class NewBook : public QDialog {
    Q_OBJECT
    Q_PROPERTY(QString name READ name WRITE setName RESET resetName)
    Q_PROPERTY(QString author READ author WRITE setAuthor RESET resetAuthor)

public:
    NewBook(QWidget *parent = 0);
    ~NewBook();
    void setName(const QString n);
    QString name() const;
    void resetName();

    void setAuthor(const QString p);
    QString Author() const;
    void resetAuthor();

protected:
    void changeEvent(QEvent *e);

private:
    Ui::NewBook *ui;

private slots:
    void on_buttonBox_accepted();
};

#endif // NEWBOOK_H
