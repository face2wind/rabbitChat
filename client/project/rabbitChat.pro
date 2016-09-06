#-------------------------------------------------
#
# Project created by QtCreator 2016-09-05T19:48:41
#
#-------------------------------------------------

QT       += core gui network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = rabbitChat
TEMPLATE = app


SOURCES += main.cpp\
        loginwindow.cpp \
    network_manager/networkmanager.cpp \
    network_manager/networkagent.cpp

HEADERS  += loginwindow.h \
    network_manager/networkmanager.h \
    network_manager/networkagent.h

FORMS    += loginwindow.ui
