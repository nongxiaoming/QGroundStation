/**
 ******************************************************************************
 *
 * @file       overosyncstats.cpp
 * @author     The OpenPilot Team, http://www.openpilot.org Copyright (C) 2010.
 * @see        The GNU Public License (GPL) Version 3
 * @addtogroup GCSPlugins GCS Plugins
 * @{
 * @addtogroup UAVObjectsPlugin UAVObjects Plugin
 * @{
 *
 * @note       Object definition file: overosyncstats.xml.
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

#include "overosyncstats.h"
#include "uavobjectfield.h"

const QString OveroSyncStats::NAME = QString("OveroSyncStats");
const QString OveroSyncStats::DESCRIPTION = QString("Maintains statistics on transfer rate to and from over");
const QString OveroSyncStats::CATEGORY = QString("System");

/**
 * Constructor
 */
OveroSyncStats::OveroSyncStats(): UAVDataObject(OBJID, ISSINGLEINST, ISSETTINGS, NAME)
{
    // Create fields
    QList<UAVObjectField *> fields;
    QStringList SendElemNames;
    SendElemNames.append("0");
    fields.append( new UAVObjectField(QString("Send"), QString("B/s"), UAVObjectField::UINT32, SendElemNames, QStringList(), QString("")));
    QStringList ReceivedElemNames;
    ReceivedElemNames.append("0");
    fields.append( new UAVObjectField(QString("Received"), QString("B/s"), UAVObjectField::UINT32, ReceivedElemNames, QStringList(), QString("")));
    QStringList FramesyncErrorsElemNames;
    FramesyncErrorsElemNames.append("0");
    fields.append( new UAVObjectField(QString("FramesyncErrors"), QString("count"), UAVObjectField::UINT32, FramesyncErrorsElemNames, QStringList(), QString("")));
    QStringList UnderrunErrorsElemNames;
    UnderrunErrorsElemNames.append("0");
    fields.append( new UAVObjectField(QString("UnderrunErrors"), QString("count"), UAVObjectField::UINT32, UnderrunErrorsElemNames, QStringList(), QString("")));
    QStringList DroppedUpdatesElemNames;
    DroppedUpdatesElemNames.append("0");
    fields.append( new UAVObjectField(QString("DroppedUpdates"), QString(""), UAVObjectField::UINT32, DroppedUpdatesElemNames, QStringList(), QString("")));
    QStringList PacketsElemNames;
    PacketsElemNames.append("0");
    fields.append( new UAVObjectField(QString("Packets"), QString(""), UAVObjectField::UINT32, PacketsElemNames, QStringList(), QString("")));
    QStringList ConnectedElemNames;
    ConnectedElemNames.append("0");
    QStringList ConnectedEnumOptions;
    ConnectedEnumOptions.append("False");
    ConnectedEnumOptions.append("True");
    fields.append( new UAVObjectField(QString("Connected"), QString(""), UAVObjectField::ENUM, ConnectedElemNames, ConnectedEnumOptions, QString("")));

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
UAVObject::Metadata OveroSyncStats::getDefaultMetadata()
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
void OveroSyncStats::setDefaultFieldValues()
{

}

/**
 * Get the object data fields
 */
OveroSyncStats::DataFields OveroSyncStats::getData()
{
    QMutexLocker locker(mutex);
    return data;
}

/**
 * Set the object data fields
 */
void OveroSyncStats::setData(const DataFields& data)
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

void OveroSyncStats::emitNotifications()
{
            //if (data.Send != oldData.Send)
            emit SendChanged(data.Send);
        //if (data.Received != oldData.Received)
            emit ReceivedChanged(data.Received);
        //if (data.FramesyncErrors != oldData.FramesyncErrors)
            emit FramesyncErrorsChanged(data.FramesyncErrors);
        //if (data.UnderrunErrors != oldData.UnderrunErrors)
            emit UnderrunErrorsChanged(data.UnderrunErrors);
        //if (data.DroppedUpdates != oldData.DroppedUpdates)
            emit DroppedUpdatesChanged(data.DroppedUpdates);
        //if (data.Packets != oldData.Packets)
            emit PacketsChanged(data.Packets);
        //if (data.Connected != oldData.Connected)
            emit ConnectedChanged(data.Connected);

}

/**
 * Create a clone of this object, a new instance ID must be specified.
 * Do not use this function directly to create new instances, the
 * UAVObjectManager should be used instead.
 */
UAVDataObject *OveroSyncStats::clone(quint32 instID)
{
    OveroSyncStats *obj = new OveroSyncStats();
    obj->initialize(instID, this->getMetaObject());
    return obj;
}

/**
 * Create a clone of this object only to be used to retrieve defaults
 */
UAVDataObject *OveroSyncStats::dirtyClone()
{
    OveroSyncStats *obj = new OveroSyncStats();
    return obj;
}

/**
 * Static function to retrieve an instance of the object.
 */
OveroSyncStats *OveroSyncStats::GetInstance(UAVObjectManager *objMngr, quint32 instID)
{
    return dynamic_cast<OveroSyncStats *>(objMngr->getObject(OveroSyncStats::OBJID, instID));
}

quint32 OveroSyncStats::getSend() const
{
   QMutexLocker locker(mutex);
   return data.Send;
}
void OveroSyncStats::setSend(quint32 value)
{
   mutex->lock();
   bool changed = data.Send != value;
   data.Send = value;
   mutex->unlock();
   if (changed) emit SendChanged(value);
}

quint32 OveroSyncStats::getReceived() const
{
   QMutexLocker locker(mutex);
   return data.Received;
}
void OveroSyncStats::setReceived(quint32 value)
{
   mutex->lock();
   bool changed = data.Received != value;
   data.Received = value;
   mutex->unlock();
   if (changed) emit ReceivedChanged(value);
}

quint32 OveroSyncStats::getFramesyncErrors() const
{
   QMutexLocker locker(mutex);
   return data.FramesyncErrors;
}
void OveroSyncStats::setFramesyncErrors(quint32 value)
{
   mutex->lock();
   bool changed = data.FramesyncErrors != value;
   data.FramesyncErrors = value;
   mutex->unlock();
   if (changed) emit FramesyncErrorsChanged(value);
}

quint32 OveroSyncStats::getUnderrunErrors() const
{
   QMutexLocker locker(mutex);
   return data.UnderrunErrors;
}
void OveroSyncStats::setUnderrunErrors(quint32 value)
{
   mutex->lock();
   bool changed = data.UnderrunErrors != value;
   data.UnderrunErrors = value;
   mutex->unlock();
   if (changed) emit UnderrunErrorsChanged(value);
}

quint32 OveroSyncStats::getDroppedUpdates() const
{
   QMutexLocker locker(mutex);
   return data.DroppedUpdates;
}
void OveroSyncStats::setDroppedUpdates(quint32 value)
{
   mutex->lock();
   bool changed = data.DroppedUpdates != value;
   data.DroppedUpdates = value;
   mutex->unlock();
   if (changed) emit DroppedUpdatesChanged(value);
}

quint32 OveroSyncStats::getPackets() const
{
   QMutexLocker locker(mutex);
   return data.Packets;
}
void OveroSyncStats::setPackets(quint32 value)
{
   mutex->lock();
   bool changed = data.Packets != value;
   data.Packets = value;
   mutex->unlock();
   if (changed) emit PacketsChanged(value);
}

quint8 OveroSyncStats::getConnected() const
{
   QMutexLocker locker(mutex);
   return data.Connected;
}
void OveroSyncStats::setConnected(quint8 value)
{
   mutex->lock();
   bool changed = data.Connected != value;
   data.Connected = value;
   mutex->unlock();
   if (changed) emit ConnectedChanged(value);
}


