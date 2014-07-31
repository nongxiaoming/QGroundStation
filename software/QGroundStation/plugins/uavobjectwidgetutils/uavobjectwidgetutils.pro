TEMPLATE = lib
TARGET = UAVObjectWidgetUtils
DEFINES += UAVOBJECTWIDGETUTILS_LIBRARY
QT += svg

include(../../common.pri)

HEADERS += uavobjectwidgetutils_global.h \
    uavobjectwidgetutilsplugin.h \
    configtaskwidget.h \
    mixercurvewidget.h \
    mixercurvepoint.h \
    mixercurveline.h \
    smartsavebutton.h \
    popupwidget.h

SOURCES += uavobjectwidgetutilsplugin.cpp \
    configtaskwidget.cpp \
    mixercurvewidget.cpp \
    mixercurvepoint.cpp \
    mixercurveline.cpp \
    smartsavebutton.cpp \
    popupwidget.cpp

RESOURCES += uavobjectwidgetutils.qrc

OTHER_FILES += UAVObjectWidgetUtils.pluginspec

FORMS +=

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
