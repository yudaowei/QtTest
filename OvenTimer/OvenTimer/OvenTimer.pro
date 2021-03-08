#-------------------------------------------------
#
# Project created by QtCreator 2019-12-21T11:38:59
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = OvenTimer
TEMPLATE = app
CONFIG += C++11

SOURCES += main.cpp\
        mainwindow.cpp \
    oventimer.cpp \
    paintlabel.cpp

HEADERS  += mainwindow.h \
    oventimer.h \
    paintlabel.h

FORMS    += mainwindow.ui
