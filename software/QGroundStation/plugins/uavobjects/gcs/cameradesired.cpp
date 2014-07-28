/**
 ******************************************************************************
 *
 * @file       cameradesired.cpp
 * @author     The OpenPilot Team, http://www.openpilot.org Copyright (C) 2010.
 * @see        The GNU Public License (GPL) Version 3
 * @addtogroup GCSPlugins GCS Plugins
 * @{
 * @addtogroup UAVObjectsPlugin UAVObjects Plugin
 * @{
 *
 * @note       Object definition file: cameradesired.xml.
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

#include "cameradesired.h"
#include "uavobjectfield.h"

const QString CameraDesired::NAME = QString("CameraDesired");
const QString CameraDesired::DESCRIPTION = QString("Desired camera outputs.  Comes from @ref CameraStabilization module.");
const QString CameraDesired::CATEGORY = QString("Control");

/**
 * Constructor
 */
CameraDesired::CameraDesired(): UAVDataObject(OBJID, ISSINGLEINST, ISSETTINGS, NAME)
{
    // Create fields
    QList<UAVObjectField *> fields;
    QStringList RollOrServo1ElemNames;
    RollOrServo1ElemNames.append("0");
    fields.append( new UAVObjectField(QString("RollOrServo1"), QString(""), UAVObjectField::FLOAT32, RollOrServo1ElemNames, QStringList(), QString("")));
    QStringList PitchOrServo2ElemNames;
    PitchOrServo2ElemNames.append("0");
    fields.append( new UAVObjectField(QString("PitchOrServo2"), QString(""), UAVObjectField::FLOAT32, PitchOrServo2ElemNames, QStringList(), QString("")));
    QStringList YawElemNames;
    YawElemNames.append("0");
    fields.append( new UAVObjectField(QString("Yaw"), QString(""), UAVObjectField::FLOAT32, YawElemNames, QStringList(), QString("")));

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
UAVObject::Metadata CameraDesired::getDefaultMetadata()
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
void CameraDesired::setDefaultFieldValues()
{

}

/**
 * Get the object data fields
 */
CameraDesired::DataFields CameraDesired::getData()
{
    QMutexLocker locker(mutex);
    return data;
}

/**
 * Set the object data fields
 */
void CameraDesired::setData(const DataFields& data)
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

void CameraDesired::emitNotifications()
{
            //if (data.RollOrServo1 != oldData.RollOrServo1)
            emit RollOrServo1Changed(data.RollOrServo1);
        //if (data.PitchOrServo2 != oldData.PitchOrServo2)
            emit PitchOrServo2Changed(data.PitchOrServo2);
        //if (data.Yaw != oldData.Yaw)
            emit YawChanged(data.Yaw);

}

/**
 * Create a clone of this object, a new instance ID must be specified.
 * Do not use this function directly to create new instances, the
 * UAVObjectManager should be used instead.
 */
UAVDataObject *CameraDesired::clone(quint32 instID)
{
    CameraDesired *obj = new CameraDesired();
    obj->initialize(instID, this->getMetaObject());
    return obj;
}

/**
 * Create a clone of this object only to be used to retrieve defaults
 */
UAVDataObject *CameraDesired::dirtyClone()
{
    CameraDesired *obj = new CameraDesired();
    return obj;
}

/**
 * Static function to retrieve an instance of the object.
 */
CameraDesired *CameraDesired::GetInstance(UAVObjectManager *objMngr, quint32 instID)
{
    return dynamic_cast<CameraDesired *>(objMngr->getObject(CameraDesired::OBJID, instID));
}

float CameraDesired::getRollOrServo1() const
{
   QMutexLocker locker(mutex);
   return data.RollOrServo1;
}
void CameraDesired::setRollOrServo1(float value)
{
   mutex->lock();
   bool changed = data.RollOrServo1 != value;
   data.RollOrServo1 = value;
   mutex->unlock();
   if (changed) emit RollOrServo1Changed(value);
}

float CameraDesired::getPitchOrServo2() const
{
   QMutexLocker locker(mutex);
   return data.PitchOrServo2;
}
void CameraDesired::setPitchOrServo2(float value)
{
   mutex->lock();
   bool changed = data.PitchOrServo2 != value;
   data.PitchOrServo2 = value;
   mutex->unlock();
   if (changed) emit PitchOrServo2Changed(value);
}

float CameraDesired::getYaw() const
{
   QMutexLocker locker(mutex);
   return data.Yaw;
}
void CameraDesired::setYaw(float value)
{
   mutex->lock();
   bool changed = data.Yaw != value;
   data.Yaw = value;
   mutex->unlock();
   if (changed) emit YawChanged(value);
}


