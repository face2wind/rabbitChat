#-------------------------------------------------
#
# Project created by QtCreator 2016-09-05T19:48:41
#
#-------------------------------------------------

QT       += core gui network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = rabbitChat
TEMPLATE = app

INCLUDEPATH += ../../common

SOURCES += main.cpp\
    network_manager/networkmanager.cpp \
    network_manager/networkagent.cpp \
    ui/loginwindow.cpp \
    ui/ui_manager.cpp \
    network_manager/msg_handler.cpp \
    model/chat_manager.cpp \
    controller/login_controller.cpp

HEADERS  += ui/loginwindow.h \
    network_manager/networkmanager.h \
    network_manager/networkagent.h \
    ui/ui_manager.hpp \
    network_manager/msg_handler.h \
    model/chat_manager.hpp \
    controller/login_controller.hpp

FORMS    += ui/loginwindow.ui

QMAKE_CXXFLAGS += -std=c++11
