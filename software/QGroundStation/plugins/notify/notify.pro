
TEMPLATE = lib 
TARGET = NotifyPlugin 
 
include(../../common.pri)

QT +=  core gui multimedia

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

HEADERS += notifyplugin.h \  
    notifypluginoptionspage.h \
    notifyitemdelegate.h \
    notifytablemodel.h \
    notificationitem.h \
    notifylogging.h

SOURCES += notifyplugin.cpp \  
    notifypluginoptionspage.cpp \
    notifyitemdelegate.cpp \
    notifytablemodel.cpp \
    notificationitem.cpp \
    notifylogging.cpp
 
OTHER_FILES += NotifyPlugin.pluginspec

FORMS += \
    notifypluginoptionspage.ui

RESOURCES += \
    res.qrc


#依赖的库文件
LIBS += -l$$qtLibraryName(Aggregation)\
        -l$$qtLibraryName(Core)\
        -l$$qtLibraryName(ExtensionSystem)\
        -l$$qtLibraryName(Utils)\
        -l$$qtLibraryName(UAVObjects)\
        -l$$qtLibraryName(UAVTalk)


#指定生成的plugin保存目录
DESTDIR=$${PROJECT_PLUGINSDIR}
