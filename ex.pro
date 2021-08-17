#-------------------------------------------------
#
# Project created by QtCreator 2016-04-11T21:36:01
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = ex
TEMPLATE = app


SOURCES += main.cpp\
        ex.cpp

HEADERS  += ex.h

#CONFIG += mobility
#MOBILITY =

QMAKE_LFLAGS += -static -static-libgcc
