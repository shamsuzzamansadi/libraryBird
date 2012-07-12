/********************************************************************************
** Form generated from reading UI file 'Books.ui'
**
** Created: Fri Jul 13 00:04:38 2012
**      by: Qt User Interface Compiler version 4.7.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BOOKS_H
#define UI_BOOKS_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QGridLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QMainWindow>
#include <QtGui/QMenu>
#include <QtGui/QMenuBar>
#include <QtGui/QTreeView>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Books
{
public:
    QAction *actionNew;
    QAction *actionEdit;
    QAction *actionDelete;
    QAction *actionQuit;
    QAction *actionFind;
    QAction *actionReset;
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    QTreeView *treeView;
    QMenuBar *menuBar;
    QMenu *menuEdit;
    QMenu *menuSearch;

    void setupUi(QMainWindow *Books)
    {
        if (Books->objectName().isEmpty())
            Books->setObjectName(QString::fromUtf8("Books"));
        Books->resize(800, 480);
        actionNew = new QAction(Books);
        actionNew->setObjectName(QString::fromUtf8("actionNew"));
        actionEdit = new QAction(Books);
        actionEdit->setObjectName(QString::fromUtf8("actionEdit"));
        actionDelete = new QAction(Books);
        actionDelete->setObjectName(QString::fromUtf8("actionDelete"));
        actionQuit = new QAction(Books);
        actionQuit->setObjectName(QString::fromUtf8("actionQuit"));
        actionFind = new QAction(Books);
        actionFind->setObjectName(QString::fromUtf8("actionFind"));
        actionReset = new QAction(Books);
        actionReset->setObjectName(QString::fromUtf8("actionReset"));
        centralWidget = new QWidget(Books);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        treeView = new QTreeView(centralWidget);
        treeView->setObjectName(QString::fromUtf8("treeView"));

        gridLayout->addWidget(treeView, 0, 0, 1, 1);

        Books->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(Books);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 800, 22));
        menuEdit = new QMenu(menuBar);
        menuEdit->setObjectName(QString::fromUtf8("menuEdit"));
        menuSearch = new QMenu(menuBar);
        menuSearch->setObjectName(QString::fromUtf8("menuSearch"));
        Books->setMenuBar(menuBar);

        menuBar->addAction(menuEdit->menuAction());
        menuBar->addAction(menuSearch->menuAction());
        menuEdit->addAction(actionNew);
        menuEdit->addAction(actionEdit);
        menuEdit->addAction(actionDelete);
        menuEdit->addAction(actionQuit);
        menuSearch->addAction(actionFind);
        menuSearch->addAction(actionReset);

        retranslateUi(Books);

        QMetaObject::connectSlotsByName(Books);
    } // setupUi

    void retranslateUi(QMainWindow *Books)
    {
        Books->setWindowTitle(QApplication::translate("Books", "Books", 0, QApplication::UnicodeUTF8));
        actionNew->setText(QApplication::translate("Books", "New", 0, QApplication::UnicodeUTF8));
        actionEdit->setText(QApplication::translate("Books", "Edit", 0, QApplication::UnicodeUTF8));
        actionDelete->setText(QApplication::translate("Books", "Delete", 0, QApplication::UnicodeUTF8));
        actionQuit->setText(QApplication::translate("Books", "Quit", 0, QApplication::UnicodeUTF8));
        actionFind->setText(QApplication::translate("Books", "Find", 0, QApplication::UnicodeUTF8));
        actionReset->setText(QApplication::translate("Books", "Reset", 0, QApplication::UnicodeUTF8));
        menuEdit->setTitle(QApplication::translate("Books", "Edit", 0, QApplication::UnicodeUTF8));
        menuSearch->setTitle(QApplication::translate("Books", "Search", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class Books: public Ui_Books {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BOOKS_H
