TEMPLATE = lib
TARGET = UAVTalk

QT += network

DEFINES += UAVTALK_LIBRARY

#DEFINES += VERBOSE_TELEMETRY
#DEFINES += VERBOSE_UAVTALK

QT +=  core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

include(../../common.pri)

HEADERS += \
    uavtalk.h \
    uavtalkplugin.h \
    telemetrymonitor.h \
    telemetrymanager.h \
    uavtalk_global.h \
    telemetry.h

SOURCES += \
    uavtalk.cpp \
    uavtalkplugin.cpp \
    telemetrymonitor.cpp \
    telemetrymanager.cpp \
    telemetry.cpp

OTHER_FILES += UAVTalk.pluginspec

#依赖的库文件
LIBS *= -l$$qtLibraryName(Aggregation)\
        -l$$qtLibraryName(Core)\
        -l$$qtLibraryName(ExtensionSystem)\
        -l$$qtLibraryName(Utils)\
        -l$$qtLibraryName(UAVObjects)\

#指定生成的plugin保存目录
DESTDIR=$${PROJECT_PLUGINSDIR}
