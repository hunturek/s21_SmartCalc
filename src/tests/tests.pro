QT += core testlib
CONFIG += console
CONFIG -= app_bundle

INCLUDEPATH += /usr/local/include

LIBS += -L/usr/local/lib -lgtest -lgtest_main -pthread -lstdc++

SOURCES += tests.cpp \
           ../calc2/model.cpp

HEADERS += ../calc2/model.h

QMAKE_CXX = /usr/bin/g++
