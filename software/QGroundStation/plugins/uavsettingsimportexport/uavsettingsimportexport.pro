
TEMPLATE = lib

QT +=  core gui xml

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = UAVSettingsImportExport
DEFINES += UAVSETTINGSIMPORTEXPORT_LIBRARY

include(../../common.pri)

HEADERS += uavsettingsimportexport.h \
    importsummary.h \
    uavsettingsimportexportfactory.h
SOURCES += uavsettingsimportexport.cpp \
    importsummary.cpp \
    uavsettingsimportexportfactory.cpp
 
OTHER_FILES += uavsettingsimportexport.pluginspec

FORMS += \
    importsummarydialog.ui

#依赖的库文件
LIBS *= -l$$qtLibraryName(Aggregation)\
        -l$$qtLibraryName(Core)\
        -l$$qtLibraryName(ExtensionSystem)\
        -l$$qtLibraryName(Utils)\
        -l$$qtLibraryName(UAVObjects)\
        -l$$qtLibraryName(UAVObjectUtil)\
        -l$$qtLibraryName(VersionInfo)

#指定生成的plugin保存目录
DESTDIR=$$PROJECT_PLUGINSDIR
