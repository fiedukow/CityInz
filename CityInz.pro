#-------------------------------------------------
#
# Project created by QtCreator 2012-11-17T16:15:56
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = CityInz
TEMPLATE = app
QMAKE_CXXFLAGS += -std=c++0x


SOURCES += main.cpp\
        CitiInz.cpp \
    CityMapFrame.cpp \
    RoadGraphReader.cpp \
    RoadGraph.cpp \

HEADERS  += CitiInz.h \
    CityMapFrame.h \
    RoadGraphReader.h \
    RoadGraph.h \
