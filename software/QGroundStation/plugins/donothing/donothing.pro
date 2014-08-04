
TEMPLATE = lib 
TARGET = DoNothing 
 
include(../../common.pri)
 
HEADERS += donothingplugin.h 
SOURCES += donothingplugin.cpp 
 
OTHER_FILES += DoNothing.pluginspec

#依赖的库文件
LIBS += -l$$qtLibraryName(Core)\
        -l$$qtLibraryName(Aggregation)\
        -l$$qtLibraryName(Utils)\
        -l$$qtLibraryName(ExtensionSystem)

#指定生成的plugin保存目录
DESTDIR=$$PROJECT_PLUGINSDIR
