TEMPLATE = lib
TARGET = OPMapControl

QT +=  core gui network sql opengl svg

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

include(../../common.pri)

DEFINES += OPMAPCONTROL_LIBRARY

HEADERS += opmapcontrol.h \
           core/accessmode.h \
           core/alllayersoftype.h \
           core/cache.h \
           core/cacheitemqueue.h \
           core/debugheader.h \
           core/diagnostics.h \
           core/geodecoderstatus.h \
           core/kibertilecache.h \
           core/languagetype.h \
           core/maptype.h \
           core/memorycache.h \
           core/opmaps.h \
           core/placemark.h \
           core/point.h \
           core/providerstrings.h \
           core/pureimage.h \
           core/pureimagecache.h \
           core/rawtile.h \
           core/size.h \
           core/tilecachequeue.h \
           core/urlfactory.h \
           internals/copyrightstrings.h \
           internals/core.h \
           internals/debugheader.h \
           internals/loadtask.h \
           internals/mousewheelzoomtype.h \
           internals/pointlatlng.h \
           internals/pureprojection.h \
           internals/rectangle.h \
           internals/rectlatlng.h \
           internals/sizelatlng.h \
           internals/tile.h \
           internals/tilematrix.h \
           mapwidget/configuration.h \
           mapwidget/gpsitem.h \
           mapwidget/homeitem.h \
           mapwidget/mapgraphicitem.h \
           mapwidget/mapripform.h \
           mapwidget/mapripper.h \
           mapwidget/opmapwidget.h \
           mapwidget/trailitem.h \
           mapwidget/traillineitem.h \
           mapwidget/uavitem.h \
           mapwidget/uavmapfollowtype.h \
           mapwidget/uavtrailtype.h \
           mapwidget/waypointitem.h \
           internals/projections/lks94projection.h \
           internals/projections/mercatorprojection.h \
           internals/projections/mercatorprojectionyandex.h \
           internals/projections/platecarreeprojection.h \
           internals/projections/platecarreeprojectionpergo.h \
           mapwidget/waypointlineitem.h
FORMS +=   mapwidget/mapripform.ui
SOURCES += core/alllayersoftype.cpp \
           core/cache.cpp \
           core/cacheitemqueue.cpp \
           core/diagnostics.cpp \
           core/kibertilecache.cpp \
           core/languagetype.cpp \
           core/memorycache.cpp \
           core/opmaps.cpp \
           core/placemark.cpp \
           core/point.cpp \
           core/providerstrings.cpp \
           core/pureimage.cpp \
           core/pureimagecache.cpp \
           core/rawtile.cpp \
           core/size.cpp \
           core/tilecachequeue.cpp \
           core/urlfactory.cpp \
           internals/core.cpp \
           internals/loadtask.cpp \
           internals/MouseWheelZoomType.cpp \
           internals/pointlatlng.cpp \
           internals/pureprojection.cpp \
           internals/rectangle.cpp \
           internals/rectlatlng.cpp \
           internals/sizelatlng.cpp \
           internals/tile.cpp \
           internals/tilematrix.cpp \
           mapwidget/configuration.cpp \
           mapwidget/gpsitem.cpp \
           mapwidget/homeitem.cpp \
           mapwidget/mapgraphicitem.cpp \
           mapwidget/mapripform.cpp \
           mapwidget/mapripper.cpp \
           mapwidget/opmapwidget.cpp \
           mapwidget/trailitem.cpp \
           mapwidget/traillineitem.cpp \
           mapwidget/uavitem.cpp \
           mapwidget/waypointitem.cpp \
           internals/projections/lks94projection.cpp \
           internals/projections/mercatorprojection.cpp \
           internals/projections/mercatorprojectionyandex.cpp \
           internals/projections/platecarreeprojection.cpp \
           internals/projections/platecarreeprojectionpergo.cpp \
           mapwidget/waypointlineitem.cpp
RESOURCES += mapwidget/mapresources.qrc


#依赖的库文件
LIBS += -l$$qtLibraryName(Utils)

#指定生成的lib保存目录
DESTDIR=$${PROJECT_LIBRARYDIR}
