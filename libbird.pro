# -------------------------------------------------
# -------------------------------------------------
QT += core \
    gui \
    sql
TARGET = Books
TEMPLATE = app
SOURCES += main.cpp \
    Books.cpp \
    newbook.cpp \
    finddlg.cpp
HEADERS += \
    Books.h \
    newbook.h \
    finddlg.h
FORMS += \
    Books.ui \
    newbook.ui \
    finddlg.ui
CONFIG += mobility
MOBILITY = 
