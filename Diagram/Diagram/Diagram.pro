#-------------------------------------------------
#
# Project created by QtCreator 2019-12-23T16:10:07
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Diagram
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    link.cpp \
    node.cpp \
    propertiesdialog.cpp

HEADERS  += mainwindow.h \
    link.h \
    node.h \
    propertiesdialog.h

FORMS    += \
    propertiesdialog.ui
