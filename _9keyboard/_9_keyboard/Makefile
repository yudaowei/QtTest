#############################################################################
# Makefile for building: _9_keyboard
# Generated by qmake (2.01a) (Qt 4.8.7) on: ?? 12? 22 13:56:20 2020
# Project:  _9_keyboard.pro
# Template: app
# Command: /home/sanway/qt/build/qt4-arm/bin/qmake -o Makefile _9_keyboard.pro
#############################################################################

####### Compiler, tools and options

CC            = arm-arago-linux-gnueabi-gcc -lts
CXX           = arm-arago-linux-gnueabi-g++ -lts
DEFINES       = -DQT_NO_DEBUG -DQT_GUI_LIB -DQT_NETWORK_LIB -DQT_CORE_LIB -DQT_SHARED
CFLAGS        = -pipe -O2 -Wall -W -D_REENTRANT $(DEFINES)
CXXFLAGS      = -pipe -O2 -Wall -W -D_REENTRANT $(DEFINES)
INCPATH       = -I/home/sanway/qt/build/qt4-arm/mkspecs/qws/linux-arm-g++ -I. -I/home/sanway/qt/build/qt4-arm/include/QtCore -I/home/sanway/qt/build/qt4-arm/include/QtNetwork -I/home/sanway/qt/build/qt4-arm/include/QtGui -I/home/sanway/qt/build/qt4-arm/include -I. -I. -I/home/sanway/qt/build/tslib/include
LINK          = arm-arago-linux-gnueabi-g++ -lts
LFLAGS        = -Wl,-O1 -Wl,-rpath,/home/sanway/qt/build/qt4-arm/lib
LIBS          = $(SUBLIBS)  -L/home/sanway/qt/build/tslib/lib -L/home/sanway/qt/build/qt4-arm/lib -lQtGui -L/home/sanway/qt/build/tslib/lib/ -L/home/sanway/qt/build/qt4-arm/lib -L/home/sanway/qt/build/tslib/lib -lQtNetwork -lQtCore -lpthread 
AR            = arm-arago-linux-gnueabi-ar cqs
RANLIB        = 
QMAKE         = /home/sanway/qt/build/qt4-arm/bin/qmake
TAR           = tar -cf
COMPRESS      = gzip -9f
COPY          = cp -f
SED           = sed
COPY_FILE     = $(COPY)
COPY_DIR      = $(COPY) -r
STRIP         = arm-arago-linux-gnueabi-strip
INSTALL_FILE  = install -m 644 -p
INSTALL_DIR   = $(COPY_DIR)
INSTALL_PROGRAM = install -m 755 -p
DEL_FILE      = rm -f
SYMLINK       = ln -f -s
DEL_DIR       = rmdir
MOVE          = mv -f
CHK_DIR_EXISTS= test -d
MKDIR         = mkdir -p

####### Output directory

OBJECTS_DIR   = ./

####### Files

SOURCES       = main.cpp \
		mainwindow.cpp \
		mythread.cpp moc_mainwindow.cpp
OBJECTS       = main.o \
		mainwindow.o \
		mythread.o \
		moc_mainwindow.o
DIST          = /home/sanway/qt/build/qt4-arm/mkspecs/common/unix.conf \
		/home/sanway/qt/build/qt4-arm/mkspecs/common/linux.conf \
		/home/sanway/qt/build/qt4-arm/mkspecs/common/gcc-base.conf \
		/home/sanway/qt/build/qt4-arm/mkspecs/common/gcc-base-unix.conf \
		/home/sanway/qt/build/qt4-arm/mkspecs/common/g++-base.conf \
		/home/sanway/qt/build/qt4-arm/mkspecs/common/g++-unix.conf \
		/home/sanway/qt/build/qt4-arm/mkspecs/common/qws.conf \
		/home/sanway/qt/build/qt4-arm/mkspecs/qconfig.pri \
		/home/sanway/qt/build/qt4-arm/mkspecs/modules/qt_webkit_version.pri \
		/home/sanway/qt/build/qt4-arm/mkspecs/features/qt_functions.prf \
		/home/sanway/qt/build/qt4-arm/mkspecs/features/qt_config.prf \
		/home/sanway/qt/build/qt4-arm/mkspecs/features/exclusive_builds.prf \
		/home/sanway/qt/build/qt4-arm/mkspecs/features/default_pre.prf \
		/home/sanway/qt/build/qt4-arm/mkspecs/features/release.prf \
		/home/sanway/qt/build/qt4-arm/mkspecs/features/default_post.prf \
		/home/sanway/qt/build/qt4-arm/mkspecs/features/shared.prf \
		/home/sanway/qt/build/qt4-arm/mkspecs/features/warn_on.prf \
		/home/sanway/qt/build/qt4-arm/mkspecs/features/qt.prf \
		/home/sanway/qt/build/qt4-arm/mkspecs/features/unix/thread.prf \
		/home/sanway/qt/build/qt4-arm/mkspecs/features/moc.prf \
		/home/sanway/qt/build/qt4-arm/mkspecs/features/resources.prf \
		/home/sanway/qt/build/qt4-arm/mkspecs/features/uic.prf \
		/home/sanway/qt/build/qt4-arm/mkspecs/features/yacc.prf \
		/home/sanway/qt/build/qt4-arm/mkspecs/features/lex.prf \
		/home/sanway/qt/build/qt4-arm/mkspecs/features/include_source_dir.prf \
		_9_keyboard.pro
