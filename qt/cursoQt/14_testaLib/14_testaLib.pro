#-------------------------------------------------
#
# Project created by QtCreator 2012-12-15T16:43:23
#
#-------------------------------------------------

QT       += core

QT       -= gui

TARGET = 14_testaLib
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app

windows:include(c:/cursoQt/include/curso.pri)
!windows:include(/cursoQt/include/curso.pri)

# -l (MINÚSCULO) indica as libs de que preciso
contains(CONFIG, debug) {
LIBS += -lMinhaLibd
}
else {
LIBS += -lMinhaLib
}


SOURCES += main.cpp
