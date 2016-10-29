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
    ui/loginwindow.cpp \
    ui/ui_manager.cpp \
    model/chat_manager.cpp \
    controller/login_controller.cpp \
    network/msg_handler.cpp \
    network/networkagent.cpp \
    network/networkmanager.cpp \
    ui/registerwindow.cpp \
    ui/mainwindow.cpp \
    memory/byte_array/queue_byte_array.cpp \
    memory/serialize/serialize_base.cpp \
    memory/serialize/serialize_manager.cpp \
    ../../common/protocol_def.cpp

HEADERS  += ui/loginwindow.h \
    ui/ui_manager.hpp \
    model/chat_manager.hpp \
    controller/login_controller.hpp \
    network/msg_handler.h \
    network/networkagent.h \
    network/networkmanager.h \
    ui/registerwindow.h \
    ui/mainwindow.h \
    memory/byte_array/byte_array.hpp \
    memory/byte_array/queue_byte_array.hpp \
    memory/serialize/serialize_base.hpp \
    memory/serialize/serialize_manager.hpp \
    ../../common/message_code.hpp \
    ../../common/protocol_def.hpp

FORMS    += ui/loginwindow.ui \
    ui/registerwindow.ui \
    ui/mainwindow.ui

QMAKE_CXXFLAGS += -std=c++11

RESOURCES += \
    res/login_bg.qrc

DISTFILES += \
    common/protocol_def.xml
