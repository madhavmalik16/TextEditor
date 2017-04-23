#-------------------------------------------------
#
# Project created by QtCreator 2017-04-13T14:06:38
#
#-------------------------------------------------

QT       += core gui printsupport concurrent widgets

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = TextEditor
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    font.cpp \
    dialog.cpp

HEADERS  += mainwindow.h \
    font.h \
    dialog.h

FORMS    += mainwindow.ui \
    font.ui \
    dialog.ui
