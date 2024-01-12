QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = termw
TEMPLATE = app

QMAKE_LFLAGS_WINDOWS += -static

SOURCES += main.cpp\
        termwidget.cpp

HEADERS += termwidget.h
