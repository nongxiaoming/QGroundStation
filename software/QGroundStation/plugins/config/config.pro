TEMPLATE = lib
TARGET = Config
DEFINES += CONFIG_LIBRARY

QT += svg opengl qml quick

include(../../common.pri)

INCLUDEPATH += ../../thirdparty/eigen

OTHER_FILES += \
    Config.pluginspec \
    calibration/WizardStepIndicator.qml

HEADERS += \
    configplugin.h \
    configgadgetwidget.h \
    configgadgetfactory.h \
    configgadget.h \
    fancytabwidget.h \
    configinputwidget.h \
    configoutputwidget.h \
    configvehicletypewidget.h \
    config_cc_hw_widget.h \
    configccattitudewidget.h \
    configpipxtremewidget.h \
    configstabilizationwidget.h \
    assertions.h \
    defaultattitudewidget.h \
    defaulthwsettingswidget.h \
    channelform.h \
    inputchannelform.h \
    configcamerastabilizationwidget.h \
    configtxpidwidget.h \
    outputchannelform.h \    
    cfg_vehicletypes/vehicleconfig.h \
    cfg_vehicletypes/configccpmwidget.h \
    cfg_vehicletypes/configmultirotorwidget.h \
    cfg_vehicletypes/configfixedwingwidget.h \
    cfg_vehicletypes/configgroundvehiclewidget.h \
    cfg_vehicletypes/configcustomwidget.h \
    configrevowidget.h \
    config_global.h \
    mixercurve.h \
    dblspindelegate.h \
    configrevohwwidget.h \
    calibration/calibrationutils.h \
    calibration/wizardstate.h \
    calibration/wizardmodel.h \
    calibration/thermal/thermalcalibration.h \
    calibration/thermal/thermalcalibrationhelper.h \
    calibration/thermal/thermalcalibrationmodel.h \
    calibration/thermal/boardsetuptransition.h \
    calibration/thermal/dataacquisitiontransition.h \
    calibration/thermal/settingshandlingtransitions.h \
    calibration/thermal/compensationcalculationtransition.h \
    calibration/sixpointcalibrationmodel.h \
    calibration/levelcalibrationmodel.h \
    calibration/gyrobiascalibrationmodel.h \
    calibration/calibrationuiutils.h

SOURCES += \
    configplugin.cpp \
    configgadgetwidget.cpp \
    configgadgetfactory.cpp \
    configgadget.cpp \
    fancytabwidget.cpp \
    configinputwidget.cpp \
    configoutputwidget.cpp \
    configvehicletypewidget.cpp \
    config_cc_hw_widget.cpp \
    configccattitudewidget.cpp \
    configstabilizationwidget.cpp \
    configpipxtremewidget.cpp \
    defaultattitudewidget.cpp \
    defaulthwsettingswidget.cpp \
    channelform.cpp \
    inputchannelform.cpp \
    configcamerastabilizationwidget.cpp \
    configrevowidget.cpp \
    configtxpidwidget.cpp \
    cfg_vehicletypes/vehicleconfig.cpp \
    cfg_vehicletypes/configccpmwidget.cpp \
    cfg_vehicletypes/configmultirotorwidget.cpp \
    cfg_vehicletypes/configfixedwingwidget.cpp \
    cfg_vehicletypes/configgroundvehiclewidget.cpp \
    cfg_vehicletypes/configcustomwidget.cpp \
    outputchannelform.cpp \
    mixercurve.cpp \
    dblspindelegate.cpp \
    configrevohwwidget.cpp \
    calibration/calibrationutils.cpp \
    calibration/wizardstate.cpp \
    calibration/wizardmodel.cpp \
    calibration/thermal/thermalcalibration.cpp \
    calibration/thermal/thermalcalibrationhelper.cpp \
    calibration/thermal/thermalcalibrationmodel.cpp \
    calibration/sixpointcalibrationmodel.cpp \
    calibration/levelcalibrationmodel.cpp \
    calibration/gyrobiascalibrationmodel.cpp

FORMS += \
    airframe.ui \
    airframe_ccpm.ui \
    airframe_fixedwing.ui \
    airframe_ground.ui \
    airframe_multirotor.ui \
    airframe_custom.ui \
    cc_hw_settings.ui \
    stabilization.ui \
    input.ui \
    output.ui \
    ccattitude.ui \
    defaultattitude.ui \
    defaulthwsettings.ui \
    inputchannelform.ui \
    camerastabilization.ui \
    outputchannelform.ui \
    revosensors.ui \
    txpid.ui \
    pipxtreme.ui \
    mixercurve.ui \
    configrevohwwidget.ui

RESOURCES += configgadget.qrc

#依赖的库文件
LIBS += -l$$qtLibraryName(Core)\
        -l$$qtLibraryName(Aggregation)\
        -l$$qtLibraryName(Utils)\
        -l$$qtLibraryName(ExtensionSystem)\
        -l$$qtLibraryName(UAVObjects)\
        -l$$qtLibraryName(UAVObjectUtil)\
        -l$$qtLibraryName(Telemetry)\
        -l$$qtLibraryName(UAVTalk)\
        -l$$qtLibraryName(UAVSettingsImportExport)\
        -l$$qtLibraryName(UAVObjectWidgetUtils)\
        -l$$qtLibraryName(VersionInfo)

#指定生成的plugin保存目录
DESTDIR=$$PROJECT_PLUGINSDIR
