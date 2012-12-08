#-------------------------------------------------
#
# Project created by QtCreator 2012-11-10T10:00:12
#
#-------------------------------------------------

QT       += core

QT       -= gui

TARGET = 03_signals_slots_valuechanged
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app

# acrescentando um diretorio onde estarão headers de bibliotecas(usados por muitos)

#   >>>>>>  INCLUDEPATH += /meudiretorio/includesglobais

# assim poderei fazer :
# #include <MinhaLib.h>
# ao invés de
# include "/meudiretorio/includesglobais/MinhaLib.h"

SOURCES += main.cpp \
    Spin.cpp \
    Slider.cpp

HEADERS += \
    Spin.h \
    Slider.h












