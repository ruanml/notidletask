#############################################################################
# Makefile for building: notidletask
# Generated by qmake (2.01a) (Qt 4.6.3) on: Sun Jan 15 19:29:30 2012
# Project:  notidletask.pro
# Template: app
# Command: /usr/bin/qmake-qt4 -spec /usr/share/qt4/mkspecs/linux-g++ -unix -o Makefile notidletask.pro
#############################################################################

####### Compiler, tools and options

CC            = gcc
CXX           = g++
DEFINES       = -DQT_NO_DEBUG -DQT_XML_LIB -DQT_GUI_LIB -DQT_CORE_LIB -DQT_SHARED
CFLAGS        = -pipe -O2 -Wall -W -D_REENTRANT $(DEFINES)
CXXFLAGS      = -pipe -O2 -Wall -W -D_REENTRANT $(DEFINES)
INCPATH       = -I/usr/share/qt4/mkspecs/linux-g++ -I. -I/usr/include/qt4/QtCore -I/usr/include/qt4/QtGui -I/usr/include/qt4/QtXml -I/usr/include/qt4 -I. -I.
LINK          = g++
LFLAGS        = -Wl,-O1
LIBS          = $(SUBLIBS)  -L/usr/lib -lXss -lQtXml -lQtGui -lQtCore -lpthread 
AR            = ar cqs
RANLIB        = 
QMAKE         = /usr/bin/qmake-qt4
TAR           = tar -cf
COMPRESS      = gzip -9f
COPY          = cp -f
SED           = sed
COPY_FILE     = $(COPY)
COPY_DIR      = $(COPY) -r
STRIP         = strip
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
		linuxsystemidle.cpp \
		isystemidle.cpp \
		configuration.cpp \
		windowssystemidle.cpp moc_mainwindow.cpp \
		moc_isystemidle.cpp \
		qrc_images.cpp
OBJECTS       = main.o \
		mainwindow.o \
		linuxsystemidle.o \
		isystemidle.o \
		configuration.o \
		windowssystemidle.o \
		moc_mainwindow.o \
		moc_isystemidle.o \
		qrc_images.o
DIST          = /usr/share/qt4/mkspecs/common/g++.conf \
		/usr/share/qt4/mkspecs/common/unix.conf \
		/usr/share/qt4/mkspecs/common/linux.conf \
		/usr/share/qt4/mkspecs/qconfig.pri \
		/usr/share/qt4/mkspecs/features/qt_functions.prf \
		/usr/share/qt4/mkspecs/features/qt_config.prf \
		/usr/share/qt4/mkspecs/features/exclusive_builds.prf \
		/usr/share/qt4/mkspecs/features/default_pre.prf \
		/usr/share/qt4/mkspecs/features/release.prf \
		/usr/share/qt4/mkspecs/features/default_post.prf \
		/usr/share/qt4/mkspecs/features/static.prf \
		/usr/share/qt4/mkspecs/features/warn_on.prf \
		/usr/share/qt4/mkspecs/features/qt.prf \
		/usr/share/qt4/mkspecs/features/unix/thread.prf \
		/usr/share/qt4/mkspecs/features/moc.prf \
		/usr/share/qt4/mkspecs/features/resources.prf \
		/usr/share/qt4/mkspecs/features/uic.prf \
		/usr/share/qt4/mkspecs/features/yacc.prf \
		/usr/share/qt4/mkspecs/features/lex.prf \
		/usr/share/qt4/mkspecs/features/include_source_dir.prf \
		notidletask.pro
QMAKE_TARGET  = notidletask
DESTDIR       = 
TARGET        = notidletask

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

Makefile: notidletask.pro  /usr/share/qt4/mkspecs/linux-g++/qmake.conf /usr/share/qt4/mkspecs/common/g++.conf \
		/usr/share/qt4/mkspecs/common/unix.conf \
		/usr/share/qt4/mkspecs/common/linux.conf \
		/usr/share/qt4/mkspecs/qconfig.pri \
		/usr/share/qt4/mkspecs/features/qt_functions.prf \
		/usr/share/qt4/mkspecs/features/qt_config.prf \
		/usr/share/qt4/mkspecs/features/exclusive_builds.prf \
		/usr/share/qt4/mkspecs/features/default_pre.prf \
		/usr/share/qt4/mkspecs/features/release.prf \
		/usr/share/qt4/mkspecs/features/default_post.prf \
		/usr/share/qt4/mkspecs/features/static.prf \
		/usr/share/qt4/mkspecs/features/warn_on.prf \
		/usr/share/qt4/mkspecs/features/qt.prf \
		/usr/share/qt4/mkspecs/features/unix/thread.prf \
		/usr/share/qt4/mkspecs/features/moc.prf \
		/usr/share/qt4/mkspecs/features/resources.prf \
		/usr/share/qt4/mkspecs/features/uic.prf \
		/usr/share/qt4/mkspecs/features/yacc.prf \
		/usr/share/qt4/mkspecs/features/lex.prf \
		/usr/share/qt4/mkspecs/features/include_source_dir.prf \
		/usr/lib/libQtXml.prl \
		/usr/lib/libQtGui.prl \
		/usr/lib/libQtCore.prl
	$(QMAKE) -spec /usr/share/qt4/mkspecs/linux-g++ -unix -o Makefile notidletask.pro
