/**
 ******************************************************************************
 *
 * @file       nedaccel.cpp
 * @author     The OpenPilot Team, http://www.openpilot.org Copyright (C) 2010.
 * @see        The GNU Public License (GPL) Version 3
 * @addtogroup GCSPlugins GCS Plugins
 * @{
 * @addtogroup UAVObjectsPlugin UAVObjects Plugin
 * @{
 *
 * @note       Object definition file: nedaccel.xml.
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

#include "nedaccel.h"
#include "uavobjectfield.h"

const QString NedAccel::NAME = QString("NedAccel");
const QString NedAccel::DESCRIPTION = QString("The projection of acceleration in the NED reference frame used by @ref Guidance.");
const QString NedAccel::CATEGORY = QString("State");

/**
 * Constructor
 */
NedAccel::NedAccel(): UAVDataObject(OBJID, ISSINGLEINST, ISSETTINGS, NAME)
{
    // Create fields
    QList<UAVObjectField *> fields;
    QStringList NorthElemNames;
    NorthElemNames.append("0");
    fields.append( new UAVObjectField(QString("North"), QString("m/s^2"), UAVObjectField::FLOAT32, NorthElemNames, QStringList(), QString("")));
    QStringList EastElemNames;
    EastElemNames.append("0");
    fields.append( new UAVObjectField(QString("East"), QString("m/s^2"), UAVObjectField::FLOAT32, EastElemNames, QStringList(), QString("")));
    QStringList DownElemNames;
    DownElemNames.append("0");
    fields.append( new UAVObjectField(QString("Down"), QString("m/s^2"), UAVObjectField::FLOAT32, DownElemNames, QStringList(), QString("")));

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
UAVObject::Metadata NedAccel::getDefaultMetadata()
{
    UAVObject::Metadata metadata;
    metadata.flags =
        ACCESS_READWRITE << UAVOBJ_ACCESS_SHIFT |
        ACCESS_READWRITE << UAVOBJ_GCS_ACCESS_SHIFT |
        0 << UAVOBJ_TELEMETRY_ACKED_SHIFT |
        0 << UAVOBJ_GCS_TELEMETRY_ACKED_SHIFT |
        UPDATEMODE_PERIODIC << UAVOBJ_TELEMETRY_UPDATE_MODE_SHIFT |
        UPDATEMODE_MANUAL << UAVOBJ_GCS_TELEMETRY_UPDATE_MODE_SHIFT |
        UPDATEMODE_MANUAL << UAVOBJ_LOGGING_UPDATE_MODE_SHIFT;
    metadata.flightTelemetryUpdatePeriod = 10001;
    metadata.gcsTelemetryUpdatePeriod = 0;
    metadata.loggingUpdatePeriod = 0;
    return metadata;
}

/**
 * Initialize object fields with the default values.
 * If a default value is not specified the object fields
 * will be initialized to zero.
 */
void NedAccel::setDefaultFieldValues()
{

}

/**
 * Get the object data fields
 */
NedAccel::DataFields NedAccel::getData()
{
    QMutexLocker locker(mutex);
    return data;
}

/**
 * Set the object data fields
 */
void NedAccel::setData(const DataFields& data)
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

void NedAccel::emitNotifications()
{
            //if (data.North != oldData.North)
            emit NorthChanged(data.North);
        //if (data.East != oldData.East)
            emit EastChanged(data.East);
        //if (data.Down != oldData.Down)
            emit DownChanged(data.Down);

}

/**
 * Create a clone of this object, a new instance ID must be specified.
 * Do not use this function directly to create new instances, the
 * UAVObjectManager should be used instead.
 */
UAVDataObject *NedAccel::clone(quint32 instID)
{
    NedAccel *obj = new NedAccel();
    obj->initialize(instID, this->getMetaObject());
    return obj;
}

/**
 * Create a clone of this object only to be used to retrieve defaults
 */
UAVDataObject *NedAccel::dirtyClone()
{
    NedAccel *obj = new NedAccel();
    return obj;
}

/**
 * Static function to retrieve an instance of the object.
 */
NedAccel *NedAccel::GetInstance(UAVObjectManager *objMngr, quint32 instID)
{
    return dynamic_cast<NedAccel *>(objMngr->getObject(NedAccel::OBJID, instID));
}

float NedAccel::getNorth() const
{
   QMutexLocker locker(mutex);
   return data.North;
}
void NedAccel::setNorth(float value)
{
   mutex->lock();
   bool changed = data.North != value;
   data.North = value;
   mutex->unlock();
   if (changed) emit NorthChanged(value);
}

float NedAccel::getEast() const
{
   QMutexLocker locker(mutex);
   return data.East;
}
void NedAccel::setEast(float value)
{
   mutex->lock();
   bool changed = data.East != value;
   data.East = value;
   mutex->unlock();
   if (changed) emit EastChanged(value);
}

float NedAccel::getDown() const
{
   QMutexLocker locker(mutex);
   return data.Down;
}
void NedAccel::setDown(float value)
{
   mutex->lock();
   bool changed = data.Down != value;
   data.Down = value;
   mutex->unlock();
   if (changed) emit DownChanged(value);
}


