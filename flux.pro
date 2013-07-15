#-------------------------------------------------
#
# Project created by QtCreator 2012-09-15T10:12:39
#
#-------------------------------------------------

QT  += core gui\
    network\
    widgets

TARGET = flux
TEMPLATE = app

SOURCES += main.cpp\
    widget.cpp \
    login.cpp \
    aboutpass.cpp \
    dao.cpp \
    config.cpp \
    plotter.cpp

HEADERS  += widget.h \
    login.h \
    aboutpass.h \
    dao.h \
    bean.h \
    config.h \
    plotter.h

FORMS += widget.ui \
    login.ui \
    aboutpass.ui

RC_FILE = icon.rc

RESOURCES += image.qrc

CONFIG += c++11

include(qtsoap/qtsoap.pri)
