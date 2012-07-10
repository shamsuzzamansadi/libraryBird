# -------------------------------------------------
# -------------------------------------------------
QT += core \
    gui \
    sql
TARGET = Books
TEMPLATE = app
SOURCES += main.cpp \
    Books.cpp \
    newbook.cpp
HEADERS += \
    Books.h \
    newbook.h
FORMS += \
    Books.ui \
    newbook.ui
CONFIG += mobility
MOBILITY = 

