#-------------------------------------------------
#
# Project created by QtCreator 2018-04-08T00:21:29
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = KnightsTourAnimation
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    knightstour.cpp

HEADERS  += mainwindow.h \
    knightstour.h \
    mystack.h

FORMS    += mainwindow.ui

QT += testlib
