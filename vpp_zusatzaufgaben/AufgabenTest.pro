GOOGLETEST_DIR = C:\Qt\googletest

include(gtest_dependency.pri)

TEMPLATE = app
CONFIG += console c++14
CONFIG -= app_bundle
CONFIG += thread
CONFIG -= qt

HEADERS += \     \
    a04.h \
    hochlager.h \
    iprodukt.h \
    produkt.h \
    produktmitpreishistory.h
    tst_testaufgaben.h

SOURCES +=     \
    a04.cpp \
    iprodukt.cpp \
    produkt.cpp \
    produktmitpreishistory.cpp \
    testZusatzAufgabenMain.cpp
