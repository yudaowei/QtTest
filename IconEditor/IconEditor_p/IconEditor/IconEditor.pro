CONFIG      += designer plugin debug_and_release
TARGET      = $$qtLibraryTarget(Iconeditorplugin)
TEMPLATE    = lib

HEADERS     = iconeditorplugin.h
SOURCES     = iconeditorplugin.cpp
RESOURCES   = icons.qrc
LIBS        += -L. 

DESTDIR = $$[QT_INSTALL_PLUGINS]/designer
INSTALLS    += target

include(iconeditor.pri)
