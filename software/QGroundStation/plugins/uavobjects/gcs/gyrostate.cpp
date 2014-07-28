/**
 ******************************************************************************
 *
 * @file       gyrostate.cpp
 * @author     The OpenPilot Team, http://www.openpilot.org Copyright (C) 2010.
 * @see        The GNU Public License (GPL) Version 3
 * @addtogroup GCSPlugins GCS Plugins
 * @{
 * @addtogroup UAVObjectsPlugin UAVObjects Plugin
 * @{
 *
 * @note       Object definition file: gyrostate.xml.
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

#include "gyrostate.h"
#include "uavobjectfield.h"

const QString GyroState::NAME = QString("GyroState");
const QString GyroState::DESCRIPTION = QString("The filtered rotation sensor data.");
const QString GyroState::CATEGORY = QString("State");

/**
 * Constructor
 */
GyroState::GyroState(): UAVDataObject(OBJID, ISSINGLEINST, ISSETTINGS, NAME)
{
    // Create fields
    QList<UAVObjectField *> fields;
    QStringList xElemNames;
    xElemNames.append("0");
    fields.append( new UAVObjectField(QString("x"), QString("deg/s"), UAVObjectField::FLOAT32, xElemNames, QStringList(), QString("")));
    QStringList yElemNames;
    yElemNames.append("0");
    fields.append( new UAVObjectField(QString("y"), QString("deg/s"), UAVObjectField::FLOAT32, yElemNames, QStringList(), QString("")));
    QStringList zElemNames;
    zElemNames.append("0");
    fields.append( new UAVObjectField(QString("z"), QString("deg/s"), UAVObjectField::FLOAT32, zElemNames, QStringList(), QString("")));

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
UAVObject::Metadata GyroState::getDefaultMetadata()
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
void GyroState::setDefaultFieldValues()
{

}

/**
 * Get the object data fields
 */
GyroState::DataFields GyroState::getData()
{
    QMutexLocker locker(mutex);
    return data;
}

/**
 * Set the object data fields
 */
void GyroState::setData(const DataFields& data)
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

void GyroState::emitNotifications()
{
            //if (data.x != oldData.x)
            emit xChanged(data.x);
        //if (data.y != oldData.y)
            emit yChanged(data.y);
        //if (data.z != oldData.z)
            emit zChanged(data.z);

}

/**
 * Create a clone of this object, a new instance ID must be specified.
 * Do not use this function directly to create new instances, the
 * UAVObjectManager should be used instead.
 */
UAVDataObject *GyroState::clone(quint32 instID)
{
    GyroState *obj = new GyroState();
    obj->initialize(instID, this->getMetaObject());
    return obj;
}

/**
 * Create a clone of this object only to be used to retrieve defaults
 */
UAVDataObject *GyroState::dirtyClone()
{
    GyroState *obj = new GyroState();
    return obj;
}

/**
 * Static function to retrieve an instance of the object.
 */
GyroState *GyroState::GetInstance(UAVObjectManager *objMngr, quint32 instID)
{
    return dynamic_cast<GyroState *>(objMngr->getObject(GyroState::OBJID, instID));
}

float GyroState::getx() const
{
   QMutexLocker locker(mutex);
   return data.x;
}
void GyroState::setx(float value)
{
   mutex->lock();
   bool changed = data.x != value;
   data.x = value;
   mutex->unlock();
   if (changed) emit xChanged(value);
}

float GyroState::gety() const
{
   QMutexLocker locker(mutex);
   return data.y;
}
void GyroState::sety(float value)
{
   mutex->lock();
   bool changed = data.y != value;
   data.y = value;
   mutex->unlock();
   if (changed) emit yChanged(value);
}

float GyroState::getz() const
{
   QMutexLocker locker(mutex);
   return data.z;
}
void GyroState::setz(float value)
{
   mutex->lock();
   bool changed = data.z != value;
   data.z = value;
   mutex->unlock();
   if (changed) emit zChanged(value);
}