QMAKE_TARGET  = _9_keyboard
DESTDIR       = 
TARGET        = _9_keyboard

first: all
####### Implicit rules

.SUFFIXES: .o .c .cpp .cc .cxx .C

.cpp.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.cc.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.cxx.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.C.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.c.o:
	$(CC) -c $(CFLAGS) $(INCPATH) -o "$@" "$<"

####### Build rules

all: Makefile $(TARGET)

$(TARGET): ui_mainwindow.h $(OBJECTS)  
	$(LINK) $(LFLAGS) -o $(TARGET) $(OBJECTS) $(OBJCOMP) $(LIBS)

Makefile: _9_keyboard.pro  /home/sanway/qt/build/qt4-arm/mkspecs/qws/linux-arm-g++/qmake.conf /home/sanway/qt/build/qt4-arm/mkspecs/common/unix.conf \
		/home/sanway/qt/build/qt4-arm/mkspecs/common/linux.conf \
		/home/sanway/qt/build/qt4-arm/mkspecs/common/gcc-base.conf \
		/home/sanway/qt/build/qt4-arm/mkspecs/common/gcc-base-unix.conf \
		/home/sanway/qt/build/qt4-arm/mkspecs/common/g++-base.conf \
		/home/sanway/qt/build/qt4-arm/mkspecs/common/g++-unix.conf \
		/home/sanway/qt/build/qt4-arm/mkspecs/common/qws.conf \
		/home/sanway/qt/build/qt4-arm/mkspecs/qconfig.pri \
		/home/sanway/qt/build/qt4-arm/mkspecs/modules/qt_webkit_version.pri \
		/home/sanway/qt/build/qt4-arm/mkspecs/features/qt_functions.prf \
		/home/sanway/qt/build/qt4-arm/mkspecs/features/qt_config.prf \
		/home/sanway/qt/build/qt4-arm/mkspecs/features/exclusive_builds.prf \
		/home/sanway/qt/build/qt4-arm/mkspecs/features/default_pre.prf \
		/home/sanway/qt/build/qt4-arm/mkspecs/features/release.prf \
		/home/sanway/qt/build/qt4-arm/mkspecs/features/default_post.prf \
		/home/sanway/qt/build/qt4-arm/mkspecs/features/shared.prf \
		/home/sanway/qt/build/qt4-arm/mkspecs/features/warn_on.prf \
		/home/sanway/qt/build/qt4-arm/mkspecs/features/qt.prf \
		/home/sanway/qt/build/qt4-arm/mkspecs/features/unix/thread.prf \
		/home/sanway/qt/build/qt4-arm/mkspecs/features/moc.prf \
		/home/sanway/qt/build/qt4-arm/mkspecs/features/resources.prf \
		/home/sanway/qt/build/qt4-arm/mkspecs/features/uic.prf \
		/home/sanway/qt/build/qt4-arm/mkspecs/features/yacc.prf \
		/home/sanway/qt/build/qt4-arm/mkspecs/features/lex.prf \
		/home/sanway/qt/build/qt4-arm/mkspecs/features/include_source_dir.prf \
		/home/sanway/qt/build/qt4-arm/lib/libQtGui.prl \
		/home/sanway/qt/build/qt4-arm/lib/libQtNetwork.prl \
		/home/sanway/qt/build/qt4-arm/lib/libQtCore.prl
	$(QMAKE) -o Makefile _9_keyboard.pro
