QT += core gui widgets network

TARGET = BooksApp
TEMPLATE = app

SOURCES += main.cpp \
           secwindow.cpp \
           tablemodel.cpp

HEADERS += secwindow.h \
           tablemodel.h \
           supplementary.h

FORMS += secwindow.ui
