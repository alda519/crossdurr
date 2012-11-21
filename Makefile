#############################################################################
# Makefile for building: itu2
# Generated by qmake (2.01a) (Qt 4.7.4) on: Wed Nov 21 09:41:41 2012
# Project:  itu2.pro
# Template: app
# Command: /usr/bin/qmake -o Makefile itu2.pro
#############################################################################

####### Compiler, tools and options

CC            = gcc
CXX           = g++
DEFINES       = -DQT_WEBKIT -DQT_NO_DEBUG -DQT_GUI_LIB -DQT_CORE_LIB -DQT_SHARED
CFLAGS        = -m64 -pipe -O2 -Wall -W -D_REENTRANT $(DEFINES)
CXXFLAGS      = -m64 -pipe -O2 -Wall -W -D_REENTRANT $(DEFINES)
INCPATH       = -I/usr/share/qt4/mkspecs/linux-g++-64 -I. -I/usr/include/qt4/QtCore -I/usr/include/qt4/QtGui -I/usr/include/qt4 -I. -I.
LINK          = g++
LFLAGS        = -m64 -Wl,-O1
LIBS          = $(SUBLIBS)  -L/usr/lib/x86_64-linux-gnu -lQtGui -lQtCore -lpthread 
AR            = ar cqs
RANLIB        = 
QMAKE         = /usr/bin/qmake
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
		otevri.cpp moc_mainwindow.cpp \
		moc_otevri.cpp \
		qrc_ikony.cpp \
		qrc_ikony_bonus.cpp
OBJECTS       = main.o \
		mainwindow.o \
		otevri.o \
		moc_mainwindow.o \
		moc_otevri.o \
		qrc_ikony.o \
		qrc_ikony_bonus.o
DIST          = /usr/share/qt4/mkspecs/common/g++.conf \
		/usr/share/qt4/mkspecs/common/unix.conf \
		/usr/share/qt4/mkspecs/common/linux.conf \
		/usr/share/qt4/mkspecs/qconfig.pri \
		/usr/share/qt4/mkspecs/modules/qt_phonon.pri \
		/usr/share/qt4/mkspecs/modules/qt_webkit_version.pri \
		/usr/share/qt4/mkspecs/features/qt_functions.prf \
		/usr/share/qt4/mkspecs/features/qt_config.prf \
		/usr/share/qt4/mkspecs/features/exclusive_builds.prf \
		/usr/share/qt4/mkspecs/features/default_pre.prf \
		/usr/share/qt4/mkspecs/features/release.prf \
		/usr/share/qt4/mkspecs/features/default_post.prf \
		/usr/share/qt4/mkspecs/features/warn_on.prf \
		/usr/share/qt4/mkspecs/features/qt.prf \
		/usr/share/qt4/mkspecs/features/unix/thread.prf \
		/usr/share/qt4/mkspecs/features/moc.prf \
		/usr/share/qt4/mkspecs/features/resources.prf \
		/usr/share/qt4/mkspecs/features/uic.prf \
		/usr/share/qt4/mkspecs/features/yacc.prf \
		/usr/share/qt4/mkspecs/features/lex.prf \
		/usr/share/qt4/mkspecs/features/include_source_dir.prf \
		itu2.pro
QMAKE_TARGET  = itu2
DESTDIR       = 
TARGET        = itu2

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

$(TARGET): ui_mainwindow.h ui_otevri.h $(OBJECTS)  
	$(LINK) $(LFLAGS) -o $(TARGET) $(OBJECTS) $(OBJCOMP) $(LIBS)

