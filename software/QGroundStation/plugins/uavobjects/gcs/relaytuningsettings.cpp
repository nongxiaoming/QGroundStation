/**
 ******************************************************************************
 *
 * @file       relaytuningsettings.cpp
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

#include "relaytuningsettings.h"
#include "uavobjectfield.h"

const QString RelayTuningSettings::NAME = QString("RelayTuningSettings");
const QString RelayTuningSettings::DESCRIPTION = QString("Setting to run a relay tuning algorithm");
const QString RelayTuningSettings::CATEGORY = QString("Control");

/**
 * Constructor
 */
RelayTuningSettings::RelayTuningSettings(): UAVDataObject(OBJID, ISSINGLEINST, ISSETTINGS, NAME)
{
    // Create fields
    QList<UAVObjectField *> fields;
    QStringList RateGainElemNames;
    RateGainElemNames.append("0");
    fields.append( new UAVObjectField(QString("RateGain"), QString(""), UAVObjectField::FLOAT32, RateGainElemNames, QStringList(), QString("")));
    QStringList AttitudeGainElemNames;
    AttitudeGainElemNames.append("0");
    fields.append( new UAVObjectField(QString("AttitudeGain"), QString(""), UAVObjectField::FLOAT32, AttitudeGainElemNames, QStringList(), QString("")));
    QStringList AmplitudeElemNames;
    AmplitudeElemNames.append("0");
    fields.append( new UAVObjectField(QString("Amplitude"), QString(""), UAVObjectField::FLOAT32, AmplitudeElemNames, QStringList(), QString("")));
    QStringList HysteresisThreshElemNames;
    HysteresisThreshElemNames.append("0");
    fields.append( new UAVObjectField(QString("HysteresisThresh"), QString("deg/s"), UAVObjectField::UINT8, HysteresisThreshElemNames, QStringList(), QString("")));
    QStringList ModeElemNames;
    ModeElemNames.append("0");
    QStringList ModeEnumOptions;
    ModeEnumOptions.append("Rate");
    ModeEnumOptions.append("Attitude");
    fields.append( new UAVObjectField(QString("Mode"), QString(""), UAVObjectField::ENUM, ModeElemNames, ModeEnumOptions, QString("")));
    QStringList BehaviorElemNames;
    BehaviorElemNames.append("0");
    QStringList BehaviorEnumOptions;
    BehaviorEnumOptions.append("Measure");
    BehaviorEnumOptions.append("Compute");
    BehaviorEnumOptions.append("Save");
    fields.append( new UAVObjectField(QString("Behavior"), QString(""), UAVObjectField::ENUM, BehaviorElemNames, BehaviorEnumOptions, QString("")));

    // Initialize object
    initializeFields(fields, (quint8 *)&data, NUMBYTES);
    // Set the default field values
    setDefaultFieldValues();
    // Set the object description
    setDescription(DESCRIPTION);

    // Set the Category of this object type
    setCategory(CATEGORY);

    connect(this, SIGNAL(objectUpdated(UAVObject *)), SLOT(emitNotifications()));
}

/**
 * Get the default metadata for this object
 */
UAVObject::Metadata RelayTuningSettings::getDefaultMetadata()
{
    UAVObject::Metadata metadata;
    metadata.flags =
        ACCESS_READWRITE << UAVOBJ_ACCESS_SHIFT |
        ACCESS_READWRITE << UAVOBJ_GCS_ACCESS_SHIFT |
        1 << UAVOBJ_TELEMETRY_ACKED_SHIFT |
        1 << UAVOBJ_GCS_TELEMETRY_ACKED_SHIFT |
        UPDATEMODE_ONCHANGE << UAVOBJ_TELEMETRY_UPDATE_MODE_SHIFT |
        UPDATEMODE_ONCHANGE << UAVOBJ_GCS_TELEMETRY_UPDATE_MODE_SHIFT |
        UPDATEMODE_MANUAL << UAVOBJ_LOGGING_UPDATE_MODE_SHIFT;
    metadata.flightTelemetryUpdatePeriod = 0;
    metadata.gcsTelemetryUpdatePeriod = 0;
    metadata.loggingUpdatePeriod = 0;
    return metadata;
}

/**
 * Initialize object fields with the default values.
 * If a default value is not specified the object fields
 * will be initialized to zero.
 */
void RelayTuningSettings::setDefaultFieldValues()
{
    data.RateGain = 0.3333;
    data.AttitudeGain = 0.2;
    data.Amplitude = 0.25;
    data.HysteresisThresh = 5;
    data.Mode = 1;
    data.Behavior = 1;

}

