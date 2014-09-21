TEMPLATE = lib
TARGET = PFDGadget
QT += svg
QT += opengl

include(../../common.pri)

HEADERS += pfdplugin.h
HEADERS += pfdgadget.h
HEADERS += pfdgadgetwidget.h
HEADERS += pfdgadgetfactory.h
HEADERS += pfdgadgetconfiguration.h
HEADERS += pfdgadgetoptionspage.h
SOURCES += pfdplugin.cpp
SOURCES += pfdgadget.cpp
SOURCES += pfdgadgetfactory.cpp
SOURCES += pfdgadgetwidget.cpp
SOURCES += pfdgadgetconfiguration.cpp
SOURCES += pfdgadgetoptionspage.cpp
OTHER_FILES += PFDGadget.pluginspec \
    PFDGadget.json
FORMS += pfdgadgetoptionspage.ui
RESOURCES += pfd.qrc

#依赖的库文件
LIBS += -l$$qtLibraryName(Aggregation)\
        -l$$qtLibraryName(Core)\
        -l$$qtLibraryName(ExtensionSystem)\
        -l$$qtLibraryName(Utils)\
        -l$$qtLibraryName(UAVObjects)


#指定生成的plugin保存目录
DESTDIR=$$PROJECT_PLUGINSDIR
