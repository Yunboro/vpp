GOOGLETEST_DIR = C:\Qt\googletest
include(gtest_dependency.pri)

TEMPLATE = app
CONFIG += console c++14
CONFIG -= app_bundle
CONFIG += thread
CONFIG += qt


HEADERS += \
    Bohrung.h \
    DeList.h \
    Fraesung.h \
    IKomponente.h \
    Iterator.h \
    Komponente.h \
    Serializer.h \
    Werkstueck.h \
    telement.h \
    v3test.h

SOURCES += \
    Bohrung.cpp \
    DeList.cpp \
    Fraesung.cpp \
    Komponente.cpp \
    P02Main.cpp \
    Serializer.cpp \
    Werkstueck.cpp \
    ikomponente.cpp \
    v3test_main.cpp
