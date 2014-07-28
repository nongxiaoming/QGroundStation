/**
 ******************************************************************************
 *
 * @file       oplinkreceiver.cpp
 * @author     The OpenPilot Team, http://www.openpilot.org Copyright (C) 2010.
 * @see        The GNU Public License (GPL) Version 3
 * @addtogroup GCSPlugins GCS Plugins
 * @{
 * @addtogroup UAVObjectsPlugin UAVObjects Plugin
 * @{
 *
 * @note       Object definition file: oplinkreceiver.xml.
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

#include "oplinkreceiver.h"
#include "uavobjectfield.h"

const QString OPLinkReceiver::NAME = QString("OPLinkReceiver");
const QString OPLinkReceiver::DESCRIPTION = QString("A receiver channel group carried over the OPLink radio.");
const QString OPLinkReceiver::CATEGORY = QString("System");

/**
 * Constructor
 */
OPLinkReceiver::OPLinkReceiver(): UAVDataObject(OBJID, ISSINGLEINST, ISSETTINGS, NAME)
{
    // Create fields
    QList<UAVObjectField *> fields;
    QStringList ChannelElemNames;
    ChannelElemNames.append("0");
    ChannelElemNames.append("1");
    ChannelElemNames.append("2");
    ChannelElemNames.append("3");
    ChannelElemNames.append("4");
    ChannelElemNames.append("5");
    ChannelElemNames.append("6");
    ChannelElemNames.append("7");
    fields.append( new UAVObjectField(QString("Channel"), QString("us"), UAVObjectField::INT16, ChannelElemNames, QStringList(), QString("")));

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
UAVObject::Metadata OPLinkReceiver::getDefaultMetadata()
{
    UAVObject::Metadata metadata;
    metadata.flags =
        ACCESS_READWRITE << UAVOBJ_ACCESS_SHIFT |
        ACCESS_READONLY << UAVOBJ_GCS_ACCESS_SHIFT |
        0 << UAVOBJ_TELEMETRY_ACKED_SHIFT |
        0 << UAVOBJ_GCS_TELEMETRY_ACKED_SHIFT |
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
void OPLinkReceiver::setDefaultFieldValues()
{

}

/**
 * Get the object data fields
 */
OPLinkReceiver::DataFields OPLinkReceiver::getData()
{
    QMutexLocker locker(mutex);
    return data;
}

/**
 * Set the object data fields
 */
void OPLinkReceiver::setData(const DataFields& data)
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

void OPLinkReceiver::emitNotifications()
{
            //if (data.Channel[0] != oldData.Channel[0])
            emit Channel_0Changed(data.Channel[0]);
        //if (data.Channel[1] != oldData.Channel[1])
            emit Channel_1Changed(data.Channel[1]);
        //if (data.Channel[2] != oldData.Channel[2])
            emit Channel_2Changed(data.Channel[2]);
        //if (data.Channel[3] != oldData.Channel[3])
            emit Channel_3Changed(data.Channel[3]);
        //if (data.Channel[4] != oldData.Channel[4])
            emit Channel_4Changed(data.Channel[4]);
        //if (data.Channel[5] != oldData.Channel[5])
            emit Channel_5Changed(data.Channel[5]);
        //if (data.Channel[6] != oldData.Channel[6])
            emit Channel_6Changed(data.Channel[6]);
        //if (data.Channel[7] != oldData.Channel[7])
            emit Channel_7Changed(data.Channel[7]);

}

/**
 * Create a clone of this object, a new instance ID must be specified.
 * Do not use this function directly to create new instances, the
 * UAVObjectManager should be used instead.
 */
UAVDataObject *OPLinkReceiver::clone(quint32 instID)
{
    OPLinkReceiver *obj = new OPLinkReceiver();
    obj->initialize(instID, this->getMetaObject());
    return obj;
}

/**
 * Create a clone of this object only to be used to retrieve defaults
 */
UAVDataObject *OPLinkReceiver::dirtyClone()
{
    OPLinkReceiver *obj = new OPLinkReceiver();
    return obj;
}

/**
 * Static function to retrieve an instance of the object.
 */
OPLinkReceiver *OPLinkReceiver::GetInstance(UAVObjectManager *objMngr, quint32 instID)
{
    return dynamic_cast<OPLinkReceiver *>(objMngr->getObject(OPLinkReceiver::OBJID, instID));
}

qint16 OPLinkReceiver::getChannel(quint32 index) const
{
   QMutexLocker locker(mutex);
   return data.Channel[index];
}
void OPLinkReceiver::setChannel(quint32 index, qint16 value)
{
   mutex->lock();
   bool changed = data.Channel[index] != value;
   data.Channel[index] = value;
   mutex->unlock();
   if (changed) emit ChannelChanged(index,value);
}

qint16 OPLinkReceiver::getChannel_0() const
{
   QMutexLocker locker(mutex);
   return data.Channel[0];
}
void OPLinkReceiver::setChannel_0(qint16 value)
{
   mutex->lock();
   bool changed = data.Channel[0] != value;
   data.Channel[0] = value;
   mutex->unlock();
   if (changed) emit Channel_0Changed(value);
}

qint16 OPLinkReceiver::getChannel_1() const
{
   QMutexLocker locker(mutex);
   return data.Channel[1];
}
void OPLinkReceiver::setChannel_1(qint16 value)
{
   mutex->lock();
   bool changed = data.Channel[1] != value;
   data.Channel[1] = value;
   mutex->unlock();
   if (changed) emit Channel_1Changed(value);
}

qint16 OPLinkReceiver::getChannel_2() const
{
   QMutexLocker locker(mutex);
   return data.Channel[2];
}
void OPLinkReceiver::setChannel_2(qint16 value)
{
   mutex->lock();
   bool changed = data.Channel[2] != value;
   data.Channel[2] = value;
   mutex->unlock();
   if (changed) emit Channel_2Changed(value);
}

qint16 OPLinkReceiver::getChannel_3() const
{
   QMutexLocker locker(mutex);
   return data.Channel[3];
}
void OPLinkReceiver::setChannel_3(qint16 value)
{
   mutex->lock();
   bool changed = data.Channel[3] != value;
   data.Channel[3] = value;
   mutex->unlock();
   if (changed) emit Channel_3Changed(value);
}

qint16 OPLinkReceiver::getChannel_4() const
{
   QMutexLocker locker(mutex);
   return data.Channel[4];
}
void OPLinkReceiver::setChannel_4(qint16 value)
{
   mutex->lock();
   bool changed = data.Channel[4] != value;
   data.Channel[4] = value;
   mutex->unlock();
   if (changed) emit Channel_4Changed(value);
}

qint16 OPLinkReceiver::getChannel_5() const
{
   QMutexLocker locker(mutex);
   return data.Channel[5];
}
void OPLinkReceiver::setChannel_5(qint16 value)
{
   mutex->lock();
   bool changed = data.Channel[5] != value;
   data.Channel[5] = value;
   mutex->unlock();
   if (changed) emit Channel_5Changed(value);
}

qint16 OPLinkReceiver::getChannel_6() const
{
   QMutexLocker locker(mutex);
   return data.Channel[6];
}
void OPLinkReceiver::setChannel_6(qint16 value)
{
   mutex->lock();
   bool changed = data.Channel[6] != value;
   data.Channel[6] = value;
   mutex->unlock();
   if (changed) emit Channel_6Changed(value);
}

qint16 OPLinkReceiver::getChannel_7() const
{
   QMutexLocker locker(mutex);
   return data.Channel[7];
}
void OPLinkReceiver::setChannel_7(qint16 value)
{
   mutex->lock();
   bool changed = data.Channel[7] != value;
   data.Channel[7] = value;
   mutex->unlock();
   if (changed) emit Channel_7Changed(value);
}


