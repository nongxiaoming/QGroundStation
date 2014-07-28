/**
 ******************************************************************************
 *
 * @file       overosyncsettings.cpp
 * @author     The OpenPilot Team, http://www.openpilot.org Copyright (C) 2010.
 * @see        The GNU Public License (GPL) Version 3
 * @addtogroup GCSPlugins GCS Plugins
 * @{
 * @addtogroup UAVObjectsPlugin UAVObjects Plugin
 * @{
 *
 * @note       Object definition file: overosyncsettings.xml.
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

#include "overosyncsettings.h"
#include "uavobjectfield.h"

const QString OveroSyncSettings::NAME = QString("OveroSyncSettings");
const QString OveroSyncSettings::DESCRIPTION = QString("Settings to control the behavior of the overo sync module");
const QString OveroSyncSettings::CATEGORY = QString("System");

/**
 * Constructor
 */
OveroSyncSettings::OveroSyncSettings(): UAVDataObject(OBJID, ISSINGLEINST, ISSETTINGS, NAME)
{
    // Create fields
    QList<UAVObjectField *> fields;
    QStringList LogOnElemNames;
    LogOnElemNames.append("0");
    QStringList LogOnEnumOptions;
    LogOnEnumOptions.append("Never");
    LogOnEnumOptions.append("Always");
    LogOnEnumOptions.append("Armed");
    fields.append( new UAVObjectField(QString("LogOn"), QString(""), UAVObjectField::ENUM, LogOnElemNames, LogOnEnumOptions, QString("")));

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
UAVObject::Metadata OveroSyncSettings::getDefaultMetadata()
{
    UAVObject::Metadata metadata;
    metadata.flags =
        ACCESS_READWRITE << UAVOBJ_ACCESS_SHIFT |
        ACCESS_READWRITE << UAVOBJ_GCS_ACCESS_SHIFT |
        0 << UAVOBJ_TELEMETRY_ACKED_SHIFT |
        0 << UAVOBJ_GCS_TELEMETRY_ACKED_SHIFT |
        UPDATEMODE_ONCHANGE << UAVOBJ_TELEMETRY_UPDATE_MODE_SHIFT |
        UPDATEMODE_MANUAL << UAVOBJ_GCS_TELEMETRY_UPDATE_MODE_SHIFT |
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
void OveroSyncSettings::setDefaultFieldValues()
{
    data.LogOn = 2;

}

/**
 * Get the object data fields
 */
OveroSyncSettings::DataFields OveroSyncSettings::getData()
{
    QMutexLocker locker(mutex);
    return data;
}

/**
 * Set the object data fields
 */
void OveroSyncSettings::setData(const DataFields& data)
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

void OveroSyncSettings::emitNotifications()
{
            //if (data.LogOn != oldData.LogOn)
            emit LogOnChanged(data.LogOn);

}

/**
 * Create a clone of this object, a new instance ID must be specified.
 * Do not use this function directly to create new instances, the
 * UAVObjectManager should be used instead.
 */
UAVDataObject *OveroSyncSettings::clone(quint32 instID)
{
    OveroSyncSettings *obj = new OveroSyncSettings();
    obj->initialize(instID, this->getMetaObject());
    return obj;
}

/**
 * Create a clone of this object only to be used to retrieve defaults
 */
UAVDataObject *OveroSyncSettings::dirtyClone()
{
    OveroSyncSettings *obj = new OveroSyncSettings();
    return obj;
}

/**
 * Static function to retrieve an instance of the object.
 */
OveroSyncSettings *OveroSyncSettings::GetInstance(UAVObjectManager *objMngr, quint32 instID)
{
    return dynamic_cast<OveroSyncSettings *>(objMngr->getObject(OveroSyncSettings::OBJID, instID));
}

quint8 OveroSyncSettings::getLogOn() const
{
   QMutexLocker locker(mutex);
   return data.LogOn;
}
void OveroSyncSettings::setLogOn(quint8 value)
{
   mutex->lock();
   bool changed = data.LogOn != value;
   data.LogOn = value;
   mutex->unlock();
   if (changed) emit LogOnChanged(value);
}