/home/sanway/qt/build/qt4-arm/mkspecs/common/unix.conf:
/home/sanway/qt/build/qt4-arm/mkspecs/common/linux.conf:
/home/sanway/qt/build/qt4-arm/mkspecs/common/gcc-base.conf:
/home/sanway/qt/build/qt4-arm/mkspecs/common/gcc-base-unix.conf:
/home/sanway/qt/build/qt4-arm/mkspecs/common/g++-base.conf:
/home/sanway/qt/build/qt4-arm/mkspecs/common/g++-unix.conf:
/home/sanway/qt/build/qt4-arm/mkspecs/common/qws.conf:
/home/sanway/qt/build/qt4-arm/mkspecs/qconfig.pri:
/home/sanway/qt/build/qt4-arm/mkspecs/modules/qt_webkit_version.pri:
/home/sanway/qt/build/qt4-arm/mkspecs/features/qt_functions.prf:
/home/sanway/qt/build/qt4-arm/mkspecs/features/qt_config.prf:
/home/sanway/qt/build/qt4-arm/mkspecs/features/exclusive_builds.prf:
/home/sanway/qt/build/qt4-arm/mkspecs/features/default_pre.prf:
/home/sanway/qt/build/qt4-arm/mkspecs/features/release.prf:
/home/sanway/qt/build/qt4-arm/mkspecs/features/default_post.prf:
/home/sanway/qt/build/qt4-arm/mkspecs/features/shared.prf:
/home/sanway/qt/build/qt4-arm/mkspecs/features/warn_on.prf:
/home/sanway/qt/build/qt4-arm/mkspecs/features/qt.prf:
/home/sanway/qt/build/qt4-arm/mkspecs/features/unix/thread.prf:
/home/sanway/qt/build/qt4-arm/mkspecs/features/moc.prf:
/home/sanway/qt/build/qt4-arm/mkspecs/features/resources.prf:
/home/sanway/qt/build/qt4-arm/mkspecs/features/uic.prf:
/home/sanway/qt/build/qt4-arm/mkspecs/features/yacc.prf:
/home/sanway/qt/build/qt4-arm/mkspecs/features/lex.prf:
/home/sanway/qt/build/qt4-arm/mkspecs/features/include_source_dir.prf:
/home/sanway/qt/build/qt4-arm/lib/libQtGui.prl:
/home/sanway/qt/build/qt4-arm/lib/libQtNetwork.prl:
/home/sanway/qt/build/qt4-arm/lib/libQtCore.prl:
qmake:  FORCE
	@$(QMAKE) -o Makefile _9_keyboard.pro

dist: 
	@$(CHK_DIR_EXISTS) .tmp/_9_keyboard1.0.0 || $(MKDIR) .tmp/_9_keyboard1.0.0 
	$(COPY_FILE) --parents $(SOURCES) $(DIST) .tmp/_9_keyboard1.0.0/ && $(COPY_FILE) --parents mainwindow.h mythread.h .tmp/_9_keyboard1.0.0/ && $(COPY_FILE) --parents main.cpp mainwindow.cpp mythread.cpp .tmp/_9_keyboard1.0.0/ && $(COPY_FILE) --parents mainwindow.ui .tmp/_9_keyboard1.0.0/ && (cd `dirname .tmp/_9_keyboard1.0.0` && $(TAR) _9_keyboard1.0.0.tar _9_keyboard1.0.0 && $(COMPRESS) _9_keyboard1.0.0.tar) && $(MOVE) `dirname .tmp/_9_keyboard1.0.0`/_9_keyboard1.0.0.tar.gz . && $(DEL_FILE) -r .tmp/_9_keyboard1.0.0


clean:compiler_clean 
	-$(DEL_FILE) $(OBJECTS)
	-$(DEL_FILE) *~ core *.core


####### Sub-libraries

distclean: clean
	-$(DEL_FILE) $(TARGET) 
	-$(DEL_FILE) Makefile


check: first

mocclean: compiler_moc_header_clean compiler_moc_source_clean

mocables: compiler_moc_header_make_all compiler_moc_source_make_all

compiler_moc_header_make_all: moc_mainwindow.cpp
compiler_moc_header_clean:
	-$(DEL_FILE) moc_mainwindow.cpp
moc_mainwindow.cpp: mainwindow.h
	/home/sanway/qt/build/qt4-arm/bin/moc $(DEFINES) $(INCPATH) mainwindow.h -o moc_mainwindow.cpp

compiler_rcc_make_all:
compiler_rcc_clean:
compiler_image_collection_make_all: qmake_image_collection.cpp
compiler_image_collection_clean:
	-$(DEL_FILE) qmake_image_collection.cpp
compiler_moc_source_make_all:
compiler_moc_source_clean:
compiler_uic_make_all: ui_mainwindow.h
compiler_uic_clean:
	-$(DEL_FILE) ui_mainwindow.h
ui_mainwindow.h: mainwindow.ui
	/home/sanway/qt/build/qt4-arm/bin/uic mainwindow.ui -o ui_mainwindow.h

compiler_yacc_decl_make_all:
compiler_yacc_decl_clean:
compiler_yacc_impl_make_all:
compiler_yacc_impl_clean:
compiler_lex_make_all:
compiler_lex_clean:
compiler_clean: compiler_moc_header_clean compiler_uic_clean 

####### Compile

main.o: main.cpp mainwindow.h \
		mythread.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o main.o main.cpp

mainwindow.o: mainwindow.cpp ui_mainwindow.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o mainwindow.o mainwindow.cpp

mythread.o: mythread.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o mythread.o mythread.cpp

moc_mainwindow.o: moc_mainwindow.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_mainwindow.o moc_mainwindow.cpp

####### Install

install:   FORCE

uninstall:   FORCE

FORCE:

