#-------------------------------------------------
#
# Project created by QtCreator 2012-10-24T15:11:27
#
#-------------------------------------------------

QT       += core gui

TARGET = itu2
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    otevri.cpp \
    field.cpp \
    editfield.cpp \
    questfield.cpp \
    tajenkafield.cpp \
    symbolfield.cpp

HEADERS  += mainwindow.h \
    otevri.h \
    field.h \
    editfield.h \
    questfield.h \
    tajenkafield.h \
    symbolfield.h

FORMS    += mainwindow.ui \
    otevri.ui

OTHER_FILES +=

RESOURCES += \
    ikony.qrc \
    ikony_bonus.qrc \
    ikony_toolbar/ikonyToolbar.qrc
