TEMPLATE = lib
TARGET = opmapwidget
DEFINES += OPMAPWIDGET_LIBRARY
include(../../../../common.pri)


SOURCES += mapgraphicitem.cpp \
    opmapwidget.cpp \
    configuration.cpp \
    waypointitem.cpp \
    uavitem.cpp \
    gpsitem.cpp \
    trailitem.cpp \
    homeitem.cpp \
    mapripform.cpp \
    mapripper.cpp \
    traillineitem.cpp \
    waypointline.cpp \
    waypointcircle.cpp

LIBS += -L../build \
    -lcore \
    -linternals \
    -lcore


POST_TARGETDEPS  += ../build/libcore.a
POST_TARGETDEPS  += ../build/libinternals.a

HEADERS += mapgraphicitem.h \
    opmapwidget.h \
    configuration.h \
    waypointitem.h \
    uavitem.h \
    gpsitem.h \
    uavmapfollowtype.h \
    uavtrailtype.h \
    trailitem.h \
    homeitem.h \
    mapripform.h \
    mapripper.h \
    traillineitem.h \
    waypointline.h \
    waypointcircle.h
QT += opengl
QT += network
QT += sql
QT += svg
RESOURCES += mapresources.qrc

FORMS += \
    mapripform.ui
