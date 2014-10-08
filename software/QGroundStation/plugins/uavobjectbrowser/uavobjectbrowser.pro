TEMPLATE = lib
TARGET = UAVObjectBrowser

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

include(../../common.pri)

HEADERS += browserplugin.h \
    uavobjectbrowserconfiguration.h \
    uavobjectbrowser.h \
    uavobjectbrowserwidget.h \
    uavobjectbrowserfactory.h \
    uavobjectbrowseroptionspage.h \
    uavobjecttreemodel.h \
    treeitem.h \
    browseritemdelegate.h \
    fieldtreeitem.h
SOURCES += browserplugin.cpp \
    uavobjectbrowserconfiguration.cpp \
    uavobjectbrowser.cpp \
    uavobjectbrowserfactory.cpp \
    uavobjectbrowserwidget.cpp \
    uavobjectbrowseroptionspage.cpp \
    uavobjecttreemodel.cpp \
    treeitem.cpp \
    browseritemdelegate.cpp \
    fieldtreeitem.cpp
OTHER_FILES += UAVObjectBrowser.pluginspec
FORMS += uavobjectbrowser.ui \
    uavobjectbrowseroptionspage.ui \
    viewoptions.ui

RESOURCES += \
    uavobjectbrowser.qrc

#依赖的库文件
LIBS += -l$$qtLibraryName(Aggregation)\
        -l$$qtLibraryName(Core)\
        -l$$qtLibraryName(ExtensionSystem)\
        -l$$qtLibraryName(Utils)\
        -l$$qtLibraryName(UAVObjects)\
        -l$$qtLibraryName(QScienceSpinBox)

#指定生成的lib保存目录
DESTDIR=$${PROJECT_PLUGINSDIR}
