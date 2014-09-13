TEMPLATE = lib
TARGET = ImportExportGadget
DEFINES += IMPORTEXPORT_LIBRARY

QT +=  core gui xml

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

include(../../common.pri)

HEADERS += importexportplugin.h \
    importexportgadgetwidget.h \
    importexportdialog.h
SOURCES += importexportplugin.cpp \
    importexportgadgetwidget.cpp \
    importexportdialog.cpp
OTHER_FILES += ImportExportGadget.pluginspec
FORMS += importexportgadgetwidget.ui \
    importexportdialog.ui

#依赖的库文件
LIBS += -l$$qtLibraryName(Aggregation)\
        -l$$qtLibraryName(Core)\
        -l$$qtLibraryName(ExtensionSystem)\
        -l$$qtLibraryName(Utils)

#指定生成的plugin保存目录
DESTDIR=$${PROJECT_PLUGINSDIR}