Makefile: itu2.pro  /usr/share/qt4/mkspecs/linux-g++-64/qmake.conf /usr/share/qt4/mkspecs/common/g++.conf \
		/usr/share/qt4/mkspecs/common/unix.conf \
		/usr/share/qt4/mkspecs/common/linux.conf \
		/usr/share/qt4/mkspecs/qconfig.pri \
		/usr/share/qt4/mkspecs/modules/qt_phonon.pri \
		/usr/share/qt4/mkspecs/modules/qt_webkit_version.pri \
		/usr/share/qt4/mkspecs/features/qt_functions.prf \
		/usr/share/qt4/mkspecs/features/qt_config.prf \
		/usr/share/qt4/mkspecs/features/exclusive_builds.prf \
		/usr/share/qt4/mkspecs/features/default_pre.prf \
		/usr/share/qt4/mkspecs/features/release.prf \
		/usr/share/qt4/mkspecs/features/default_post.prf \
		/usr/share/qt4/mkspecs/features/warn_on.prf \
		/usr/share/qt4/mkspecs/features/qt.prf \
		/usr/share/qt4/mkspecs/features/unix/thread.prf \
		/usr/share/qt4/mkspecs/features/moc.prf \
		/usr/share/qt4/mkspecs/features/resources.prf \
		/usr/share/qt4/mkspecs/features/uic.prf \
		/usr/share/qt4/mkspecs/features/yacc.prf \
		/usr/share/qt4/mkspecs/features/lex.prf \
		/usr/share/qt4/mkspecs/features/include_source_dir.prf \
		/usr/lib/x86_64-linux-gnu/libQtGui.prl \
		/usr/lib/x86_64-linux-gnu/libQtCore.prl
	$(QMAKE) -o Makefile itu2.pro
/usr/share/qt4/mkspecs/common/g++.conf:
/usr/share/qt4/mkspecs/common/unix.conf:
/usr/share/qt4/mkspecs/common/linux.conf:
/usr/share/qt4/mkspecs/qconfig.pri:
/usr/share/qt4/mkspecs/modules/qt_phonon.pri:
/usr/share/qt4/mkspecs/modules/qt_webkit_version.pri:
/usr/share/qt4/mkspecs/features/qt_functions.prf:
/usr/share/qt4/mkspecs/features/qt_config.prf:
/usr/share/qt4/mkspecs/features/exclusive_builds.prf:
/usr/share/qt4/mkspecs/features/default_pre.prf:
/usr/share/qt4/mkspecs/features/release.prf:
/usr/share/qt4/mkspecs/features/default_post.prf:
/usr/share/qt4/mkspecs/features/warn_on.prf:
/usr/share/qt4/mkspecs/features/qt.prf:
/usr/share/qt4/mkspecs/features/unix/thread.prf:
/usr/share/qt4/mkspecs/features/moc.prf:
/usr/share/qt4/mkspecs/features/resources.prf:
/usr/share/qt4/mkspecs/features/uic.prf:
/usr/share/qt4/mkspecs/features/yacc.prf:
/usr/share/qt4/mkspecs/features/lex.prf:
/usr/share/qt4/mkspecs/features/include_source_dir.prf:
/usr/lib/x86_64-linux-gnu/libQtGui.prl:
/usr/lib/x86_64-linux-gnu/libQtCore.prl:
qmake:  FORCE
	@$(QMAKE) -o Makefile itu2.pro

dist: 
	@$(CHK_DIR_EXISTS) .tmp/itu21.0.0 || $(MKDIR) .tmp/itu21.0.0 
	$(COPY_FILE) --parents $(SOURCES) $(DIST) .tmp/itu21.0.0/ && $(COPY_FILE) --parents mainwindow.h otevri.h .tmp/itu21.0.0/ && $(COPY_FILE) --parents ikony.qrc ikony_bonus.qrc .tmp/itu21.0.0/ && $(COPY_FILE) --parents main.cpp mainwindow.cpp otevri.cpp .tmp/itu21.0.0/ && $(COPY_FILE) --parents mainwindow.ui otevri.ui .tmp/itu21.0.0/ && (cd `dirname .tmp/itu21.0.0` && $(TAR) itu21.0.0.tar itu21.0.0 && $(COMPRESS) itu21.0.0.tar) && $(MOVE) `dirname .tmp/itu21.0.0`/itu21.0.0.tar.gz . && $(DEL_FILE) -r .tmp/itu21.0.0


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

compiler_moc_header_make_all: moc_mainwindow.cpp moc_otevri.cpp
compiler_moc_header_clean:
	-$(DEL_FILE) moc_mainwindow.cpp moc_otevri.cpp
moc_mainwindow.cpp: mainwindow.h
	/usr/bin/moc-qt4 $(DEFINES) $(INCPATH) mainwindow.h -o moc_mainwindow.cpp

moc_otevri.cpp: otevri.h
	/usr/bin/moc-qt4 $(DEFINES) $(INCPATH) otevri.h -o moc_otevri.cpp

compiler_rcc_make_all: qrc_ikony.cpp qrc_ikony_bonus.cpp
compiler_rcc_clean:
	-$(DEL_FILE) qrc_ikony.cpp qrc_ikony_bonus.cpp
qrc_ikony.cpp: ikony.qrc \
		ikony/101.png \
		ikony/102.png \
		ikony/001.png \
		ikony/103.png \
		ikony/002.png \
		ikony/003.png \
		ikony/104.png \
		ikony/105.png \
		ikony/004.png \
		ikony/106.png \
		ikony/005.png \
		ikony/006.png \
		ikony/107.png \
		ikony/007.png \
		ikony/108.png \
		ikony/109.png \
		ikony/008.png \
		ikony/009.png \
		ikony/110.png \
		ikony/111.png \
		ikony/010.png \
		ikony/011.png \
		ikony/112.png \
		ikony/012.png \
		ikony/113.png \
		ikony/114.png \
		ikony/013.png \
		ikony/115.png \
		ikony/014.png \
		ikony/015.png \
		ikony/116.png \
		ikony/117.png \
		ikony/016.png \
		ikony/118.png \
		ikony/017.png \
		ikony/119.png \
		ikony/018.png \
		ikony/019.png \
		ikony/120.png \
		ikony/020.png \
		ikony/121.png \
		ikony/122.png \
		ikony/021.png \
		ikony/123.png \
		ikony/022.png \
		ikony/023.png \
		ikony/124.png \
		ikony/024.png \
		ikony/125.png \
		ikony/126.png \
		ikony/025.png \
		ikony/127.png \
		ikony/026.png \
		ikony/027.png \
		ikony/128.png \
		ikony/129.png \
		ikony/028.png \
		ikony/029.png \
		ikony/130.png \
		ikony/131.png \
		ikony/030.png \
		ikony/031.png \
		ikony/132.png \
		ikony/032.png \
		ikony/133.png \
		ikony/033.png \
		ikony/134.png \
		ikony/034.png \
		ikony/135.png \
		ikony/035.png \
		ikony/136.png \
		ikony/036.png \
		ikony/137.png \
		ikony/037.png \
		ikony/138.png \
		ikony/038.png \
		ikony/139.png \
		ikony/039.png \
		ikony/140.png \
		ikony/040.png \
		ikony/141.png \
		ikony/041.png \
		ikony/142.png \
		ikony/042.png \
		ikony/143.png \
		ikony/043.png \
		ikony/144.png \
		ikony/044.png \
		ikony/145.png \
		ikony/045.png \
		ikony/146.png \
		ikony/046.png \
		ikony/147.png \
		ikony/047.png \
		ikony/148.png \
		ikony/048.png \
		ikony/149.png \
		ikony/049.png \
		ikony/150.png \
		ikony/050.png \
		ikony/151.png \
		ikony/051.png \
		ikony/152.png \
		ikony/052.png \
		ikony/153.png \
		ikony/053.png \
		ikony/154.png \
		ikony/054.png \
		ikony/155.png \
		ikony/055.png \
		ikony/156.png \
		ikony/056.png \
		ikony/157.png \
		ikony/057.png \
		ikony/158.png \
		ikony/058.png \
		ikony/159.png \
		ikony/059.png \
		ikony/160.png \
		ikony/060.png \
		ikony/161.png \
		ikony/061.png \
		ikony/162.png \
		ikony/062.png \
		ikony/163.png \
		ikony/063.png \
		ikony/164.png \
		ikony/064.png \
		ikony/165.png \
		ikony/065.png \
		ikony/166.png \
		ikony/066.png \
		ikony/167.png \
		ikony/067.png \
		ikony/168.png \
		ikony/068.png \
		ikony/169.png \
		ikony/069.png \
		ikony/170.png \
		ikony/070.png \
		ikony/171.png \
		ikony/071.png \
		ikony/172.png \
		ikony/072.png \
		ikony/173.png \
		ikony/073.png \
		ikony/174.png \
		ikony/074.png \
		ikony/175.png \
		ikony/075.png \
		ikony/176.png \
		ikony/076.png \
		ikony/177.png \
		ikony/077.png \
		ikony/178.png \
		ikony/078.png \
		ikony/079.png \
		ikony/080.png \
		ikony/081.png \
		ikony/082.png \
		ikony/083.png \
		ikony/084.png \
		ikony/085.png \
		ikony/086.png \
		ikony/087.png \
		ikony/088.png \
		ikony/089.png \
		ikony/090.png \
		ikony/091.png \
		ikony/092.png \
		ikony/093.png \
		ikony/094.png \
		ikony/095.png \
		ikony/096.png \
		ikony/097.png \
		ikony/098.png \
		ikony/099.png \
		ikony/100.png
	/usr/bin/rcc -name ikony ikony.qrc -o qrc_ikony.cpp

