GOOGLETEST_DIR = C:\Qt\googletest

include(gtest_dependency.pri)

TEMPLATE = app
CONFIG += console c++14
CONFIG -= app_bundle
CONFIG += thread
CONFIG -= qt

HEADERS += \    
    tst_testaufgaben.h

SOURCES +=     \
    testZusatzAufgabenMain.cpp
