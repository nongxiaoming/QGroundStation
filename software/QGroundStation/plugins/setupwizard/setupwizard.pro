
TEMPLATE = lib 
TARGET = SetupWizard 
QT += svg


include(../../common.pri)


LIBS *= -l$$qtLibraryName(Uploader)
HEADERS += setupwizardplugin.h \ 
    setupwizard.h \
    pages/opstartpage.h \
    pages/opendpage.h \
    pages/controllerpage.h \
    pages/vehiclepage.h \
    pages/notyetimplementedpage.h \
    pages/multipage.h \
    pages/fixedwingpage.h \
    pages/helipage.h \
    pages/surfacepage.h \
    pages/abstractwizardpage.h \
    pages/outputpage.h \
    pages/inputpage.h \
    pages/summarypage.h \
    vehicleconfigurationsource.h \
    vehicleconfigurationhelper.h \
    connectiondiagram.h \
    pages/outputcalibrationpage.h \
    outputcalibrationutil.h \
    pages/rebootpage.h \
    pages/savepage.h \
    pages/autoupdatepage.h \
    pages/revocalibrationpage.h \
    biascalibrationutil.h \
    pages/biascalibrationpage.h

SOURCES += setupwizardplugin.cpp \
    setupwizard.cpp \
    pages/opstartpage.cpp \
    pages/opendpage.cpp \
    pages/controllerpage.cpp \
    pages/vehiclepage.cpp \
    pages/notyetimplementedpage.cpp \
    pages/multipage.cpp \
    pages/fixedwingpage.cpp \
    pages/helipage.cpp \
    pages/surfacepage.cpp \
    pages/abstractwizardpage.cpp \
    pages/outputpage.cpp \
    pages/inputpage.cpp \
    pages/summarypage.cpp \
    vehicleconfigurationsource.cpp \
    vehicleconfigurationhelper.cpp \
    connectiondiagram.cpp \
    pages/outputcalibrationpage.cpp \
    outputcalibrationutil.cpp \
    pages/rebootpage.cpp \
    pages/savepage.cpp \
    pages/autoupdatepage.cpp \
    pages/revocalibrationpage.cpp \
    biascalibrationutil.cpp \
    pages/biascalibrationpage.cpp

OTHER_FILES += SetupWizard.pluginspec

FORMS += \
    pages/opstartpage.ui \
    pages/opendpage.ui \
    pages/controllerpage.ui \
    pages/vehiclepage.ui \
    pages/notyetimplementedpage.ui \
    pages/multipage.ui \
    pages/fixedwingpage.ui \
    pages/helipage.ui \
    pages/surfacepage.ui \
    pages/outputpage.ui \
    pages/inputpage.ui \
    pages/summarypage.ui \
    connectiondiagram.ui \
    pages/outputcalibrationpage.ui \
    pages/rebootpage.ui \
    pages/savepage.ui \
    pages/autoupdatepage.ui \
    pages/revocalibrationpage.ui \
    pages/biascalibrationpage.ui

RESOURCES += \
    wizardResources.qrc

#依赖的库文件
LIBS += -l$$qtLibraryName(Aggregation)\
        -l$$qtLibraryName(Core)\
        -l$$qtLibraryName(ExtensionSystem)\
        -l$$qtLibraryName(Utils)\
        -l$$qtLibraryName(UAVObjects)\
        -l$$qtLibraryName(UAVTalk)\
        -l$$qtLibraryName(UAVObjectUtil)\
        -l$$qtLibraryName(UAVSettingsImportExport)\
        -l$$qtLibraryName(Config)

#指定生成的lib保存目录
DESTDIR=$${PROJECT_PLUGINSDIR}
