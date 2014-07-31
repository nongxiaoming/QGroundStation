/**
 ******************************************************************************
 *
 * @file       relaytuning.h
 * @author     The OpenPilot Team, http://www.openpilot.org Copyright (C) 2010.
 * @see        The GNU Public License (GPL) Version 3
 * @addtogroup GCSPlugins GCS Plugins
 * @{
 * @addtogroup UAVObjectsPlugin UAVObjects Plugin
 * @{
 *   
 * @note       Object definition file: relaytuning.xml. 
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
#ifndef RELAYTUNING_H
#define RELAYTUNING_H

#include "uavobjects/uavdataobject.h"
#include "uavobjects/uavobjectmanager.h"

class UAVOBJECTS_EXPORT RelayTuning: public UAVDataObject
{
    Q_OBJECT
    Q_PROPERTY(float Period_Roll READ getPeriod_Roll WRITE setPeriod_Roll NOTIFY Period_RollChanged);
    Q_PROPERTY(float Period_Pitch READ getPeriod_Pitch WRITE setPeriod_Pitch NOTIFY Period_PitchChanged);
    Q_PROPERTY(float Period_Yaw READ getPeriod_Yaw WRITE setPeriod_Yaw NOTIFY Period_YawChanged);
    Q_PROPERTY(float Gain_Roll READ getGain_Roll WRITE setGain_Roll NOTIFY Gain_RollChanged);
    Q_PROPERTY(float Gain_Pitch READ getGain_Pitch WRITE setGain_Pitch NOTIFY Gain_PitchChanged);
    Q_PROPERTY(float Gain_Yaw READ getGain_Yaw WRITE setGain_Yaw NOTIFY Gain_YawChanged);


public:
    // Field structure
    typedef struct {
        float Period[3];
        float Gain[3];

    } __attribute__((packed)) DataFields;

    // Field information
    // Field Period information
    /* Array element names for field Period */
    typedef enum { PERIOD_ROLL=0, PERIOD_PITCH=1, PERIOD_YAW=2 } PeriodElem;
    /* Number of elements for field Period */
    static const quint32 PERIOD_NUMELEM = 3;
    // Field Gain information
    /* Array element names for field Gain */
    typedef enum { GAIN_ROLL=0, GAIN_PITCH=1, GAIN_YAW=2 } GainElem;
    /* Number of elements for field Gain */
    static const quint32 GAIN_NUMELEM = 3;

  
    // Constants
    static const quint32 OBJID = 0xF6EE61BE;
    static const QString NAME;
    static const QString DESCRIPTION;
    static const QString CATEGORY;
    static const bool ISSINGLEINST = 1;
    static const bool ISSETTINGS = 0;
    static const quint32 NUMBYTES = sizeof(DataFields);

    // Functions
    RelayTuning();

    DataFields getData();
    void setData(const DataFields& data);
    Metadata getDefaultMetadata();
    UAVDataObject* clone(quint32 instID);
	UAVDataObject* dirtyClone();
	
    static RelayTuning* GetInstance(UAVObjectManager* objMngr, quint32 instID = 0);

    Q_INVOKABLE float getPeriod(quint32 index) const;
    Q_INVOKABLE float getPeriod_Roll() const;
    Q_INVOKABLE float getPeriod_Pitch() const;
    Q_INVOKABLE float getPeriod_Yaw() const;
    Q_INVOKABLE float getGain(quint32 index) const;
    Q_INVOKABLE float getGain_Roll() const;
    Q_INVOKABLE float getGain_Pitch() const;
    Q_INVOKABLE float getGain_Yaw() const;


public slots:
    void setPeriod(quint32 index, float value);
    void setPeriod_Roll(float value);
    void setPeriod_Pitch(float value);
    void setPeriod_Yaw(float value);
    void setGain(quint32 index, float value);
    void setGain_Roll(float value);
    void setGain_Pitch(float value);
    void setGain_Yaw(float value);


signals:
    void PeriodChanged(quint32 index, float value);
    void Period_RollChanged(float value);
    void Period_PitchChanged(float value);
    void Period_YawChanged(float value);
    void GainChanged(quint32 index, float value);
    void Gain_RollChanged(float value);
    void Gain_PitchChanged(float value);
    void Gain_YawChanged(float value);


private slots:
    void emitNotifications();
	
private:
    DataFields data;

    void setDefaultFieldValues();

};

#endif // RELAYTUNING_H
