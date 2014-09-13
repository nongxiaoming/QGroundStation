TEMPLATE = lib
TARGET = GCSControl

QT += svg opengl network

include(../../common.pri)


HEADERS += \
    gcscontrolgadget.h \
    gcscontrolgadgetconfiguration.h \
    gcscontrolgadgetoptionspage.h \
    gcscontrolgadgetwidget.h \
    gcscontrolgadgetfactory.h \
    gcscontrolplugin.h \
    joystickcontrol.h

SOURCES += \
    gcscontrolgadget.cpp \
    gcscontrolgadgetconfiguration.cpp \
    gcscontrolgadgetoptionspage.cpp \
    gcscontrolgadgetwidget.cpp \
    gcscontrolgadgetfactory.cpp \
    gcscontrolplugin.cpp \
    joystickcontrol.cpp

OTHER_FILES += GCSControl.pluginspec

FORMS += \
    gcscontrol.ui \
    gcscontrolgadgetoptionspage.ui

RESOURCES += gcscontrol.qrc

#依赖的库文件
LIBS *= -l$$qtLibraryName(Aggregation)\
        -l$$qtLibraryName(Core)\
        -l$$qtLibraryName(ExtensionSystem)\
        -l$$qtLibraryName(Utils)\
        -l$$qtLibraryName(UAVObjects)\
        -l$$qtLibraryName(Telemetry)\
        -l$$qtLibraryName(sdlgamepad)

#指定生成的plugin保存目录
DESTDIR=$${PROJECT_PLUGINSDIR}
