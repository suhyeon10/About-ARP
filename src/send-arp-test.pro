TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

INCLUDEPATH += C:/npcap-sdk-1.15/Include
LIBS += -LC:/npcap-sdk-1.15/Lib/x64 -lwpcap -lws2_32

SOURCES += \
    arphdr.cpp \
    ethhdr.cpp \
    ip.cpp \
    mac.cpp \
    main.cpp

HEADERS += \
    arphdr.h \
    ethhdr.h \
    ip.h \
    mac.h
