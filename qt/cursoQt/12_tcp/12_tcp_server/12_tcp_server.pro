#-------------------------------------------------
#
# Project created by QtCreator 2008-11-10T20:42:20
#
#-------------------------------------------------

QT       += network

TARGET = 
TEMPLATE = app


SOURCES += main.cpp\
        svr_maindlg.cpp \
    TcpDataExchangeSocket.cpp

HEADERS  += svr_maindlg.h \
    TcpConnectionServer.h \
    TcpDataExchangeSocket.h \
    ../TcpDataProtocol.h

FORMS    += svr_maindlg.ui

INCLUDEPATH += ../

