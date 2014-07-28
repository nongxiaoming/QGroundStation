/**
 ******************************************************************************
 *
 * @file       gpssettings.cpp
 * @author     The OpenPilot Team, http://www.openpilot.org Copyright (C) 2010.
 * @see        The GNU Public License (GPL) Version 3
 * @addtogroup GCSPlugins GCS Plugins
 * @{
 * @addtogroup UAVObjectsPlugin UAVObjects Plugin
 * @{
 *
 * @note       Object definition file: gpssettings.xml.
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

#include "gpssettings.h"
#include "uavobjectfield.h"

const QString GPSSettings::NAME = QString("GPSSettings");
const QString GPSSettings::DESCRIPTION = QString("GPS Module specific settings");
const QString GPSSettings::CATEGORY = QString("Sensors");

/**
 * Constructor
 */
GPSSettings::GPSSettings(): UAVDataObject(OBJID, ISSINGLEINST, ISSETTINGS, NAME)
{
    // Create fields
    QList<UAVObjectField *> fields;
    QStringList MaxPDOPElemNames;
    MaxPDOPElemNames.append("0");
    fields.append( new UAVObjectField(QString("MaxPDOP"), QString(""), UAVObjectField::FLOAT32, MaxPDOPElemNames, QStringList(), QString("")));
    QStringList DataProtocolElemNames;
    DataProtocolElemNames.append("0");
    QStringList DataProtocolEnumOptions;
    DataProtocolEnumOptions.append("NMEA");
    DataProtocolEnumOptions.append("UBX");
    fields.append( new UAVObjectField(QString("DataProtocol"), QString(""), UAVObjectField::ENUM, DataProtocolElemNames, DataProtocolEnumOptions, QString("")));
    QStringList MinSattelitesElemNames;
    MinSattelitesElemNames.append("0");
    fields.append( new UAVObjectField(QString("MinSattelites"), QString(""), UAVObjectField::UINT8, MinSattelitesElemNames, QStringList(), QString("")));

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
UAVObject::Metadata GPSSettings::getDefaultMetadata()
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
void GPSSettings::setDefaultFieldValues()
{
    data.MaxPDOP = 3.5;
    data.DataProtocol = 1;
    data.MinSattelites = 7;

}

/**
 * Get the object data fields
 */
GPSSettings::DataFields GPSSettings::getData()
{
    QMutexLocker locker(mutex);
    return data;
}

/**
 * Set the object data fields
 */
void GPSSettings::setData(const DataFields& data)
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

void GPSSettings::emitNotifications()
{
            //if (data.MaxPDOP != oldData.MaxPDOP)
            emit MaxPDOPChanged(data.MaxPDOP);
        //if (data.DataProtocol != oldData.DataProtocol)
            emit DataProtocolChanged(data.DataProtocol);
        //if (data.MinSattelites != oldData.MinSattelites)
            emit MinSattelitesChanged(data.MinSattelites);

}

/**
 * Create a clone of this object, a new instance ID must be specified.
 * Do not use this function directly to create new instances, the
 * UAVObjectManager should be used instead.
 */
UAVDataObject *GPSSettings::clone(quint32 instID)
{
    GPSSettings *obj = new GPSSettings();
    obj->initialize(instID, this->getMetaObject());
    return obj;
}

/**
 * Create a clone of this object only to be used to retrieve defaults
 */
UAVDataObject *GPSSettings::dirtyClone()
{
    GPSSettings *obj = new GPSSettings();
    return obj;
}

/**
 * Static function to retrieve an instance of the object.
 */
GPSSettings *GPSSettings::GetInstance(UAVObjectManager *objMngr, quint32 instID)
{
    return dynamic_cast<GPSSettings *>(objMngr->getObject(GPSSettings::OBJID, instID));
}

float GPSSettings::getMaxPDOP() const
{
   QMutexLocker locker(mutex);
   return data.MaxPDOP;
}
void GPSSettings::setMaxPDOP(float value)
{
   mutex->lock();
   bool changed = data.MaxPDOP != value;
   data.MaxPDOP = value;
   mutex->unlock();
   if (changed) emit MaxPDOPChanged(value);
}

quint8 GPSSettings::getDataProtocol() const
{
   QMutexLocker locker(mutex);
   return data.DataProtocol;
}
void GPSSettings::setDataProtocol(quint8 value)
{
   mutex->lock();
   bool changed = data.DataProtocol != value;
   data.DataProtocol = value;
   mutex->unlock();
   if (changed) emit DataProtocolChanged(value);
}

quint8 GPSSettings::getMinSattelites() const
{
   QMutexLocker locker(mutex);
   return data.MinSattelites;
}
void GPSSettings::setMinSattelites(quint8 value)
{
   mutex->lock();
   bool changed = data.MinSattelites != value;
   data.MinSattelites = value;
   mutex->unlock();
   if (changed) emit MinSattelitesChanged(value);
}


