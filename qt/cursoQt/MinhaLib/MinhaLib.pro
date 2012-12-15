#-------------------------------------------------
#
# Project created by QtCreator 2012-12-15T15:40:04
#
#-------------------------------------------------

QT       -= gui

TARGET = MinhaLib
TEMPLATE = lib

DEFINES += MINHALIB_LIBRARY

windows:include(c:/cursoQt/include/curso.pri)
!windows:include(/cursoQt/include/curso.pri)

SOURCES += MinhaLib.cpp

HEADERS += \
	 $$INCLUDE_DIR/MinhaLib.h

symbian {
    MMP_RULES += EXPORTUNFROZEN
    TARGET.UID3 = 0xE54EFCCF
    TARGET.CAPABILITY = 
    TARGET.EPOCALLOWDLLDATA = 1
    addFiles.sources = MinhaLib.dll
    addFiles.path = !:/sys/bin
    DEPLOYMENT += addFiles
}

unix:!symbian {
    maemo5 {
        target.path = /opt/usr/lib
    } else {
        target.path = /usr/lib
    }
    INSTALLS += target
}



