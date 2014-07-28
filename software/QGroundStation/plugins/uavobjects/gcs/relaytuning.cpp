/**
 ******************************************************************************
 *
 * @file       relaytuning.cpp
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

#include "relaytuning.h"
#include "uavobjectfield.h"

const QString RelayTuning::NAME = QString("RelayTuning");
const QString RelayTuning::DESCRIPTION = QString("The input to the relay tuning.");
const QString RelayTuning::CATEGORY = QString("Control");

/**
 * Constructor
 */
RelayTuning::RelayTuning(): UAVDataObject(OBJID, ISSINGLEINST, ISSETTINGS, NAME)
{
    // Create fields
    QList<UAVObjectField *> fields;
    QStringList PeriodElemNames;
    PeriodElemNames.append("Roll");
    PeriodElemNames.append("Pitch");
    PeriodElemNames.append("Yaw");
    fields.append( new UAVObjectField(QString("Period"), QString("ms"), UAVObjectField::FLOAT32, PeriodElemNames, QStringList(), QString("")));
    QStringList GainElemNames;
    GainElemNames.append("Roll");
    GainElemNames.append("Pitch");
    GainElemNames.append("Yaw");
    fields.append( new UAVObjectField(QString("Gain"), QString("(deg/s)/output"), UAVObjectField::FLOAT32, GainElemNames, QStringList(), QString("")));

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
UAVObject::Metadata RelayTuning::getDefaultMetadata()
{
    UAVObject::Metadata metadata;
    metadata.flags =
        ACCESS_READWRITE << UAVOBJ_ACCESS_SHIFT |
        ACCESS_READONLY << UAVOBJ_GCS_ACCESS_SHIFT |
        0 << UAVOBJ_TELEMETRY_ACKED_SHIFT |
        0 << UAVOBJ_GCS_TELEMETRY_ACKED_SHIFT |
        UPDATEMODE_PERIODIC << UAVOBJ_TELEMETRY_UPDATE_MODE_SHIFT |
        UPDATEMODE_MANUAL << UAVOBJ_GCS_TELEMETRY_UPDATE_MODE_SHIFT |
        UPDATEMODE_MANUAL << UAVOBJ_LOGGING_UPDATE_MODE_SHIFT;
    metadata.flightTelemetryUpdatePeriod = 1000;
    metadata.gcsTelemetryUpdatePeriod = 0;
    metadata.loggingUpdatePeriod = 0;
    return metadata;
}

/**
 * Initialize object fields with the default values.
 * If a default value is not specified the object fields
 * will be initialized to zero.
 */
void RelayTuning::setDefaultFieldValues()
{

}

/**
 * Get the object data fields
 */
RelayTuning::DataFields RelayTuning::getData()
{
    QMutexLocker locker(mutex);
    return data;
}

/**
 * Set the object data fields
 */
void RelayTuning::setData(const DataFields& data)
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

void RelayTuning::emitNotifications()
{
            //if (data.Period[0] != oldData.Period[0])
            emit Period_RollChanged(data.Period[0]);
        //if (data.Period[1] != oldData.Period[1])
            emit Period_PitchChanged(data.Period[1]);
        //if (data.Period[2] != oldData.Period[2])
            emit Period_YawChanged(data.Period[2]);
        //if (data.Gain[0] != oldData.Gain[0])
            emit Gain_RollChanged(data.Gain[0]);
        //if (data.Gain[1] != oldData.Gain[1])
            emit Gain_PitchChanged(data.Gain[1]);
        //if (data.Gain[2] != oldData.Gain[2])
            emit Gain_YawChanged(data.Gain[2]);

}

/**
 * Create a clone of this object, a new instance ID must be specified.
 * Do not use this function directly to create new instances, the
 * UAVObjectManager should be used instead.
 */
UAVDataObject *RelayTuning::clone(quint32 instID)
{
    RelayTuning *obj = new RelayTuning();
    obj->initialize(instID, this->getMetaObject());
    return obj;
}

/**
 * Create a clone of this object only to be used to retrieve defaults
 */
UAVDataObject *RelayTuning::dirtyClone()
{
    RelayTuning *obj = new RelayTuning();
    return obj;
}

/**
 * Static function to retrieve an instance of the object.
 */
RelayTuning *RelayTuning::GetInstance(UAVObjectManager *objMngr, quint32 instID)
{
    return dynamic_cast<RelayTuning *>(objMngr->getObject(RelayTuning::OBJID, instID));
}

float RelayTuning::getPeriod(quint32 index) const
{
   QMutexLocker locker(mutex);
   return data.Period[index];
}
void RelayTuning::setPeriod(quint32 index, float value)
{
   mutex->lock();
   bool changed = data.Period[index] != value;
   data.Period[index] = value;
   mutex->unlock();
   if (changed) emit PeriodChanged(index,value);
}

float RelayTuning::getPeriod_Roll() const
{
   QMutexLocker locker(mutex);
   return data.Period[0];
}
void RelayTuning::setPeriod_Roll(float value)
{
   mutex->lock();
   bool changed = data.Period[0] != value;
   data.Period[0] = value;
   mutex->unlock();
   if (changed) emit Period_RollChanged(value);
}

float RelayTuning::getPeriod_Pitch() const
{
   QMutexLocker locker(mutex);
   return data.Period[1];
}
void RelayTuning::setPeriod_Pitch(float value)
{
   mutex->lock();
   bool changed = data.Period[1] != value;
   data.Period[1] = value;
   mutex->unlock();
   if (changed) emit Period_PitchChanged(value);
}

float RelayTuning::getPeriod_Yaw() const
{
   QMutexLocker locker(mutex);
   return data.Period[2];
}
void RelayTuning::setPeriod_Yaw(float value)
{
   mutex->lock();
   bool changed = data.Period[2] != value;
   data.Period[2] = value;
   mutex->unlock();
   if (changed) emit Period_YawChanged(value);
}

float RelayTuning::getGain(quint32 index) const
{
   QMutexLocker locker(mutex);
   return data.Gain[index];
}
void RelayTuning::setGain(quint32 index, float value)
{
   mutex->lock();
   bool changed = data.Gain[index] != value;
   data.Gain[index] = value;
   mutex->unlock();
   if (changed) emit GainChanged(index,value);
}

float RelayTuning::getGain_Roll() const
{
   QMutexLocker locker(mutex);
   return data.Gain[0];
}
void RelayTuning::setGain_Roll(float value)
{
   mutex->lock();
   bool changed = data.Gain[0] != value;
   data.Gain[0] = value;
   mutex->unlock();
   if (changed) emit Gain_RollChanged(value);
}

float RelayTuning::getGain_Pitch() const
{
   QMutexLocker locker(mutex);
   return data.Gain[1];
}
void RelayTuning::setGain_Pitch(float value)
{
   mutex->lock();
   bool changed = data.Gain[1] != value;
   data.Gain[1] = value;
   mutex->unlock();
   if (changed) emit Gain_PitchChanged(value);
}

float RelayTuning::getGain_Yaw() const
{
   QMutexLocker locker(mutex);
   return data.Gain[2];
}
void RelayTuning::setGain_Yaw(float value)
{
   mutex->lock();
   bool changed = data.Gain[2] != value;
   data.Gain[2] = value;
   mutex->unlock();
   if (changed) emit Gain_YawChanged(value);
}


