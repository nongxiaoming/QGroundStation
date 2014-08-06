TEMPLATE = lib 
TARGET = FlightLog

QT += qml quick

include(../../common.pri)

HEADERS += flightlogplugin.h \
    flightlogmanager.h \
    flightlogdialog.h
SOURCES += flightlogplugin.cpp \
    flightlogmanager.cpp \
    flightlogdialog.cpp

OTHER_FILES += Flightlog.pluginspec \
    FlightLogDialog.qml \
    functions.js

FORMS +=

RESOURCES += \
    flightLog.qrc

#依赖的库文件
LIBS *= -l$$qtLibraryName(Aggregation)\
        -l$$qtLibraryName(Core)\
        -l$$qtLibraryName(ExtensionSystem)\
        -l$$qtLibraryName(Utils)\
        -l$$qtLibraryName(UAVObjects)\
        -l$$qtLibraryName(UAVObjectUtil)\
        -l$$qtLibraryName(UAVTalk)\
        -l$$qtLibraryName(UAVSettingsImportExport)\
        -l$$qtLibraryName(Telemetry)

#指定生成的plugin保存目录
DESTDIR=$$PROJECT_PLUGINSDIR
