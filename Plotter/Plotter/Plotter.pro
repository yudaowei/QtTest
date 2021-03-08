#-------------------------------------------------
#
# Project created by QtCreator 2019-12-05T10:28:22
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Plotter
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    plotter.cpp \
    plotsettings.cpp

HEADERS  += mainwindow.h \
    plotter.h \
    plotsettings.h

FORMS    += mainwindow.ui
