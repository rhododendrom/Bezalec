#-------------------------------------------------
#
# Project created by QtCreator 2017-03-15T10:02:52
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = testTable
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    kategorijaedit.cpp \
    izpispodatkov.cpp

HEADERS  += mainwindow.h \
    kategorijaedit.h \
    izpispodatkov.h

FORMS    += mainwindow.ui \
    kategorijaedit.ui \
    izpispodatkov.ui
CONFIG += c++11
