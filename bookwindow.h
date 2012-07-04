#ifndef BOOKWINDOW_H
 #define BOOKWINDOW_H

 #include <QtGui>
 #include <QtSql>

 #include "ui_bookwindow.h"

 class BookWindow: public QMainWindow
 {
     Q_OBJECT
 public:
     BookWindow();

 private:
     void showError(const QSqlError &err);
     Ui::BookWindow ui;
     QSqlRelationalTableModel *model;
     int authorIdx, genreIdx;
 };

 #endif