qrc_ikony_bonus.cpp: ikony_bonus.qrc \
		ikony_bonus/023.png \
		ikony_bonus/101.png \
		ikony_bonus/056.png \
		ikony_bonus/006.png \
		ikony_bonus/089.png \
		ikony_bonus/061.png \
		ikony_bonus/039.png \
		ikony_bonus/011.png \
		ikony_bonus/094.png \
		ikony_bonus/044.png \
		ikony_bonus/077.png \
		ikony_bonus/027.png \
		ikony_bonus/082.png \
		ikony_bonus/105.png \
		ikony_bonus/032.png \
		ikony_bonus/110.png \
		ikony_bonus/065.png \
		ikony_bonus/015.png \
		ikony_bonus/098.png \
		ikony_bonus/070.png \
		ikony_bonus/048.png \
		ikony_bonus/020.png \
		ikony_bonus/053.png \
		ikony_bonus/003.png \
		ikony_bonus/086.png \
		ikony_bonus/109.png \
		ikony_bonus/036.png \
		ikony_bonus/091.png \
		ikony_bonus/114.png \
		ikony_bonus/069.png \
		ikony_bonus/041.png \
		ikony_bonus/019.png \
		ikony_bonus/074.png \
		ikony_bonus/024.png \
		ikony_bonus/102.png \
		ikony_bonus/057.png \
		ikony_bonus/007.png \
		ikony_bonus/062.png \
		ikony_bonus/012.png \
		ikony_bonus/095.png \
		ikony_bonus/045.png \
		ikony_bonus/078.png \
		ikony_bonus/050.png \
		ikony_bonus/028.png \
		ikony_bonus/083.png \
		ikony_bonus/106.png \
		ikony_bonus/033.png \
		ikony_bonus/111.png \
		ikony_bonus/066.png \
		ikony_bonus/016.png \
		ikony_bonus/099.png \
		ikony_bonus/071.png \
		ikony_bonus/049.png \
		ikony_bonus/021.png \
		ikony_bonus/054.png \
		ikony_bonus/004.png \
		ikony_bonus/087.png \
		ikony_bonus/037.png \
		ikony_bonus/092.png \
		ikony_bonus/042.png \
		ikony_bonus/075.png \
		ikony_bonus/025.png \
		ikony_bonus/080.png \
		ikony_bonus/103.png \
		ikony_bonus/058.png \
		ikony_bonus/030.png \
		ikony_bonus/008.png \
		ikony_bonus/063.png \
		ikony_bonus/013.png \
		ikony_bonus/096.png \
		ikony_bonus/046.png \
		ikony_bonus/079.png \
		ikony_bonus/051.png \
		ikony_bonus/029.png \
		ikony_bonus/001.png \
		ikony_bonus/084.png \
		ikony_bonus/107.png \
		ikony_bonus/034.png \
		ikony_bonus/112.png \
		ikony_bonus/067.png \
		ikony_bonus/017.png \
		ikony_bonus/072.png \
		ikony_bonus/022.png \
		ikony_bonus/100.png \
		ikony_bonus/055.png \
		ikony_bonus/005.png \
		ikony_bonus/088.png \
		ikony_bonus/060.png \
		ikony_bonus/038.png \
		ikony_bonus/010.png \
		ikony_bonus/093.png \
		ikony_bonus/043.png \
		ikony_bonus/076.png \
		ikony_bonus/026.png \
		ikony_bonus/081.png \
		ikony_bonus/104.png \
		ikony_bonus/059.png \
		ikony_bonus/031.png \
		ikony_bonus/009.png \
		ikony_bonus/064.png \
		ikony_bonus/014.png \
		ikony_bonus/097.png \
		ikony_bonus/047.png \
		ikony_bonus/052.png \
		ikony_bonus/002.png \
		ikony_bonus/085.png \
		ikony_bonus/108.png \
		ikony_bonus/035.png \
		ikony_bonus/090.png \
		ikony_bonus/113.png \
		ikony_bonus/068.png \
		ikony_bonus/040.png \
		ikony_bonus/018.png \
		ikony_bonus/073.png
	/usr/bin/rcc -name ikony_bonus ikony_bonus.qrc -o qrc_ikony_bonus.cpp