/**
 * Get the object data fields
 */
RelayTuningSettings::DataFields RelayTuningSettings::getData()
{
    QMutexLocker locker(mutex);
    return data;
}

/**
 * Set the object data fields
 */
void RelayTuningSettings::setData(const DataFields& data)
{
    QMutexLocker locker(mutex);
    // Get metadata
    Metadata mdata = getMetadata();
    // Update object if the access mode permits
    if (UAVObject::GetGcsAccess(mdata) == ACCESS_READWRITE) {
        this->data = data;
        emit objectUpdatedAuto(this); // trigger object updated event
        emit objectUpdated(this);
    }
}

void RelayTuningSettings::emitNotifications()
{
            //if (data.RateGain != oldData.RateGain)
            emit RateGainChanged(data.RateGain);
        //if (data.AttitudeGain != oldData.AttitudeGain)
            emit AttitudeGainChanged(data.AttitudeGain);
        //if (data.Amplitude != oldData.Amplitude)
            emit AmplitudeChanged(data.Amplitude);
        //if (data.HysteresisThresh != oldData.HysteresisThresh)
            emit HysteresisThreshChanged(data.HysteresisThresh);
        //if (data.Mode != oldData.Mode)
            emit ModeChanged(data.Mode);
        //if (data.Behavior != oldData.Behavior)
            emit BehaviorChanged(data.Behavior);

}

/**
 * Create a clone of this object, a new instance ID must be specified.
 * Do not use this function directly to create new instances, the
 * UAVObjectManager should be used instead.
 */
UAVDataObject *RelayTuningSettings::clone(quint32 instID)
{
    RelayTuningSettings *obj = new RelayTuningSettings();
    obj->initialize(instID, this->getMetaObject());
    return obj;
}

/**
 * Create a clone of this object only to be used to retrieve defaults
 */
UAVDataObject *RelayTuningSettings::dirtyClone()
{
    RelayTuningSettings *obj = new RelayTuningSettings();
    return obj;
}

/**
 * Static function to retrieve an instance of the object.
 */
RelayTuningSettings *RelayTuningSettings::GetInstance(UAVObjectManager *objMngr, quint32 instID)
{
    return dynamic_cast<RelayTuningSettings *>(objMngr->getObject(RelayTuningSettings::OBJID, instID));
}

float RelayTuningSettings::getRateGain() const
{
   QMutexLocker locker(mutex);
   return data.RateGain;
}
void RelayTuningSettings::setRateGain(float value)
{
   mutex->lock();
   bool changed = data.RateGain != value;
   data.RateGain = value;
   mutex->unlock();
   if (changed) emit RateGainChanged(value);
}

float RelayTuningSettings::getAttitudeGain() const
{
   QMutexLocker locker(mutex);
   return data.AttitudeGain;
}
void RelayTuningSettings::setAttitudeGain(float value)
{
   mutex->lock();
   bool changed = data.AttitudeGain != value;
   data.AttitudeGain = value;
   mutex->unlock();
   if (changed) emit AttitudeGainChanged(value);
}

float RelayTuningSettings::getAmplitude() const
{
   QMutexLocker locker(mutex);
   return data.Amplitude;
}
void RelayTuningSettings::setAmplitude(float value)
{
   mutex->lock();
   bool changed = data.Amplitude != value;
   data.Amplitude = value;
   mutex->unlock();
   if (changed) emit AmplitudeChanged(value);
}

quint8 RelayTuningSettings::getHysteresisThresh() const
{
   QMutexLocker locker(mutex);
   return data.HysteresisThresh;
}
void RelayTuningSettings::setHysteresisThresh(quint8 value)
{
   mutex->lock();
   bool changed = data.HysteresisThresh != value;
   data.HysteresisThresh = value;
   mutex->unlock();
   if (changed) emit HysteresisThreshChanged(value);
}

quint8 RelayTuningSettings::getMode() const
{
   QMutexLocker locker(mutex);
   return data.Mode;
}
void RelayTuningSettings::setMode(quint8 value)
{
   mutex->lock();
   bool changed = data.Mode != value;
   data.Mode = value;
   mutex->unlock();
   if (changed) emit ModeChanged(value);
}

quint8 RelayTuningSettings::getBehavior() const
{
   QMutexLocker locker(mutex);
   return data.Behavior;
}
void RelayTuningSettings::setBehavior(quint8 value)
{
   mutex->lock();
   bool changed = data.Behavior != value;
   data.Behavior = value;
   mutex->unlock();
   if (changed) emit BehaviorChanged(value);
}


