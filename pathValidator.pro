TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
    main.c\
    errorloger.c \
    check.c \
    processing.c

HEADERS += \
    errorloger.h \
    check.h \
    processing.h