compiler_image_collection_make_all: qmake_image_collection.cpp
compiler_image_collection_clean:
	-$(DEL_FILE) qmake_image_collection.cpp
compiler_moc_source_make_all:
compiler_moc_source_clean:
compiler_uic_make_all: ui_mainwindow.h ui_otevri.h
compiler_uic_clean:
	-$(DEL_FILE) ui_mainwindow.h ui_otevri.h
ui_mainwindow.h: mainwindow.ui
	/usr/bin/uic-qt4 mainwindow.ui -o ui_mainwindow.h

ui_otevri.h: otevri.ui
	/usr/bin/uic-qt4 otevri.ui -o ui_otevri.h

compiler_yacc_decl_make_all:
compiler_yacc_decl_clean:
compiler_yacc_impl_make_all:
compiler_yacc_impl_clean:
compiler_lex_make_all:
compiler_lex_clean:
compiler_clean: compiler_moc_header_clean compiler_rcc_clean compiler_uic_clean 

####### Compile

main.o: main.cpp mainwindow.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o main.o main.cpp

mainwindow.o: mainwindow.cpp mainwindow.h \
		ui_mainwindow.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o mainwindow.o mainwindow.cpp

otevri.o: otevri.cpp otevri.h \
		ui_otevri.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o otevri.o otevri.cpp

moc_mainwindow.o: moc_mainwindow.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_mainwindow.o moc_mainwindow.cpp

moc_otevri.o: moc_otevri.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_otevri.o moc_otevri.cpp

qrc_ikony.o: qrc_ikony.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o qrc_ikony.o qrc_ikony.cpp

qrc_ikony_bonus.o: qrc_ikony_bonus.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o qrc_ikony_bonus.o qrc_ikony_bonus.cpp

####### Install

install:   FORCE

uninstall:   FORCE

FORCE:
