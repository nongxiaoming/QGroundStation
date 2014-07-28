/**
 ******************************************************************************
 *
 * @file       flighttelemetrystats.cpp
 * @author     The OpenPilot Team, http://www.openpilot.org Copyright (C) 2010.
 * @see        The GNU Public License (GPL) Version 3
 * @addtogroup GCSPlugins GCS Plugins
 * @{
 * @addtogroup UAVObjectsPlugin UAVObjects Plugin
 * @{
 *
 * @note       Object definition file: flighttelemetrystats.xml.
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

#include "flighttelemetrystats.h"
#include "uavobjectfield.h"

const QString FlightTelemetryStats::NAME = QString("FlightTelemetryStats");
const QString FlightTelemetryStats::DESCRIPTION = QString("Maintains the telemetry statistics from the OpenPilot flight computer.");
const QString FlightTelemetryStats::CATEGORY = QString("System");

/**
 * Constructor
 */
FlightTelemetryStats::FlightTelemetryStats(): UAVDataObject(OBJID, ISSINGLEINST, ISSETTINGS, NAME)
{
    // Create fields
    QList<UAVObjectField *> fields;
    QStringList TxDataRateElemNames;
    TxDataRateElemNames.append("0");
    fields.append( new UAVObjectField(QString("TxDataRate"), QString("bytes/sec"), UAVObjectField::FLOAT32, TxDataRateElemNames, QStringList(), QString("")));
    QStringList TxBytesElemNames;
    TxBytesElemNames.append("0");
    fields.append( new UAVObjectField(QString("TxBytes"), QString("bytes"), UAVObjectField::UINT32, TxBytesElemNames, QStringList(), QString("")));
    QStringList TxFailuresElemNames;
    TxFailuresElemNames.append("0");
    fields.append( new UAVObjectField(QString("TxFailures"), QString("count"), UAVObjectField::UINT32, TxFailuresElemNames, QStringList(), QString("")));
    QStringList TxRetriesElemNames;
    TxRetriesElemNames.append("0");
    fields.append( new UAVObjectField(QString("TxRetries"), QString("count"), UAVObjectField::UINT32, TxRetriesElemNames, QStringList(), QString("")));
    QStringList RxDataRateElemNames;
    RxDataRateElemNames.append("0");
    fields.append( new UAVObjectField(QString("RxDataRate"), QString("bytes/sec"), UAVObjectField::FLOAT32, RxDataRateElemNames, QStringList(), QString("")));
    QStringList RxBytesElemNames;
    RxBytesElemNames.append("0");
    fields.append( new UAVObjectField(QString("RxBytes"), QString("bytes"), UAVObjectField::UINT32, RxBytesElemNames, QStringList(), QString("")));
    QStringList RxFailuresElemNames;
    RxFailuresElemNames.append("0");
    fields.append( new UAVObjectField(QString("RxFailures"), QString("count"), UAVObjectField::UINT32, RxFailuresElemNames, QStringList(), QString("")));
    QStringList RxSyncErrorsElemNames;
    RxSyncErrorsElemNames.append("0");
    fields.append( new UAVObjectField(QString("RxSyncErrors"), QString("count"), UAVObjectField::UINT32, RxSyncErrorsElemNames, QStringList(), QString("")));
    QStringList RxCrcErrorsElemNames;
    RxCrcErrorsElemNames.append("0");
    fields.append( new UAVObjectField(QString("RxCrcErrors"), QString("count"), UAVObjectField::UINT32, RxCrcErrorsElemNames, QStringList(), QString("")));
    QStringList StatusElemNames;
    StatusElemNames.append("0");
    QStringList StatusEnumOptions;
    StatusEnumOptions.append("Disconnected");
    StatusEnumOptions.append("HandshakeReq");
    StatusEnumOptions.append("HandshakeAck");
    StatusEnumOptions.append("Connected");
    fields.append( new UAVObjectField(QString("Status"), QString(""), UAVObjectField::ENUM, StatusElemNames, StatusEnumOptions, QString("")));

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
UAVObject::Metadata FlightTelemetryStats::getDefaultMetadata()
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
    metadata.flightTelemetryUpdatePeriod = 5000;
    metadata.gcsTelemetryUpdatePeriod = 0;
    metadata.loggingUpdatePeriod = 0;
    return metadata;
}

/**
 * Initialize object fields with the default values.
 * If a default value is not specified the object fields
 * will be initialized to zero.
 */
void FlightTelemetryStats::setDefaultFieldValues()
{

}

/**
 * Get the object data fields
 */
FlightTelemetryStats::DataFields FlightTelemetryStats::getData()
{
    QMutexLocker locker(mutex);
    return data;
}

/**
 * Set the object data fields
 */
void FlightTelemetryStats::setData(const DataFields& data)
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

void FlightTelemetryStats::emitNotifications()
{
            //if (data.TxDataRate != oldData.TxDataRate)
            emit TxDataRateChanged(data.TxDataRate);
        //if (data.TxBytes != oldData.TxBytes)
            emit TxBytesChanged(data.TxBytes);
        //if (data.TxFailures != oldData.TxFailures)
            emit TxFailuresChanged(data.TxFailures);
        //if (data.TxRetries != oldData.TxRetries)
            emit TxRetriesChanged(data.TxRetries);
        //if (data.RxDataRate != oldData.RxDataRate)
            emit RxDataRateChanged(data.RxDataRate);
        //if (data.RxBytes != oldData.RxBytes)
            emit RxBytesChanged(data.RxBytes);
        //if (data.RxFailures != oldData.RxFailures)
            emit RxFailuresChanged(data.RxFailures);
        //if (data.RxSyncErrors != oldData.RxSyncErrors)
            emit RxSyncErrorsChanged(data.RxSyncErrors);
        //if (data.RxCrcErrors != oldData.RxCrcErrors)
            emit RxCrcErrorsChanged(data.RxCrcErrors);
        //if (data.Status != oldData.Status)
            emit StatusChanged(data.Status);

}