/usr/share/qt4/mkspecs/common/g++.conf:
/usr/share/qt4/mkspecs/common/unix.conf:
/usr/share/qt4/mkspecs/common/linux.conf:
/usr/share/qt4/mkspecs/qconfig.pri:
/usr/share/qt4/mkspecs/features/qt_functions.prf:
/usr/share/qt4/mkspecs/features/qt_config.prf:
/usr/share/qt4/mkspecs/features/exclusive_builds.prf:
/usr/share/qt4/mkspecs/features/default_pre.prf:
/usr/share/qt4/mkspecs/features/release.prf:
/usr/share/qt4/mkspecs/features/default_post.prf:
/usr/share/qt4/mkspecs/features/static.prf:
/usr/share/qt4/mkspecs/features/warn_on.prf:
/usr/share/qt4/mkspecs/features/qt.prf:
/usr/share/qt4/mkspecs/features/unix/thread.prf:
/usr/share/qt4/mkspecs/features/moc.prf:
/usr/share/qt4/mkspecs/features/resources.prf:
/usr/share/qt4/mkspecs/features/uic.prf:
/usr/share/qt4/mkspecs/features/yacc.prf:
/usr/share/qt4/mkspecs/features/lex.prf:
/usr/share/qt4/mkspecs/features/include_source_dir.prf:
/usr/lib/libQtXml.prl:
/usr/lib/libQtGui.prl:
/usr/lib/libQtCore.prl:
qmake:  FORCE
	@$(QMAKE) -spec /usr/share/qt4/mkspecs/linux-g++ -unix -o Makefile notidletask.pro

dist: 
	@$(CHK_DIR_EXISTS) .tmp/notidletask1.0.0 || $(MKDIR) .tmp/notidletask1.0.0 
	$(COPY_FILE) --parents $(SOURCES) $(DIST) .tmp/notidletask1.0.0/ && $(COPY_FILE) --parents mainwindow.h isystemidle.h linuxsystemidle.h configuration.h main.h windowssystemidle.h crosscompiling.h .tmp/notidletask1.0.0/ && $(COPY_FILE) --parents images.qrc .tmp/notidletask1.0.0/ && $(COPY_FILE) --parents main.cpp mainwindow.cpp linuxsystemidle.cpp isystemidle.cpp configuration.cpp windowssystemidle.cpp .tmp/notidletask1.0.0/ && $(COPY_FILE) --parents mainwindow.ui .tmp/notidletask1.0.0/ && (cd `dirname .tmp/notidletask1.0.0` && $(TAR) notidletask1.0.0.tar notidletask1.0.0 && $(COMPRESS) notidletask1.0.0.tar) && $(MOVE) `dirname .tmp/notidletask1.0.0`/notidletask1.0.0.tar.gz . && $(DEL_FILE) -r .tmp/notidletask1.0.0


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

compiler_moc_header_make_all: moc_mainwindow.cpp moc_isystemidle.cpp
compiler_moc_header_clean:
	-$(DEL_FILE) moc_mainwindow.cpp moc_isystemidle.cpp
moc_mainwindow.cpp: main.h \
		configuration.h \
		isystemidle.h \
		crosscompiling.h \
		mainwindow.h
	/usr/bin/moc-qt4 $(DEFINES) $(INCPATH) mainwindow.h -o moc_mainwindow.cpp

moc_isystemidle.cpp: crosscompiling.h \
		configuration.h \
		isystemidle.h
	/usr/bin/moc-qt4 $(DEFINES) $(INCPATH) isystemidle.h -o moc_isystemidle.cpp

compiler_rcc_make_all: qrc_images.cpp
compiler_rcc_clean:
	-$(DEL_FILE) qrc_images.cpp
qrc_images.cpp: images.qrc \
		appicon.ico
	/usr/bin/rcc -name images images.qrc -o qrc_images.cpp

compiler_image_collection_make_all: qmake_image_collection.cpp
compiler_image_collection_clean:
	-$(DEL_FILE) qmake_image_collection.cpp
compiler_moc_source_make_all:
compiler_moc_source_clean:
compiler_uic_make_all: ui_mainwindow.h
compiler_uic_clean:
	-$(DEL_FILE) ui_mainwindow.h
ui_mainwindow.h: mainwindow.ui
	/usr/bin/uic-qt4 mainwindow.ui -o ui_mainwindow.h

compiler_yacc_decl_make_all:
compiler_yacc_decl_clean:
compiler_yacc_impl_make_all:
compiler_yacc_impl_clean:
compiler_lex_make_all:
compiler_lex_clean:
compiler_clean: compiler_moc_header_clean compiler_rcc_clean compiler_uic_clean 

####### Compile

main.o: main.cpp main.h \
		configuration.h \
		isystemidle.h \
		crosscompiling.h \
		mainwindow.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o main.o main.cpp

mainwindow.o: mainwindow.cpp mainwindow.h \
		main.h \
		configuration.h \
		isystemidle.h \
		crosscompiling.h \
		ui_mainwindow.h \
		linuxsystemidle.h \
		windowssystemidle.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o mainwindow.o mainwindow.cpp

linuxsystemidle.o: linuxsystemidle.cpp linuxsystemidle.h \
		isystemidle.h \
		crosscompiling.h \
		configuration.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o linuxsystemidle.o linuxsystemidle.cpp

isystemidle.o: isystemidle.cpp isystemidle.h \
		crosscompiling.h \
		configuration.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o isystemidle.o isystemidle.cpp

configuration.o: configuration.cpp configuration.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o configuration.o configuration.cpp

windowssystemidle.o: windowssystemidle.cpp windowssystemidle.h \
		isystemidle.h \
		crosscompiling.h \
		configuration.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o windowssystemidle.o windowssystemidle.cpp

moc_mainwindow.o: moc_mainwindow.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_mainwindow.o moc_mainwindow.cpp

moc_isystemidle.o: moc_isystemidle.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_isystemidle.o moc_isystemidle.cpp

qrc_images.o: qrc_images.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o qrc_images.o qrc_images.cpp

####### Install

install:   FORCE

uninstall:   FORCE

FORCE:

