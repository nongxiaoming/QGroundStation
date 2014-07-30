TEMPLATE = lib
TARGET = AntennaTrack

QT +=  core gui serialport

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

include(../../common.pri)

HEADERS += antennatrackplugin.h
HEADERS += gpsparser.h
HEADERS += telemetryparser.h
HEADERS += antennatrackgadget.h
HEADERS += antennatrackwidget.h
HEADERS += antennatrackgadgetfactory.h
HEADERS += antennatrackgadgetconfiguration.h
HEADERS += antennatrackgadgetoptionspage.h
SOURCES += antennatrackplugin.cpp
SOURCES += gpsparser.cpp
SOURCES += telemetryparser.cpp
SOURCES += antennatrackgadget.cpp
SOURCES += antennatrackgadgetfactory.cpp
SOURCES += antennatrackwidget.cpp
SOURCES += antennatrackgadgetconfiguration.cpp
SOURCES += antennatrackgadgetoptionspage.cpp
OTHER_FILES += AntennaTrack.pluginspec
FORMS += antennatrackgadgetoptionspage.ui
FORMS += antennatrackwidget.ui

#依赖的库文件
LIBS += -l$$qtLibraryName(Core)\
        -l$$qtLibraryName(Aggregation)\
        -l$$qtLibraryName(Utils)\
        -l$$qtLibraryName(UAVObjects)\
        -l$$qtLibraryName(ExtensionSystem)\
        -l$$qtLibraryName(Qwt)
#指定生成的plugin保存目录
DESTDIR=$$PROJECT_PLUGINSDIR
