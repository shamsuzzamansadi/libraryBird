/********************************************************************************
** Form generated from reading UI file 'newbook.ui'
**
** Created: Thu Jul 12 22:36:37 2012
**      by: Qt User Interface Compiler version 4.7.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_NEWBOOK_H
#define UI_NEWBOOK_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QDialogButtonBox>
#include <QtGui/QGridLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QSpacerItem>

QT_BEGIN_NAMESPACE

class Ui_NewBook
{
public:
    QGridLayout *gridLayout;
    QLabel *nameLabel;
    QLineEdit *nameEdit;
    QLabel *authorLabel;
    QLineEdit *authorEdit;
    QLabel *isbnLabel;
    QLineEdit *isbnEdit;
    QLabel *quantityLabel;
    QLineEdit *quantityEdit;
    QLabel *availableLabel;
    QLineEdit *availableEdit;
    QLabel *studentidlabel;
    QLineEdit *studentidEdit;
    QDialogButtonBox *buttonBox;
    QSpacerItem *verticalSpacer;

    void setupUi(QDialog *NewBook)
    {
        if (NewBook->objectName().isEmpty())
            NewBook->setObjectName(QString::fromUtf8("NewBook"));
        NewBook->resize(431, 548);
        gridLayout = new QGridLayout(NewBook);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        nameLabel = new QLabel(NewBook);
        nameLabel->setObjectName(QString::fromUtf8("nameLabel"));

        gridLayout->addWidget(nameLabel, 0, 0, 1, 1);

        nameEdit = new QLineEdit(NewBook);
        nameEdit->setObjectName(QString::fromUtf8("nameEdit"));

        gridLayout->addWidget(nameEdit, 1, 0, 1, 1);

        authorLabel = new QLabel(NewBook);
        authorLabel->setObjectName(QString::fromUtf8("authorLabel"));

        gridLayout->addWidget(authorLabel, 2, 0, 1, 1);

        authorEdit = new QLineEdit(NewBook);
        authorEdit->setObjectName(QString::fromUtf8("authorEdit"));

        gridLayout->addWidget(authorEdit, 3, 0, 1, 1);

        isbnLabel = new QLabel(NewBook);
        isbnLabel->setObjectName(QString::fromUtf8("isbnLabel"));

        gridLayout->addWidget(isbnLabel, 4, 0, 1, 1);

        isbnEdit = new QLineEdit(NewBook);
        isbnEdit->setObjectName(QString::fromUtf8("isbnEdit"));

        gridLayout->addWidget(isbnEdit, 5, 0, 1, 1);

        quantityLabel = new QLabel(NewBook);
        quantityLabel->setObjectName(QString::fromUtf8("quantityLabel"));

        gridLayout->addWidget(quantityLabel, 6, 0, 1, 1);

        quantityEdit = new QLineEdit(NewBook);
        quantityEdit->setObjectName(QString::fromUtf8("quantityEdit"));

        gridLayout->addWidget(quantityEdit, 7, 0, 1, 1);

        availableLabel = new QLabel(NewBook);
        availableLabel->setObjectName(QString::fromUtf8("availableLabel"));

        gridLayout->addWidget(availableLabel, 8, 0, 1, 1);

        availableEdit = new QLineEdit(NewBook);
        availableEdit->setObjectName(QString::fromUtf8("availableEdit"));

        gridLayout->addWidget(availableEdit, 9, 0, 1, 1);

        studentidlabel = new QLabel(NewBook);
        studentidlabel->setObjectName(QString::fromUtf8("studentidlabel"));

        gridLayout->addWidget(studentidlabel, 10, 0, 1, 1);

        studentidEdit = new QLineEdit(NewBook);
        studentidEdit->setObjectName(QString::fromUtf8("studentidEdit"));

        gridLayout->addWidget(studentidEdit, 12, 0, 1, 1);

        buttonBox = new QDialogButtonBox(NewBook);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        gridLayout->addWidget(buttonBox, 14, 0, 1, 1);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer, 13, 0, 1, 1);


        retranslateUi(NewBook);
        QObject::connect(buttonBox, SIGNAL(accepted()), NewBook, SLOT(accept()));

        QMetaObject::connectSlotsByName(NewBook);
    } // setupUi

    void retranslateUi(QDialog *NewBook)
    {
        NewBook->setWindowTitle(QApplication::translate("NewBook", "New Book", 0, QApplication::UnicodeUTF8));
        nameLabel->setText(QApplication::translate("NewBook", "Name:", 0, QApplication::UnicodeUTF8));
        authorLabel->setText(QApplication::translate("NewBook", "Author:", 0, QApplication::UnicodeUTF8));
        isbnLabel->setText(QApplication::translate("NewBook", "ISBN:", 0, QApplication::UnicodeUTF8));
        quantityLabel->setText(QApplication::translate("NewBook", "Quantity:", 0, QApplication::UnicodeUTF8));
        availableLabel->setText(QApplication::translate("NewBook", "Available:", 0, QApplication::UnicodeUTF8));
        studentidlabel->setText(QApplication::translate("NewBook", "Taken By(Student ID):", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class NewBook: public Ui_NewBook {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NEWBOOK_H
