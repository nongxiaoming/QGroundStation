TEMPLATE = lib
TARGET = opHID

include(../../common.pri)

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

HEADERS += inc/ophid_global.h \
           inc/ophid_plugin.h \
           inc/ophid.h \
           inc/ophid_hidapi.h \
           inc/ophid_const.h \
           inc/ophid_usbmon.h \
           inc/ophid_usbsignal.h \
           hidapi/hidapi.h
SOURCES += src/ophid_plugin.cpp \
           src/ophid.cpp \
           src/ophid_usbsignal.cpp \
           src/ophid_hidapi.cpp
FORMS += 
RESOURCES += 
DEFINES += OPHID_LIBRARY
OTHER_FILES += opHID.pluginspec

INCLUDEPATH += ./inc

# Platform Specific

win32 { 
    SOURCES += src/ophid_usbmon_win.cpp \
               hidapi/windows/hid.c
    LIBS += -lhid -lsetupapi
}

macx { 
    SOURCES += src/ophid_usbmon_mac.cpp \
               hidapi/mac/hid.c
    LIBS += -framework CoreFoundation \
            -framework IOKit
}

linux-g++ {
    SOURCES += src/ophid_usbmon_linux.cpp
    LIBS += -lusb -ludev

    # hidapi library
    ## rawhid
    #  SOURCES += hidapi/linux/hid.c
    ## libusb
    SOURCES += hidapi/libusb/hid.c
    LIBS += `pkg-config libusb-1.0 --libs` -lrt -lpthread
    INCLUDEPATH += /usr/include/libusb-1.0 
#   INCLUDEPATH += `pkg-config libusb-1.0 --cflags`

    !exists(/usr/include/libusb-1.0) {
        error(Install libusb-1.0.0-dev using your package manager.)
    }
}

linux-g++-64 {
    SOURCES += src/ophid_usbmon_linux.cpp
    LIBS += -lusb -ludev

    # hidapi library
    ## rawhid
    #  SOURCES += hidapi/linux/hid.c
    ## libusb
    SOURCES += hidapi/libusb/hid.c
    LIBS += `pkg-config libusb-1.0 --libs` -lrt -lpthread
    INCLUDEPATH += /usr/include/libusb-1.0
#   INCLUDEPATH += `pkg-config libusb-1.0 --cflags`
    !exists(/usr/include/libusb-1.0) {
        error(Install libusb-1.0.0-dev using your package manager.)
    }
}

#依赖的库文件
LIBS += -l$$qtLibraryName(Aggregation)\
        -l$$qtLibraryName(Core)\
        -l$$qtLibraryName(ExtensionSystem)\
        -l$$qtLibraryName(Utils)

#指定生成的lib保存目录
DESTDIR=$${PROJECT_LIBDIR}
