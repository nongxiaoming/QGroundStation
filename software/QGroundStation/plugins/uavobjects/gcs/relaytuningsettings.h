/**
 ******************************************************************************
 *
 * @file       relaytuningsettings.h
 * @author     The OpenPilot Team, http://www.openpilot.org Copyright (C) 2010.
 * @see        The GNU Public License (GPL) Version 3
 * @addtogroup GCSPlugins GCS Plugins
 * @{
 * @addtogroup UAVObjectsPlugin UAVObjects Plugin
 * @{
 *   
 * @note       Object definition file: relaytuningsettings.xml. 
 *             This is an automatically generated file.
 *             DO NOT modify manually.
 *
 * @brief      The UAVUObjects GCS plugin 
 *****************************************************************************/
/* 
 * This program is free software; you can redistribute it and/or modify 
 * it under the terms of the GNU General Public License as published by 
 * the Free Software Foundation; either version 3 of the License, or 
 * (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful, but 
 * WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY 
 * or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License 
 * for more details.
 * 
 * You should have received a copy of the GNU General Public License along 
 * with this program; if not, write to the Free Software Foundation, Inc., 
 * 59 Temple Place, Suite 330, Boston, MA 02111-1307 USA
 */
#ifndef RELAYTUNINGSETTINGS_H
#define RELAYTUNINGSETTINGS_H

#include "uavdataobject.h"
#include "uavobjectmanager.h"

class UAVOBJECTS_EXPORT RelayTuningSettings: public UAVDataObject
{
    Q_OBJECT
    Q_PROPERTY(float RateGain READ getRateGain WRITE setRateGain NOTIFY RateGainChanged);
    Q_PROPERTY(float AttitudeGain READ getAttitudeGain WRITE setAttitudeGain NOTIFY AttitudeGainChanged);
    Q_PROPERTY(float Amplitude READ getAmplitude WRITE setAmplitude NOTIFY AmplitudeChanged);
    Q_PROPERTY(quint8 HysteresisThresh READ getHysteresisThresh WRITE setHysteresisThresh NOTIFY HysteresisThreshChanged);
    Q_PROPERTY(quint8 Mode READ getMode WRITE setMode NOTIFY ModeChanged);
    Q_PROPERTY(quint8 Behavior READ getBehavior WRITE setBehavior NOTIFY BehaviorChanged);


public:
    // Field structure
    typedef struct {
        float RateGain;
        float AttitudeGain;
        float Amplitude;
        quint8 HysteresisThresh;
        quint8 Mode;
        quint8 Behavior;

    } __attribute__((packed)) DataFields;

    // Field information
    // Field RateGain information
    // Field AttitudeGain information
    // Field Amplitude information
    // Field HysteresisThresh information
    // Field Mode information
    /* Enumeration options for field Mode */
    typedef enum { MODE_RATE=0, MODE_ATTITUDE=1 } ModeOptions;
    // Field Behavior information
    /* Enumeration options for field Behavior */
    typedef enum { BEHAVIOR_MEASURE=0, BEHAVIOR_COMPUTE=1, BEHAVIOR_SAVE=2 } BehaviorOptions;

  
    // Constants
    static const quint32 OBJID = 0xEA358166;
    static const QString NAME;
    static const QString DESCRIPTION;
    static const QString CATEGORY;
    static const bool ISSINGLEINST = 1;
    static const bool ISSETTINGS = 1;
    static const quint32 NUMBYTES = sizeof(DataFields);

    // Functions
    RelayTuningSettings();

    DataFields getData();
    void setData(const DataFields& data);
    Metadata getDefaultMetadata();
    UAVDataObject* clone(quint32 instID);
	UAVDataObject* dirtyClone();
	
    static RelayTuningSettings* GetInstance(UAVObjectManager* objMngr, quint32 instID = 0);

    Q_INVOKABLE float getRateGain() const;
    Q_INVOKABLE float getAttitudeGain() const;
    Q_INVOKABLE float getAmplitude() const;
    Q_INVOKABLE quint8 getHysteresisThresh() const;
    Q_INVOKABLE quint8 getMode() const;
    Q_INVOKABLE quint8 getBehavior() const;


public slots:
    void setRateGain(float value);
    void setAttitudeGain(float value);
    void setAmplitude(float value);
    void setHysteresisThresh(quint8 value);
    void setMode(quint8 value);
    void setBehavior(quint8 value);


signals:
    void RateGainChanged(float value);
    void AttitudeGainChanged(float value);
    void AmplitudeChanged(float value);
    void HysteresisThreshChanged(quint8 value);
    void ModeChanged(quint8 value);
    void BehaviorChanged(quint8 value);


private slots:
    void emitNotifications();
	
private:
    DataFields data;

    void setDefaultFieldValues();

};

#endif // RELAYTUNINGSETTINGS_H
