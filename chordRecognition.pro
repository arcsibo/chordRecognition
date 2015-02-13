#-------------------------------------------------
#
# Project created by QtCreator 2015-01-01T22:13:34
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = chordRecognition
TEMPLATE = app

QMAKE_CXXFLAGS += -std=c++0x


# INCLUDEPATH += /usr/include/QtMobility
# INCLUDEPATH += /usr/include/QtMultimediaKit

LIBS+= -lsndfile \
       #-lQtMultimedia


SOURCES += src/main.cpp\
        src/mainwindow.cpp \
    genchords/src/BeatDetection.cpp \
    genchords/src/Chordsequence.cpp \
    genchords/src/Chordtype.cpp \
    genchords/src/FFT.cpp \
    genchords/src/Key.cpp \
    genchords/src/Labelfile.cpp \
    genchords/src/PCP.cpp \
    genchords/src/PitchName.cpp \
    genchords/src/Sounddata.cpp \
    genchords/src/utilities.cpp \
    src/Utils/neuralutilities.cpp \
    src/IOMusicHandler/fileoperator.cpp \
    src/IOMusicHandler/getfeatures.cpp \
    src/IOMusicHandler/sounddata.cpp


HEADERS  += src/mainwindow.h \
    genchords/src/BeatDetection.h \
    genchords/src/Chordsequence.h \
    genchords/src/Chordtype.h \
    genchords/src/FFT.h \
    genchords/src/genchords.h \
    genchords/src/Key.h \
    genchords/src/Labelfile.h \
    genchords/src/PCP.h \
    genchords/src/PitchName.h \
    genchords/src/Sounddata.h \
    genchords/src/utilities.h \
    genchords/src/learnchords.h \
    src/Utils/neuralutilities.h \
    src/IOMusicHandler/fileoperator.h \
    src/IOMusicHandler/getfeatures.h \
    src/IOMusicHandler/sounddata.h

FORMS    += src/mainwindow.ui
