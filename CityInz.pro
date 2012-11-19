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


SOURCES += src/main.cpp\
           src/CitiInz.cpp \
           src/CityMapFrame.cpp \
           src/RoadGraphReader.cpp \
           src/RoadGraph.cpp \
           src/Speed.cpp \
           src/PositionAtEdge.cpp \
           src/Coords.cpp

HEADERS  += src/CitiInz.h \
            src/CityMapFrame.h \
            src/RoadGraphReader.h \
            src/RoadGraph.h \
            src/Speed.h \
            src/PositionAtEdge.h \
            src/Coords.h
