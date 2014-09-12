TEMPLATE = lib
TARGET = PfdQml
QT += svg
QT += opengl
QT += qml quick
OSG {
    DEFINES += USE_OSG
}

include(../../common.pri)


HEADERS += \
    pfdqmlplugin.h \
    pfdqmlgadget.h \
    pfdqmlgadgetwidget.h \
    pfdqmlgadgetfactory.h \
    pfdqmlgadgetconfiguration.h \
    pfdqmlgadgetoptionspage.h

SOURCES += \
    pfdqmlplugin.cpp \
    pfdqmlgadget.cpp \
    pfdqmlgadgetfactory.cpp \
    pfdqmlgadgetwidget.cpp \
    pfdqmlgadgetconfiguration.cpp \
    pfdqmlgadgetoptionspage.cpp


contains(DEFINES,USE_OSG) {
    LIBS += -losg -losgUtil -losgViewer -losgQt -losgDB -lOpenThreads -losgGA
    LIBS += -losgEarth -losgEarthFeatures -losgEarthUtil

    HEADERS += osgearth.h
    SOURCES += osgearth.cpp
}

OTHER_FILES += PfdQml.pluginspec

FORMS += pfdqmlgadgetoptionspage.ui

#依赖的库文件
LIBS += -l$$qtLibraryName(Aggregation)\
        -l$$qtLibraryName(Core)\
        -l$$qtLibraryName(ExtensionSystem)\
        -l$$qtLibraryName(Utils)\
        -l$$qtLibraryName(UAVObjects)


#指定生成的plugin保存目录
DESTDIR=$$PROJECT_PLUGINSDIR
