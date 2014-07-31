TEMPLATE = lib
TARGET = UAVObjectUtil
DEFINES += UAVOBJECTUTIL_LIBRARY

QT +=  core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

include(../../common.pri)

HEADERS += uavobjectutil_global.h \
	uavobjectutilmanager.h \
    uavobjectutilplugin.h \
   devicedescriptorstruct.h \
    uavobjecthelper.h

SOURCES += uavobjectutilmanager.cpp \
    uavobjectutilplugin.cpp \
    uavobjecthelper.cpp

OTHER_FILES += UAVObjectUtil.pluginspec

#依赖的库文件
LIBS *= -l$$qtLibraryName(Aggregation)\
        -l$$qtLibraryName(Core)\
        -l$$qtLibraryName(ExtensionSystem)\
        -l$$qtLibraryName(Utils)\
        -l$$qtLibraryName(UAVObjects)

#指定生成的plugin保存目录
DESTDIR=$$PROJECT_PLUGINSDIR