/**
 * Create a clone of this object, a new instance ID must be specified.
 * Do not use this function directly to create new instances, the
 * UAVObjectManager should be used instead.
 */
UAVDataObject *FlightTelemetryStats::clone(quint32 instID)
{
    FlightTelemetryStats *obj = new FlightTelemetryStats();
    obj->initialize(instID, this->getMetaObject());
    return obj;
}

/**
 * Create a clone of this object only to be used to retrieve defaults
 */
UAVDataObject *FlightTelemetryStats::dirtyClone()
{
    FlightTelemetryStats *obj = new FlightTelemetryStats();
    return obj;
}

/**
 * Static function to retrieve an instance of the object.
 */
FlightTelemetryStats *FlightTelemetryStats::GetInstance(UAVObjectManager *objMngr, quint32 instID)
{
    return dynamic_cast<FlightTelemetryStats *>(objMngr->getObject(FlightTelemetryStats::OBJID, instID));
}

float FlightTelemetryStats::getTxDataRate() const
{
   QMutexLocker locker(mutex);
   return data.TxDataRate;
}
void FlightTelemetryStats::setTxDataRate(float value)
{
   mutex->lock();
   bool changed = data.TxDataRate != value;
   data.TxDataRate = value;
   mutex->unlock();
   if (changed) emit TxDataRateChanged(value);
}

quint32 FlightTelemetryStats::getTxBytes() const
{
   QMutexLocker locker(mutex);
   return data.TxBytes;
}
void FlightTelemetryStats::setTxBytes(quint32 value)
{
   mutex->lock();
   bool changed = data.TxBytes != value;
   data.TxBytes = value;
   mutex->unlock();
   if (changed) emit TxBytesChanged(value);
}

quint32 FlightTelemetryStats::getTxFailures() const
{
   QMutexLocker locker(mutex);
   return data.TxFailures;
}
void FlightTelemetryStats::setTxFailures(quint32 value)
{
   mutex->lock();
   bool changed = data.TxFailures != value;
   data.TxFailures = value;
   mutex->unlock();
   if (changed) emit TxFailuresChanged(value);
}

quint32 FlightTelemetryStats::getTxRetries() const
{
   QMutexLocker locker(mutex);
   return data.TxRetries;
}
void FlightTelemetryStats::setTxRetries(quint32 value)
{
   mutex->lock();
   bool changed = data.TxRetries != value;
   data.TxRetries = value;
   mutex->unlock();
   if (changed) emit TxRetriesChanged(value);
}

float FlightTelemetryStats::getRxDataRate() const
{
   QMutexLocker locker(mutex);
   return data.RxDataRate;
}
void FlightTelemetryStats::setRxDataRate(float value)
{
   mutex->lock();
   bool changed = data.RxDataRate != value;
   data.RxDataRate = value;
   mutex->unlock();
   if (changed) emit RxDataRateChanged(value);
}

quint32 FlightTelemetryStats::getRxBytes() const
{
   QMutexLocker locker(mutex);
   return data.RxBytes;
}
void FlightTelemetryStats::setRxBytes(quint32 value)
{
   mutex->lock();
   bool changed = data.RxBytes != value;
   data.RxBytes = value;
   mutex->unlock();
   if (changed) emit RxBytesChanged(value);
}

quint32 FlightTelemetryStats::getRxFailures() const
{
   QMutexLocker locker(mutex);
   return data.RxFailures;
}
void FlightTelemetryStats::setRxFailures(quint32 value)
{
   mutex->lock();
   bool changed = data.RxFailures != value;
   data.RxFailures = value;
   mutex->unlock();
   if (changed) emit RxFailuresChanged(value);
}

quint32 FlightTelemetryStats::getRxSyncErrors() const
{
   QMutexLocker locker(mutex);
   return data.RxSyncErrors;
}
void FlightTelemetryStats::setRxSyncErrors(quint32 value)
{
   mutex->lock();
   bool changed = data.RxSyncErrors != value;
   data.RxSyncErrors = value;
   mutex->unlock();
   if (changed) emit RxSyncErrorsChanged(value);
}

quint32 FlightTelemetryStats::getRxCrcErrors() const
{
   QMutexLocker locker(mutex);
   return data.RxCrcErrors;
}
void FlightTelemetryStats::setRxCrcErrors(quint32 value)
{
   mutex->lock();
   bool changed = data.RxCrcErrors != value;
   data.RxCrcErrors = value;
   mutex->unlock();
   if (changed) emit RxCrcErrorsChanged(value);
}

quint8 FlightTelemetryStats::getStatus() const
{
   QMutexLocker locker(mutex);
   return data.Status;
}
void FlightTelemetryStats::setStatus(quint8 value)
{
   mutex->lock();
   bool changed = data.Status != value;
   data.Status = value;
   mutex->unlock();
   if (changed) emit StatusChanged(value);
}


