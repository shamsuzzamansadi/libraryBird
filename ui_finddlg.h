/********************************************************************************
** Form generated from reading UI file 'finddlg.ui'
**
** Created: Thu Jul 12 23:35:12 2012
**      by: Qt User Interface Compiler version 4.7.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FINDDLG_H
#define UI_FINDDLG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QComboBox>
#include <QtGui/QDialog>
#include <QtGui/QHeaderView>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_finddlg
{
public:
    QLineEdit *lineEdit;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QComboBox *comboBox;

    void setupUi(QDialog *finddlg)
    {
        if (finddlg->objectName().isEmpty())
            finddlg->setObjectName(QString::fromUtf8("finddlg"));
        finddlg->resize(400, 86);
        lineEdit = new QLineEdit(finddlg);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(10, 10, 381, 31));
        pushButton = new QPushButton(finddlg);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(280, 50, 114, 32));
        pushButton_2 = new QPushButton(finddlg);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(160, 50, 114, 32));
        comboBox = new QComboBox(finddlg);
        comboBox->setObjectName(QString::fromUtf8("comboBox"));
        comboBox->setGeometry(QRect(10, 50, 111, 26));

        retranslateUi(finddlg);

        QMetaObject::connectSlotsByName(finddlg);
    } // setupUi

    void retranslateUi(QDialog *finddlg)
    {
        finddlg->setWindowTitle(QApplication::translate("finddlg", "Dialog", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QApplication::translate("finddlg", "Cancel", 0, QApplication::UnicodeUTF8));
        pushButton_2->setText(QApplication::translate("finddlg", "Search", 0, QApplication::UnicodeUTF8));
        comboBox->clear();
        comboBox->insertItems(0, QStringList()
         << QApplication::translate("finddlg", "Name", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("finddlg", "Author", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("finddlg", "ISBN", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("finddlg", "Quantity", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("finddlg", "Available", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("finddlg", "Student ID", 0, QApplication::UnicodeUTF8)
        );
    } // retranslateUi

};

namespace Ui {
    class finddlg: public Ui_finddlg {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FINDDLG_H
