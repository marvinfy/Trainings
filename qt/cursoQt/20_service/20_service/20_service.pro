#-------------------------------------------------
#
# Project created by QtCreator 2010-12-11T17:38:33
#
#-------------------------------------------------

QT       += core network

QT       -= gui

TARGET = qt_curso_service
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app
win32: include (C:/QtSDK/QtService/qtservice-2.6_1-opensource/src/qtservice.pri)
unix : include (/home/user/QtSDK/QtService/qtservice-2.6_1-opensource/src/qtservice.pri)

SOURCES += main.cpp \
    cursoService.cpp \
    TcpServer.cpp

HEADERS += \
    cursoService.h \
    TcpServer.h

win32:DESTDIR=c:/cursoQt
unix:DESTDIR=/home/user/cursoQt
