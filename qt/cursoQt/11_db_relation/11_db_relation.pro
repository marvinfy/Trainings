#-------------------------------------------------
#
# Project created by QtCreator 2011-04-17T17:24:13
#
#-------------------------------------------------

QT       += core gui sql

TARGET =
TEMPLATE = app


SOURCES += main.cpp\
        Widget.cpp \
    MovimentoEditDialog.cpp \
    DateDelegate.cpp

HEADERS  += Widget.h \
    MovimentoEditDialog.h \
    DateDelegate.h \
    ColumnIndexes.h

FORMS    += Widget.ui \
    MovimentoEditDialog.ui

RESOURCES += \
    recursos/recursos.qrc

OTHER_FILES += \
    opcoes.txt
