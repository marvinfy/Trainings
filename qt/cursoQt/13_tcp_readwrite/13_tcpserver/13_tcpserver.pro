#-------------------------------------------------
#
# Project created by QtCreator 2012-06-11T21:38:09
#
#-------------------------------------------------

QT       += core gui network

TARGET = 16_tcpserver
TEMPLATE = app


SOURCES += main.cpp\
        Widget.cpp \
    TcpConnectionServer.cpp \
    DataExchangeSocket.cpp

HEADERS  += Widget.h \
    TcpConnectionServer.h \
    DataExchangeSocket.h

FORMS    += Widget.ui

INCLUDEPATH += ../




