/**
 ******************************************************************************
 *
 * @file       actuatorsettings.cpp
 * @author     The OpenPilot Team, http://www.openpilot.org Copyright (C) 2010.
 * @see        The GNU Public License (GPL) Version 3
 * @addtogroup GCSPlugins GCS Plugins
 * @{
 * @addtogroup UAVObjectsPlugin UAVObjects Plugin
 * @{
 *
 * @note       Object definition file: actuatorsettings.xml.
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

#include "actuatorsettings.h"
#include "uavobjectfield.h"

const QString ActuatorSettings::NAME = QString("ActuatorSettings");
const QString ActuatorSettings::DESCRIPTION = QString("Settings for the @ref ActuatorModule that controls the channel assignments for the mixer based on AircraftType");
const QString ActuatorSettings::CATEGORY = QString("Control");

/**
 * Constructor
 */
ActuatorSettings::ActuatorSettings(): UAVDataObject(OBJID, ISSINGLEINST, ISSETTINGS, NAME)
{
    // Create fields
    QList<UAVObjectField *> fields;
    QStringList ChannelUpdateFreqElemNames;
    ChannelUpdateFreqElemNames.append("0");
    ChannelUpdateFreqElemNames.append("1");
    ChannelUpdateFreqElemNames.append("2");
    ChannelUpdateFreqElemNames.append("3");
    ChannelUpdateFreqElemNames.append("4");
    ChannelUpdateFreqElemNames.append("5");
    fields.append( new UAVObjectField(QString("ChannelUpdateFreq"), QString("Hz"), UAVObjectField::UINT16, ChannelUpdateFreqElemNames, QStringList(), QString("")));
    QStringList ChannelMaxElemNames;
    ChannelMaxElemNames.append("0");
    ChannelMaxElemNames.append("1");
    ChannelMaxElemNames.append("2");
    ChannelMaxElemNames.append("3");
    ChannelMaxElemNames.append("4");
    ChannelMaxElemNames.append("5");
    ChannelMaxElemNames.append("6");
    ChannelMaxElemNames.append("7");
    ChannelMaxElemNames.append("8");
    ChannelMaxElemNames.append("9");
    ChannelMaxElemNames.append("10");
    ChannelMaxElemNames.append("11");
    fields.append( new UAVObjectField(QString("ChannelMax"), QString("us"), UAVObjectField::INT16, ChannelMaxElemNames, QStringList(), QString("")));
    QStringList ChannelNeutralElemNames;
    ChannelNeutralElemNames.append("0");
    ChannelNeutralElemNames.append("1");
    ChannelNeutralElemNames.append("2");
    ChannelNeutralElemNames.append("3");
    ChannelNeutralElemNames.append("4");
    ChannelNeutralElemNames.append("5");
    ChannelNeutralElemNames.append("6");
    ChannelNeutralElemNames.append("7");
    ChannelNeutralElemNames.append("8");
    ChannelNeutralElemNames.append("9");
    ChannelNeutralElemNames.append("10");
    ChannelNeutralElemNames.append("11");
    fields.append( new UAVObjectField(QString("ChannelNeutral"), QString("us"), UAVObjectField::INT16, ChannelNeutralElemNames, QStringList(), QString("")));
    QStringList ChannelMinElemNames;
    ChannelMinElemNames.append("0");
    ChannelMinElemNames.append("1");
    ChannelMinElemNames.append("2");
    ChannelMinElemNames.append("3");
    ChannelMinElemNames.append("4");
    ChannelMinElemNames.append("5");
    ChannelMinElemNames.append("6");
    ChannelMinElemNames.append("7");
    ChannelMinElemNames.append("8");
    ChannelMinElemNames.append("9");
    ChannelMinElemNames.append("10");
    ChannelMinElemNames.append("11");
    fields.append( new UAVObjectField(QString("ChannelMin"), QString("us"), UAVObjectField::INT16, ChannelMinElemNames, QStringList(), QString("")));
    QStringList ChannelTypeElemNames;
    ChannelTypeElemNames.append("0");
    ChannelTypeElemNames.append("1");
    ChannelTypeElemNames.append("2");
    ChannelTypeElemNames.append("3");
    ChannelTypeElemNames.append("4");
    ChannelTypeElemNames.append("5");
    ChannelTypeElemNames.append("6");
    ChannelTypeElemNames.append("7");
    ChannelTypeElemNames.append("8");
    ChannelTypeElemNames.append("9");
    ChannelTypeElemNames.append("10");
    ChannelTypeElemNames.append("11");
    QStringList ChannelTypeEnumOptions;
    ChannelTypeEnumOptions.append("PWM");
    ChannelTypeEnumOptions.append("MK");
    ChannelTypeEnumOptions.append("ASTEC4");
    ChannelTypeEnumOptions.append("PWM Alarm Buzzer");
    ChannelTypeEnumOptions.append("Arming led");
    ChannelTypeEnumOptions.append("Info led");
    fields.append( new UAVObjectField(QString("ChannelType"), QString(""), UAVObjectField::ENUM, ChannelTypeElemNames, ChannelTypeEnumOptions, QString("")));
    QStringList ChannelAddrElemNames;
    ChannelAddrElemNames.append("0");
    ChannelAddrElemNames.append("1");
    ChannelAddrElemNames.append("2");
    ChannelAddrElemNames.append("3");
    ChannelAddrElemNames.append("4");
    ChannelAddrElemNames.append("5");
    ChannelAddrElemNames.append("6");
    ChannelAddrElemNames.append("7");
    ChannelAddrElemNames.append("8");
    ChannelAddrElemNames.append("9");
    ChannelAddrElemNames.append("10");
    ChannelAddrElemNames.append("11");
    fields.append( new UAVObjectField(QString("ChannelAddr"), QString(""), UAVObjectField::UINT8, ChannelAddrElemNames, QStringList(), QString("")));
    QStringList MotorsSpinWhileArmedElemNames;
    MotorsSpinWhileArmedElemNames.append("0");
    QStringList MotorsSpinWhileArmedEnumOptions;
    MotorsSpinWhileArmedEnumOptions.append("FALSE");
    MotorsSpinWhileArmedEnumOptions.append("TRUE");
    fields.append( new UAVObjectField(QString("MotorsSpinWhileArmed"), QString(""), UAVObjectField::ENUM, MotorsSpinWhileArmedElemNames, MotorsSpinWhileArmedEnumOptions, QString("")));
    QStringList LowThrottleZeroAxisElemNames;
    LowThrottleZeroAxisElemNames.append("Roll");
    LowThrottleZeroAxisElemNames.append("Pitch");
    LowThrottleZeroAxisElemNames.append("Yaw");
    QStringList LowThrottleZeroAxisEnumOptions;
    LowThrottleZeroAxisEnumOptions.append("FALSE");
    LowThrottleZeroAxisEnumOptions.append("TRUE");
    fields.append( new UAVObjectField(QString("LowThrottleZeroAxis"), QString(""), UAVObjectField::ENUM, LowThrottleZeroAxisElemNames, LowThrottleZeroAxisEnumOptions, QString("")));

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
UAVObject::Metadata ActuatorSettings::getDefaultMetadata()
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
void ActuatorSettings::setDefaultFieldValues()
{
    data.ChannelUpdateFreq[0] = 50;
    data.ChannelUpdateFreq[1] = 50;
    data.ChannelUpdateFreq[2] = 50;
    data.ChannelUpdateFreq[3] = 50;
    data.ChannelUpdateFreq[4] = 50;
    data.ChannelUpdateFreq[5] = 50;
    data.ChannelMax[0] = 1000;
    data.ChannelMax[1] = 1000;
    data.ChannelMax[2] = 1000;
    data.ChannelMax[3] = 1000;
    data.ChannelMax[4] = 1000;
    data.ChannelMax[5] = 1000;
    data.ChannelMax[6] = 1000;
    data.ChannelMax[7] = 1000;
    data.ChannelMax[8] = 1000;
    data.ChannelMax[9] = 1000;
    data.ChannelMax[10] = 1000;
    data.ChannelMax[11] = 1000;
    data.ChannelNeutral[0] = 1000;
    data.ChannelNeutral[1] = 1000;
    data.ChannelNeutral[2] = 1000;
    data.ChannelNeutral[3] = 1000;
    data.ChannelNeutral[4] = 1000;
    data.ChannelNeutral[5] = 1000;
    data.ChannelNeutral[6] = 1000;
    data.ChannelNeutral[7] = 1000;
    data.ChannelNeutral[8] = 1000;
    data.ChannelNeutral[9] = 1000;
    data.ChannelNeutral[10] = 1000;
    data.ChannelNeutral[11] = 1000;
    data.ChannelMin[0] = 1000;
    data.ChannelMin[1] = 1000;
    data.ChannelMin[2] = 1000;
    data.ChannelMin[3] = 1000;
    data.ChannelMin[4] = 1000;
    data.ChannelMin[5] = 1000;
    data.ChannelMin[6] = 1000;
    data.ChannelMin[7] = 1000;
    data.ChannelMin[8] = 1000;
    data.ChannelMin[9] = 1000;
    data.ChannelMin[10] = 1000;
    data.ChannelMin[11] = 1000;
    data.ChannelType[0] = 0;
    data.ChannelType[1] = 0;
    data.ChannelType[2] = 0;
    data.ChannelType[3] = 0;
    data.ChannelType[4] = 0;
    data.ChannelType[5] = 0;
    data.ChannelType[6] = 0;
    data.ChannelType[7] = 0;
    data.ChannelType[8] = 0;
    data.ChannelType[9] = 0;
    data.ChannelType[10] = 0;
    data.ChannelType[11] = 0;
    data.ChannelAddr[0] = 0;
    data.ChannelAddr[1] = 1;
    data.ChannelAddr[2] = 2;
    data.ChannelAddr[3] = 3;
    data.ChannelAddr[4] = 4;
    data.ChannelAddr[5] = 5;
    data.ChannelAddr[6] = 6;
    data.ChannelAddr[7] = 7;
    data.ChannelAddr[8] = 8;
    data.ChannelAddr[9] = 9;
    data.ChannelAddr[10] = 10;
    data.ChannelAddr[11] = 11;
    data.MotorsSpinWhileArmed = 0;
    data.LowThrottleZeroAxis[0] = 0;
    data.LowThrottleZeroAxis[1] = 0;
    data.LowThrottleZeroAxis[2] = 0;

}

/**
 * Get the object data fields
 */
ActuatorSettings::DataFields ActuatorSettings::getData()
{
    QMutexLocker locker(mutex);
    return data;
}

/**
 * Set the object data fields
 */
void ActuatorSettings::setData(const DataFields& data)
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

void ActuatorSettings::emitNotifications()
{
            //if (data.ChannelUpdateFreq[0] != oldData.ChannelUpdateFreq[0])
            emit ChannelUpdateFreq_0Changed(data.ChannelUpdateFreq[0]);
        //if (data.ChannelUpdateFreq[1] != oldData.ChannelUpdateFreq[1])
            emit ChannelUpdateFreq_1Changed(data.ChannelUpdateFreq[1]);
        //if (data.ChannelUpdateFreq[2] != oldData.ChannelUpdateFreq[2])
            emit ChannelUpdateFreq_2Changed(data.ChannelUpdateFreq[2]);
        //if (data.ChannelUpdateFreq[3] != oldData.ChannelUpdateFreq[3])
            emit ChannelUpdateFreq_3Changed(data.ChannelUpdateFreq[3]);
        //if (data.ChannelUpdateFreq[4] != oldData.ChannelUpdateFreq[4])
            emit ChannelUpdateFreq_4Changed(data.ChannelUpdateFreq[4]);
        //if (data.ChannelUpdateFreq[5] != oldData.ChannelUpdateFreq[5])
            emit ChannelUpdateFreq_5Changed(data.ChannelUpdateFreq[5]);
        //if (data.ChannelMax[0] != oldData.ChannelMax[0])
            emit ChannelMax_0Changed(data.ChannelMax[0]);
        //if (data.ChannelMax[1] != oldData.ChannelMax[1])
            emit ChannelMax_1Changed(data.ChannelMax[1]);
        //if (data.ChannelMax[2] != oldData.ChannelMax[2])
            emit ChannelMax_2Changed(data.ChannelMax[2]);
        //if (data.ChannelMax[3] != oldData.ChannelMax[3])
            emit ChannelMax_3Changed(data.ChannelMax[3]);
        //if (data.ChannelMax[4] != oldData.ChannelMax[4])
            emit ChannelMax_4Changed(data.ChannelMax[4]);
        //if (data.ChannelMax[5] != oldData.ChannelMax[5])
            emit ChannelMax_5Changed(data.ChannelMax[5]);
        //if (data.ChannelMax[6] != oldData.ChannelMax[6])
            emit ChannelMax_6Changed(data.ChannelMax[6]);
        //if (data.ChannelMax[7] != oldData.ChannelMax[7])
            emit ChannelMax_7Changed(data.ChannelMax[7]);
        //if (data.ChannelMax[8] != oldData.ChannelMax[8])
            emit ChannelMax_8Changed(data.ChannelMax[8]);
        //if (data.ChannelMax[9] != oldData.ChannelMax[9])
            emit ChannelMax_9Changed(data.ChannelMax[9]);
        //if (data.ChannelMax[10] != oldData.ChannelMax[10])
            emit ChannelMax_10Changed(data.ChannelMax[10]);
        //if (data.ChannelMax[11] != oldData.ChannelMax[11])
            emit ChannelMax_11Changed(data.ChannelMax[11]);
        //if (data.ChannelNeutral[0] != oldData.ChannelNeutral[0])
            emit ChannelNeutral_0Changed(data.ChannelNeutral[0]);
        //if (data.ChannelNeutral[1] != oldData.ChannelNeutral[1])
            emit ChannelNeutral_1Changed(data.ChannelNeutral[1]);
        //if (data.ChannelNeutral[2] != oldData.ChannelNeutral[2])
            emit ChannelNeutral_2Changed(data.ChannelNeutral[2]);
        //if (data.ChannelNeutral[3] != oldData.ChannelNeutral[3])
            emit ChannelNeutral_3Changed(data.ChannelNeutral[3]);
        //if (data.ChannelNeutral[4] != oldData.ChannelNeutral[4])
            emit ChannelNeutral_4Changed(data.ChannelNeutral[4]);
        //if (data.ChannelNeutral[5] != oldData.ChannelNeutral[5])
            emit ChannelNeutral_5Changed(data.ChannelNeutral[5]);
        //if (data.ChannelNeutral[6] != oldData.ChannelNeutral[6])
            emit ChannelNeutral_6Changed(data.ChannelNeutral[6]);
        //if (data.ChannelNeutral[7] != oldData.ChannelNeutral[7])
            emit ChannelNeutral_7Changed(data.ChannelNeutral[7]);
        //if (data.ChannelNeutral[8] != oldData.ChannelNeutral[8])
            emit ChannelNeutral_8Changed(data.ChannelNeutral[8]);
        //if (data.ChannelNeutral[9] != oldData.ChannelNeutral[9])
            emit ChannelNeutral_9Changed(data.ChannelNeutral[9]);
        //if (data.ChannelNeutral[10] != oldData.ChannelNeutral[10])
            emit ChannelNeutral_10Changed(data.ChannelNeutral[10]);
        //if (data.ChannelNeutral[11] != oldData.ChannelNeutral[11])
            emit ChannelNeutral_11Changed(data.ChannelNeutral[11]);
        //if (data.ChannelMin[0] != oldData.ChannelMin[0])
            emit ChannelMin_0Changed(data.ChannelMin[0]);
        //if (data.ChannelMin[1] != oldData.ChannelMin[1])
            emit ChannelMin_1Changed(data.ChannelMin[1]);
        //if (data.ChannelMin[2] != oldData.ChannelMin[2])
            emit ChannelMin_2Changed(data.ChannelMin[2]);
        //if (data.ChannelMin[3] != oldData.ChannelMin[3])
            emit ChannelMin_3Changed(data.ChannelMin[3]);
        //if (data.ChannelMin[4] != oldData.ChannelMin[4])
            emit ChannelMin_4Changed(data.ChannelMin[4]);
        //if (data.ChannelMin[5] != oldData.ChannelMin[5])
            emit ChannelMin_5Changed(data.ChannelMin[5]);
        //if (data.ChannelMin[6] != oldData.ChannelMin[6])
            emit ChannelMin_6Changed(data.ChannelMin[6]);
        //if (data.ChannelMin[7] != oldData.ChannelMin[7])
            emit ChannelMin_7Changed(data.ChannelMin[7]);
        //if (data.ChannelMin[8] != oldData.ChannelMin[8])
            emit ChannelMin_8Changed(data.ChannelMin[8]);
        //if (data.ChannelMin[9] != oldData.ChannelMin[9])
            emit ChannelMin_9Changed(data.ChannelMin[9]);
        //if (data.ChannelMin[10] != oldData.ChannelMin[10])
            emit ChannelMin_10Changed(data.ChannelMin[10]);
        //if (data.ChannelMin[11] != oldData.ChannelMin[11])
            emit ChannelMin_11Changed(data.ChannelMin[11]);
        //if (data.ChannelType[0] != oldData.ChannelType[0])
            emit ChannelType_0Changed(data.ChannelType[0]);
        //if (data.ChannelType[1] != oldData.ChannelType[1])
            emit ChannelType_1Changed(data.ChannelType[1]);
        //if (data.ChannelType[2] != oldData.ChannelType[2])
            emit ChannelType_2Changed(data.ChannelType[2]);
        //if (data.ChannelType[3] != oldData.ChannelType[3])
            emit ChannelType_3Changed(data.ChannelType[3]);
        //if (data.ChannelType[4] != oldData.ChannelType[4])
            emit ChannelType_4Changed(data.ChannelType[4]);
        //if (data.ChannelType[5] != oldData.ChannelType[5])
            emit ChannelType_5Changed(data.ChannelType[5]);
        //if (data.ChannelType[6] != oldData.ChannelType[6])
            emit ChannelType_6Changed(data.ChannelType[6]);
        //if (data.ChannelType[7] != oldData.ChannelType[7])
            emit ChannelType_7Changed(data.ChannelType[7]);
        //if (data.ChannelType[8] != oldData.ChannelType[8])
            emit ChannelType_8Changed(data.ChannelType[8]);
        //if (data.ChannelType[9] != oldData.ChannelType[9])
            emit ChannelType_9Changed(data.ChannelType[9]);
        //if (data.ChannelType[10] != oldData.ChannelType[10])
            emit ChannelType_10Changed(data.ChannelType[10]);
        //if (data.ChannelType[11] != oldData.ChannelType[11])
            emit ChannelType_11Changed(data.ChannelType[11]);
        //if (data.ChannelAddr[0] != oldData.ChannelAddr[0])
            emit ChannelAddr_0Changed(data.ChannelAddr[0]);
        //if (data.ChannelAddr[1] != oldData.ChannelAddr[1])
            emit ChannelAddr_1Changed(data.ChannelAddr[1]);
        //if (data.ChannelAddr[2] != oldData.ChannelAddr[2])
            emit ChannelAddr_2Changed(data.ChannelAddr[2]);
        //if (data.ChannelAddr[3] != oldData.ChannelAddr[3])
            emit ChannelAddr_3Changed(data.ChannelAddr[3]);
        //if (data.ChannelAddr[4] != oldData.ChannelAddr[4])
            emit ChannelAddr_4Changed(data.ChannelAddr[4]);
        //if (data.ChannelAddr[5] != oldData.ChannelAddr[5])
            emit ChannelAddr_5Changed(data.ChannelAddr[5]);
        //if (data.ChannelAddr[6] != oldData.ChannelAddr[6])
            emit ChannelAddr_6Changed(data.ChannelAddr[6]);
        //if (data.ChannelAddr[7] != oldData.ChannelAddr[7])
            emit ChannelAddr_7Changed(data.ChannelAddr[7]);
        //if (data.ChannelAddr[8] != oldData.ChannelAddr[8])
            emit ChannelAddr_8Changed(data.ChannelAddr[8]);
        //if (data.ChannelAddr[9] != oldData.ChannelAddr[9])
            emit ChannelAddr_9Changed(data.ChannelAddr[9]);
        //if (data.ChannelAddr[10] != oldData.ChannelAddr[10])
            emit ChannelAddr_10Changed(data.ChannelAddr[10]);
        //if (data.ChannelAddr[11] != oldData.ChannelAddr[11])
            emit ChannelAddr_11Changed(data.ChannelAddr[11]);
        //if (data.MotorsSpinWhileArmed != oldData.MotorsSpinWhileArmed)
            emit MotorsSpinWhileArmedChanged(data.MotorsSpinWhileArmed);
        //if (data.LowThrottleZeroAxis[0] != oldData.LowThrottleZeroAxis[0])
            emit LowThrottleZeroAxis_RollChanged(data.LowThrottleZeroAxis[0]);
        //if (data.LowThrottleZeroAxis[1] != oldData.LowThrottleZeroAxis[1])
            emit LowThrottleZeroAxis_PitchChanged(data.LowThrottleZeroAxis[1]);
        //if (data.LowThrottleZeroAxis[2] != oldData.LowThrottleZeroAxis[2])
            emit LowThrottleZeroAxis_YawChanged(data.LowThrottleZeroAxis[2]);

}

/**
 * Create a clone of this object, a new instance ID must be specified.
 * Do not use this function directly to create new instances, the
 * UAVObjectManager should be used instead.
 */
UAVDataObject *ActuatorSettings::clone(quint32 instID)
{
    ActuatorSettings *obj = new ActuatorSettings();
    obj->initialize(instID, this->getMetaObject());
    return obj;
}

/**
 * Create a clone of this object only to be used to retrieve defaults
 */
UAVDataObject *ActuatorSettings::dirtyClone()
{
    ActuatorSettings *obj = new ActuatorSettings();
    return obj;
}

/**
 * Static function to retrieve an instance of the object.
 */
ActuatorSettings *ActuatorSettings::GetInstance(UAVObjectManager *objMngr, quint32 instID)
{
    return dynamic_cast<ActuatorSettings *>(objMngr->getObject(ActuatorSettings::OBJID, instID));
}

quint16 ActuatorSettings::getChannelUpdateFreq(quint32 index) const
{
   QMutexLocker locker(mutex);
   return data.ChannelUpdateFreq[index];
}
void ActuatorSettings::setChannelUpdateFreq(quint32 index, quint16 value)
{
   mutex->lock();
   bool changed = data.ChannelUpdateFreq[index] != value;
   data.ChannelUpdateFreq[index] = value;
   mutex->unlock();
   if (changed) emit ChannelUpdateFreqChanged(index,value);
}

quint16 ActuatorSettings::getChannelUpdateFreq_0() const
{
   QMutexLocker locker(mutex);
   return data.ChannelUpdateFreq[0];
}
void ActuatorSettings::setChannelUpdateFreq_0(quint16 value)
{
   mutex->lock();
   bool changed = data.ChannelUpdateFreq[0] != value;
   data.ChannelUpdateFreq[0] = value;
   mutex->unlock();
   if (changed) emit ChannelUpdateFreq_0Changed(value);
}

quint16 ActuatorSettings::getChannelUpdateFreq_1() const
{
   QMutexLocker locker(mutex);
   return data.ChannelUpdateFreq[1];
}
void ActuatorSettings::setChannelUpdateFreq_1(quint16 value)
{
   mutex->lock();
   bool changed = data.ChannelUpdateFreq[1] != value;
   data.ChannelUpdateFreq[1] = value;
   mutex->unlock();
   if (changed) emit ChannelUpdateFreq_1Changed(value);
}

quint16 ActuatorSettings::getChannelUpdateFreq_2() const
{
   QMutexLocker locker(mutex);
   return data.ChannelUpdateFreq[2];
}
void ActuatorSettings::setChannelUpdateFreq_2(quint16 value)
{
   mutex->lock();
   bool changed = data.ChannelUpdateFreq[2] != value;
   data.ChannelUpdateFreq[2] = value;
   mutex->unlock();
   if (changed) emit ChannelUpdateFreq_2Changed(value);
}

quint16 ActuatorSettings::getChannelUpdateFreq_3() const
{
   QMutexLocker locker(mutex);
   return data.ChannelUpdateFreq[3];
}
void ActuatorSettings::setChannelUpdateFreq_3(quint16 value)
{
   mutex->lock();
   bool changed = data.ChannelUpdateFreq[3] != value;
   data.ChannelUpdateFreq[3] = value;
   mutex->unlock();
   if (changed) emit ChannelUpdateFreq_3Changed(value);
}

quint16 ActuatorSettings::getChannelUpdateFreq_4() const
{
   QMutexLocker locker(mutex);
   return data.ChannelUpdateFreq[4];
}
void ActuatorSettings::setChannelUpdateFreq_4(quint16 value)
{
   mutex->lock();
   bool changed = data.ChannelUpdateFreq[4] != value;
   data.ChannelUpdateFreq[4] = value;
   mutex->unlock();
   if (changed) emit ChannelUpdateFreq_4Changed(value);
}

quint16 ActuatorSettings::getChannelUpdateFreq_5() const
{
   QMutexLocker locker(mutex);
   return data.ChannelUpdateFreq[5];
}
void ActuatorSettings::setChannelUpdateFreq_5(quint16 value)
{
   mutex->lock();
   bool changed = data.ChannelUpdateFreq[5] != value;
   data.ChannelUpdateFreq[5] = value;
   mutex->unlock();
   if (changed) emit ChannelUpdateFreq_5Changed(value);
}

qint16 ActuatorSettings::getChannelMax(quint32 index) const
{
   QMutexLocker locker(mutex);
   return data.ChannelMax[index];
}
void ActuatorSettings::setChannelMax(quint32 index, qint16 value)
{
   mutex->lock();
   bool changed = data.ChannelMax[index] != value;
   data.ChannelMax[index] = value;
   mutex->unlock();
   if (changed) emit ChannelMaxChanged(index,value);
}

qint16 ActuatorSettings::getChannelMax_0() const
{
   QMutexLocker locker(mutex);
   return data.ChannelMax[0];
}
void ActuatorSettings::setChannelMax_0(qint16 value)
{
   mutex->lock();
   bool changed = data.ChannelMax[0] != value;
   data.ChannelMax[0] = value;
   mutex->unlock();
   if (changed) emit ChannelMax_0Changed(value);
}

qint16 ActuatorSettings::getChannelMax_1() const
{
   QMutexLocker locker(mutex);
   return data.ChannelMax[1];
}
void ActuatorSettings::setChannelMax_1(qint16 value)
{
   mutex->lock();
   bool changed = data.ChannelMax[1] != value;
   data.ChannelMax[1] = value;
   mutex->unlock();
   if (changed) emit ChannelMax_1Changed(value);
}

qint16 ActuatorSettings::getChannelMax_2() const
{
   QMutexLocker locker(mutex);
   return data.ChannelMax[2];
}
void ActuatorSettings::setChannelMax_2(qint16 value)
{
   mutex->lock();
   bool changed = data.ChannelMax[2] != value;
   data.ChannelMax[2] = value;
   mutex->unlock();
   if (changed) emit ChannelMax_2Changed(value);
}

qint16 ActuatorSettings::getChannelMax_3() const
{
   QMutexLocker locker(mutex);
   return data.ChannelMax[3];
}
void ActuatorSettings::setChannelMax_3(qint16 value)
{
   mutex->lock();
   bool changed = data.ChannelMax[3] != value;
   data.ChannelMax[3] = value;
   mutex->unlock();
   if (changed) emit ChannelMax_3Changed(value);
}

qint16 ActuatorSettings::getChannelMax_4() const
{
   QMutexLocker locker(mutex);
   return data.ChannelMax[4];
}
void ActuatorSettings::setChannelMax_4(qint16 value)
{
   mutex->lock();
   bool changed = data.ChannelMax[4] != value;
   data.ChannelMax[4] = value;
   mutex->unlock();
   if (changed) emit ChannelMax_4Changed(value);
}

qint16 ActuatorSettings::getChannelMax_5() const
{
   QMutexLocker locker(mutex);
   return data.ChannelMax[5];
}
void ActuatorSettings::setChannelMax_5(qint16 value)
{
   mutex->lock();
   bool changed = data.ChannelMax[5] != value;
   data.ChannelMax[5] = value;
   mutex->unlock();
   if (changed) emit ChannelMax_5Changed(value);
}

qint16 ActuatorSettings::getChannelMax_6() const
{
   QMutexLocker locker(mutex);
   return data.ChannelMax[6];
}
void ActuatorSettings::setChannelMax_6(qint16 value)
{
   mutex->lock();
   bool changed = data.ChannelMax[6] != value;
   data.ChannelMax[6] = value;
   mutex->unlock();
   if (changed) emit ChannelMax_6Changed(value);
}

qint16 ActuatorSettings::getChannelMax_7() const
{
   QMutexLocker locker(mutex);
   return data.ChannelMax[7];
}
void ActuatorSettings::setChannelMax_7(qint16 value)
{
   mutex->lock();
   bool changed = data.ChannelMax[7] != value;
   data.ChannelMax[7] = value;
   mutex->unlock();
   if (changed) emit ChannelMax_7Changed(value);
}

qint16 ActuatorSettings::getChannelMax_8() const
{
   QMutexLocker locker(mutex);
   return data.ChannelMax[8];
}
void ActuatorSettings::setChannelMax_8(qint16 value)
{
   mutex->lock();
   bool changed = data.ChannelMax[8] != value;
   data.ChannelMax[8] = value;
   mutex->unlock();
   if (changed) emit ChannelMax_8Changed(value);
}

qint16 ActuatorSettings::getChannelMax_9() const
{
   QMutexLocker locker(mutex);
   return data.ChannelMax[9];
}
void ActuatorSettings::setChannelMax_9(qint16 value)
{
   mutex->lock();
   bool changed = data.ChannelMax[9] != value;
   data.ChannelMax[9] = value;
   mutex->unlock();
   if (changed) emit ChannelMax_9Changed(value);
}

qint16 ActuatorSettings::getChannelMax_10() const
{
   QMutexLocker locker(mutex);
   return data.ChannelMax[10];
}
void ActuatorSettings::setChannelMax_10(qint16 value)
{
   mutex->lock();
   bool changed = data.ChannelMax[10] != value;
   data.ChannelMax[10] = value;
   mutex->unlock();
   if (changed) emit ChannelMax_10Changed(value);
}

qint16 ActuatorSettings::getChannelMax_11() const
{
   QMutexLocker locker(mutex);
   return data.ChannelMax[11];
}
void ActuatorSettings::setChannelMax_11(qint16 value)
{
   mutex->lock();
   bool changed = data.ChannelMax[11] != value;
   data.ChannelMax[11] = value;
   mutex->unlock();
   if (changed) emit ChannelMax_11Changed(value);
}

qint16 ActuatorSettings::getChannelNeutral(quint32 index) const
{
   QMutexLocker locker(mutex);
   return data.ChannelNeutral[index];
}
void ActuatorSettings::setChannelNeutral(quint32 index, qint16 value)
{
   mutex->lock();
   bool changed = data.ChannelNeutral[index] != value;
   data.ChannelNeutral[index] = value;
   mutex->unlock();
   if (changed) emit ChannelNeutralChanged(index,value);
}

qint16 ActuatorSettings::getChannelNeutral_0() const
{
   QMutexLocker locker(mutex);
   return data.ChannelNeutral[0];
}
void ActuatorSettings::setChannelNeutral_0(qint16 value)
{
   mutex->lock();
   bool changed = data.ChannelNeutral[0] != value;
   data.ChannelNeutral[0] = value;
   mutex->unlock();
   if (changed) emit ChannelNeutral_0Changed(value);
}

qint16 ActuatorSettings::getChannelNeutral_1() const
{
   QMutexLocker locker(mutex);
   return data.ChannelNeutral[1];
}
void ActuatorSettings::setChannelNeutral_1(qint16 value)
{
   mutex->lock();
   bool changed = data.ChannelNeutral[1] != value;
   data.ChannelNeutral[1] = value;
   mutex->unlock();
   if (changed) emit ChannelNeutral_1Changed(value);
}

qint16 ActuatorSettings::getChannelNeutral_2() const
{
   QMutexLocker locker(mutex);
   return data.ChannelNeutral[2];
}
void ActuatorSettings::setChannelNeutral_2(qint16 value)
{
   mutex->lock();
   bool changed = data.ChannelNeutral[2] != value;
   data.ChannelNeutral[2] = value;
   mutex->unlock();
   if (changed) emit ChannelNeutral_2Changed(value);
}

qint16 ActuatorSettings::getChannelNeutral_3() const
{
   QMutexLocker locker(mutex);
   return data.ChannelNeutral[3];
}
void ActuatorSettings::setChannelNeutral_3(qint16 value)
{
   mutex->lock();
   bool changed = data.ChannelNeutral[3] != value;
   data.ChannelNeutral[3] = value;
   mutex->unlock();
   if (changed) emit ChannelNeutral_3Changed(value);
}

qint16 ActuatorSettings::getChannelNeutral_4() const
{
   QMutexLocker locker(mutex);
   return data.ChannelNeutral[4];
}
void ActuatorSettings::setChannelNeutral_4(qint16 value)
{
   mutex->lock();
   bool changed = data.ChannelNeutral[4] != value;
   data.ChannelNeutral[4] = value;
   mutex->unlock();
   if (changed) emit ChannelNeutral_4Changed(value);
}

qint16 ActuatorSettings::getChannelNeutral_5() const
{
   QMutexLocker locker(mutex);
   return data.ChannelNeutral[5];
}
void ActuatorSettings::setChannelNeutral_5(qint16 value)
{
   mutex->lock();
   bool changed = data.ChannelNeutral[5] != value;
   data.ChannelNeutral[5] = value;
   mutex->unlock();
   if (changed) emit ChannelNeutral_5Changed(value);
}

qint16 ActuatorSettings::getChannelNeutral_6() const
{
   QMutexLocker locker(mutex);
   return data.ChannelNeutral[6];
}
void ActuatorSettings::setChannelNeutral_6(qint16 value)
{
   mutex->lock();
   bool changed = data.ChannelNeutral[6] != value;
   data.ChannelNeutral[6] = value;
   mutex->unlock();
   if (changed) emit ChannelNeutral_6Changed(value);
}

qint16 ActuatorSettings::getChannelNeutral_7() const
{
   QMutexLocker locker(mutex);
   return data.ChannelNeutral[7];
}
void ActuatorSettings::setChannelNeutral_7(qint16 value)
{
   mutex->lock();
   bool changed = data.ChannelNeutral[7] != value;
   data.ChannelNeutral[7] = value;
   mutex->unlock();
   if (changed) emit ChannelNeutral_7Changed(value);
}

qint16 ActuatorSettings::getChannelNeutral_8() const
{
   QMutexLocker locker(mutex);
   return data.ChannelNeutral[8];
}
void ActuatorSettings::setChannelNeutral_8(qint16 value)
{
   mutex->lock();
   bool changed = data.ChannelNeutral[8] != value;
   data.ChannelNeutral[8] = value;
   mutex->unlock();
   if (changed) emit ChannelNeutral_8Changed(value);
}

qint16 ActuatorSettings::getChannelNeutral_9() const
{
   QMutexLocker locker(mutex);
   return data.ChannelNeutral[9];
}
void ActuatorSettings::setChannelNeutral_9(qint16 value)
{
   mutex->lock();
   bool changed = data.ChannelNeutral[9] != value;
   data.ChannelNeutral[9] = value;
   mutex->unlock();
   if (changed) emit ChannelNeutral_9Changed(value);
}

qint16 ActuatorSettings::getChannelNeutral_10() const
{
   QMutexLocker locker(mutex);
   return data.ChannelNeutral[10];
}
void ActuatorSettings::setChannelNeutral_10(qint16 value)
{
   mutex->lock();
   bool changed = data.ChannelNeutral[10] != value;
   data.ChannelNeutral[10] = value;
   mutex->unlock();
   if (changed) emit ChannelNeutral_10Changed(value);
}

qint16 ActuatorSettings::getChannelNeutral_11() const
{
   QMutexLocker locker(mutex);
   return data.ChannelNeutral[11];
}
void ActuatorSettings::setChannelNeutral_11(qint16 value)
{
   mutex->lock();
   bool changed = data.ChannelNeutral[11] != value;
   data.ChannelNeutral[11] = value;
   mutex->unlock();
   if (changed) emit ChannelNeutral_11Changed(value);
}

qint16 ActuatorSettings::getChannelMin(quint32 index) const
{
   QMutexLocker locker(mutex);
   return data.ChannelMin[index];
}
void ActuatorSettings::setChannelMin(quint32 index, qint16 value)
{
   mutex->lock();
   bool changed = data.ChannelMin[index] != value;
   data.ChannelMin[index] = value;
   mutex->unlock();
   if (changed) emit ChannelMinChanged(index,value);
}

qint16 ActuatorSettings::getChannelMin_0() const
{
   QMutexLocker locker(mutex);
   return data.ChannelMin[0];
}
void ActuatorSettings::setChannelMin_0(qint16 value)
{
   mutex->lock();
   bool changed = data.ChannelMin[0] != value;
   data.ChannelMin[0] = value;
   mutex->unlock();
   if (changed) emit ChannelMin_0Changed(value);
}

qint16 ActuatorSettings::getChannelMin_1() const
{
   QMutexLocker locker(mutex);
   return data.ChannelMin[1];
}
void ActuatorSettings::setChannelMin_1(qint16 value)
{
   mutex->lock();
   bool changed = data.ChannelMin[1] != value;
   data.ChannelMin[1] = value;
   mutex->unlock();
   if (changed) emit ChannelMin_1Changed(value);
}

qint16 ActuatorSettings::getChannelMin_2() const
{
   QMutexLocker locker(mutex);
   return data.ChannelMin[2];
}
void ActuatorSettings::setChannelMin_2(qint16 value)
{
   mutex->lock();
   bool changed = data.ChannelMin[2] != value;
   data.ChannelMin[2] = value;
   mutex->unlock();
   if (changed) emit ChannelMin_2Changed(value);
}

qint16 ActuatorSettings::getChannelMin_3() const
{
   QMutexLocker locker(mutex);
   return data.ChannelMin[3];
}
void ActuatorSettings::setChannelMin_3(qint16 value)
{
   mutex->lock();
   bool changed = data.ChannelMin[3] != value;
   data.ChannelMin[3] = value;
   mutex->unlock();
   if (changed) emit ChannelMin_3Changed(value);
}

qint16 ActuatorSettings::getChannelMin_4() const
{
   QMutexLocker locker(mutex);
   return data.ChannelMin[4];
}
void ActuatorSettings::setChannelMin_4(qint16 value)
{
   mutex->lock();
   bool changed = data.ChannelMin[4] != value;
   data.ChannelMin[4] = value;
   mutex->unlock();
   if (changed) emit ChannelMin_4Changed(value);
}

qint16 ActuatorSettings::getChannelMin_5() const
{
   QMutexLocker locker(mutex);
   return data.ChannelMin[5];
}
void ActuatorSettings::setChannelMin_5(qint16 value)
{
   mutex->lock();
   bool changed = data.ChannelMin[5] != value;
   data.ChannelMin[5] = value;
   mutex->unlock();
   if (changed) emit ChannelMin_5Changed(value);
}

qint16 ActuatorSettings::getChannelMin_6() const
{
   QMutexLocker locker(mutex);
   return data.ChannelMin[6];
}
void ActuatorSettings::setChannelMin_6(qint16 value)
{
   mutex->lock();
   bool changed = data.ChannelMin[6] != value;
   data.ChannelMin[6] = value;
   mutex->unlock();
   if (changed) emit ChannelMin_6Changed(value);
}

qint16 ActuatorSettings::getChannelMin_7() const
{
   QMutexLocker locker(mutex);
   return data.ChannelMin[7];
}
void ActuatorSettings::setChannelMin_7(qint16 value)
{
   mutex->lock();
   bool changed = data.ChannelMin[7] != value;
   data.ChannelMin[7] = value;
   mutex->unlock();
   if (changed) emit ChannelMin_7Changed(value);
}

qint16 ActuatorSettings::getChannelMin_8() const
{
   QMutexLocker locker(mutex);
   return data.ChannelMin[8];
}
void ActuatorSettings::setChannelMin_8(qint16 value)
{
   mutex->lock();
   bool changed = data.ChannelMin[8] != value;
   data.ChannelMin[8] = value;
   mutex->unlock();
   if (changed) emit ChannelMin_8Changed(value);
}

qint16 ActuatorSettings::getChannelMin_9() const
{
   QMutexLocker locker(mutex);
   return data.ChannelMin[9];
}
void ActuatorSettings::setChannelMin_9(qint16 value)
{
   mutex->lock();
   bool changed = data.ChannelMin[9] != value;
   data.ChannelMin[9] = value;
   mutex->unlock();
   if (changed) emit ChannelMin_9Changed(value);
}

qint16 ActuatorSettings::getChannelMin_10() const
{
   QMutexLocker locker(mutex);
   return data.ChannelMin[10];
}
void ActuatorSettings::setChannelMin_10(qint16 value)
{
   mutex->lock();
   bool changed = data.ChannelMin[10] != value;
   data.ChannelMin[10] = value;
   mutex->unlock();
   if (changed) emit ChannelMin_10Changed(value);
}

qint16 ActuatorSettings::getChannelMin_11() const
{
   QMutexLocker locker(mutex);
   return data.ChannelMin[11];
}
void ActuatorSettings::setChannelMin_11(qint16 value)
{
   mutex->lock();
   bool changed = data.ChannelMin[11] != value;
   data.ChannelMin[11] = value;
   mutex->unlock();
   if (changed) emit ChannelMin_11Changed(value);
}

quint8 ActuatorSettings::getChannelType(quint32 index) const
{
   QMutexLocker locker(mutex);
   return data.ChannelType[index];
}
void ActuatorSettings::setChannelType(quint32 index, quint8 value)
{
   mutex->lock();
   bool changed = data.ChannelType[index] != value;
   data.ChannelType[index] = value;
   mutex->unlock();
   if (changed) emit ChannelTypeChanged(index,value);
}

quint8 ActuatorSettings::getChannelType_0() const
{
   QMutexLocker locker(mutex);
   return data.ChannelType[0];
}
void ActuatorSettings::setChannelType_0(quint8 value)
{
   mutex->lock();
   bool changed = data.ChannelType[0] != value;
   data.ChannelType[0] = value;
   mutex->unlock();
   if (changed) emit ChannelType_0Changed(value);
}

quint8 ActuatorSettings::getChannelType_1() const
{
   QMutexLocker locker(mutex);
   return data.ChannelType[1];
}
void ActuatorSettings::setChannelType_1(quint8 value)
{
   mutex->lock();
   bool changed = data.ChannelType[1] != value;
   data.ChannelType[1] = value;
   mutex->unlock();
   if (changed) emit ChannelType_1Changed(value);
}

quint8 ActuatorSettings::getChannelType_2() const
{
   QMutexLocker locker(mutex);
   return data.ChannelType[2];
}
void ActuatorSettings::setChannelType_2(quint8 value)
{
   mutex->lock();
   bool changed = data.ChannelType[2] != value;
   data.ChannelType[2] = value;
   mutex->unlock();
   if (changed) emit ChannelType_2Changed(value);
}

quint8 ActuatorSettings::getChannelType_3() const
{
   QMutexLocker locker(mutex);
   return data.ChannelType[3];
}
void ActuatorSettings::setChannelType_3(quint8 value)
{
   mutex->lock();
   bool changed = data.ChannelType[3] != value;
   data.ChannelType[3] = value;
   mutex->unlock();
   if (changed) emit ChannelType_3Changed(value);
}

quint8 ActuatorSettings::getChannelType_4() const
{
   QMutexLocker locker(mutex);
   return data.ChannelType[4];
}
void ActuatorSettings::setChannelType_4(quint8 value)
{
   mutex->lock();
   bool changed = data.ChannelType[4] != value;
   data.ChannelType[4] = value;
   mutex->unlock();
   if (changed) emit ChannelType_4Changed(value);
}

quint8 ActuatorSettings::getChannelType_5() const
{
   QMutexLocker locker(mutex);
   return data.ChannelType[5];
}
void ActuatorSettings::setChannelType_5(quint8 value)
{
   mutex->lock();
   bool changed = data.ChannelType[5] != value;
   data.ChannelType[5] = value;
   mutex->unlock();
   if (changed) emit ChannelType_5Changed(value);
}

quint8 ActuatorSettings::getChannelType_6() const
{
   QMutexLocker locker(mutex);
   return data.ChannelType[6];
}
void ActuatorSettings::setChannelType_6(quint8 value)
{
   mutex->lock();
   bool changed = data.ChannelType[6] != value;
   data.ChannelType[6] = value;
   mutex->unlock();
   if (changed) emit ChannelType_6Changed(value);
}

quint8 ActuatorSettings::getChannelType_7() const
{
   QMutexLocker locker(mutex);
   return data.ChannelType[7];
}
void ActuatorSettings::setChannelType_7(quint8 value)
{
   mutex->lock();
   bool changed = data.ChannelType[7] != value;
   data.ChannelType[7] = value;
   mutex->unlock();
   if (changed) emit ChannelType_7Changed(value);
}

quint8 ActuatorSettings::getChannelType_8() const
{
   QMutexLocker locker(mutex);
   return data.ChannelType[8];
}
void ActuatorSettings::setChannelType_8(quint8 value)
{
   mutex->lock();
   bool changed = data.ChannelType[8] != value;
   data.ChannelType[8] = value;
   mutex->unlock();
   if (changed) emit ChannelType_8Changed(value);
}

quint8 ActuatorSettings::getChannelType_9() const
{
   QMutexLocker locker(mutex);
   return data.ChannelType[9];
}
void ActuatorSettings::setChannelType_9(quint8 value)
{
   mutex->lock();
   bool changed = data.ChannelType[9] != value;
   data.ChannelType[9] = value;
   mutex->unlock();
   if (changed) emit ChannelType_9Changed(value);
}

quint8 ActuatorSettings::getChannelType_10() const
{
   QMutexLocker locker(mutex);
   return data.ChannelType[10];
}
void ActuatorSettings::setChannelType_10(quint8 value)
{
   mutex->lock();
   bool changed = data.ChannelType[10] != value;
   data.ChannelType[10] = value;
   mutex->unlock();
   if (changed) emit ChannelType_10Changed(value);
}

quint8 ActuatorSettings::getChannelType_11() const
{
   QMutexLocker locker(mutex);
   return data.ChannelType[11];
}
void ActuatorSettings::setChannelType_11(quint8 value)
{
   mutex->lock();
   bool changed = data.ChannelType[11] != value;
   data.ChannelType[11] = value;
   mutex->unlock();
   if (changed) emit ChannelType_11Changed(value);
}

quint8 ActuatorSettings::getChannelAddr(quint32 index) const
{
   QMutexLocker locker(mutex);
   return data.ChannelAddr[index];
}
void ActuatorSettings::setChannelAddr(quint32 index, quint8 value)
{
   mutex->lock();
   bool changed = data.ChannelAddr[index] != value;
   data.ChannelAddr[index] = value;
   mutex->unlock();
   if (changed) emit ChannelAddrChanged(index,value);
}

quint8 ActuatorSettings::getChannelAddr_0() const
{
   QMutexLocker locker(mutex);
   return data.ChannelAddr[0];
}
void ActuatorSettings::setChannelAddr_0(quint8 value)
{
   mutex->lock();
   bool changed = data.ChannelAddr[0] != value;
   data.ChannelAddr[0] = value;
   mutex->unlock();
   if (changed) emit ChannelAddr_0Changed(value);
}

quint8 ActuatorSettings::getChannelAddr_1() const
{
   QMutexLocker locker(mutex);
   return data.ChannelAddr[1];
}
void ActuatorSettings::setChannelAddr_1(quint8 value)
{
   mutex->lock();
   bool changed = data.ChannelAddr[1] != value;
   data.ChannelAddr[1] = value;
   mutex->unlock();
   if (changed) emit ChannelAddr_1Changed(value);
}

quint8 ActuatorSettings::getChannelAddr_2() const
{
   QMutexLocker locker(mutex);
   return data.ChannelAddr[2];
}
void ActuatorSettings::setChannelAddr_2(quint8 value)
{
   mutex->lock();
   bool changed = data.ChannelAddr[2] != value;
   data.ChannelAddr[2] = value;
   mutex->unlock();
   if (changed) emit ChannelAddr_2Changed(value);
}

quint8 ActuatorSettings::getChannelAddr_3() const
{
   QMutexLocker locker(mutex);
   return data.ChannelAddr[3];
}
void ActuatorSettings::setChannelAddr_3(quint8 value)
{
   mutex->lock();
   bool changed = data.ChannelAddr[3] != value;
   data.ChannelAddr[3] = value;
   mutex->unlock();
   if (changed) emit ChannelAddr_3Changed(value);
}

quint8 ActuatorSettings::getChannelAddr_4() const
{
   QMutexLocker locker(mutex);
   return data.ChannelAddr[4];
}
void ActuatorSettings::setChannelAddr_4(quint8 value)
{
   mutex->lock();
   bool changed = data.ChannelAddr[4] != value;
   data.ChannelAddr[4] = value;
   mutex->unlock();
   if (changed) emit ChannelAddr_4Changed(value);
}

quint8 ActuatorSettings::getChannelAddr_5() const
{
   QMutexLocker locker(mutex);
   return data.ChannelAddr[5];
}
void ActuatorSettings::setChannelAddr_5(quint8 value)
{
   mutex->lock();
   bool changed = data.ChannelAddr[5] != value;
   data.ChannelAddr[5] = value;
   mutex->unlock();
   if (changed) emit ChannelAddr_5Changed(value);
}

quint8 ActuatorSettings::getChannelAddr_6() const
{
   QMutexLocker locker(mutex);
   return data.ChannelAddr[6];
}
void ActuatorSettings::setChannelAddr_6(quint8 value)
{
   mutex->lock();
   bool changed = data.ChannelAddr[6] != value;
   data.ChannelAddr[6] = value;
   mutex->unlock();
   if (changed) emit ChannelAddr_6Changed(value);
}

quint8 ActuatorSettings::getChannelAddr_7() const
{
   QMutexLocker locker(mutex);
   return data.ChannelAddr[7];
}
void ActuatorSettings::setChannelAddr_7(quint8 value)
{
   mutex->lock();
   bool changed = data.ChannelAddr[7] != value;
   data.ChannelAddr[7] = value;
   mutex->unlock();
   if (changed) emit ChannelAddr_7Changed(value);
}

quint8 ActuatorSettings::getChannelAddr_8() const
{
   QMutexLocker locker(mutex);
   return data.ChannelAddr[8];
}
void ActuatorSettings::setChannelAddr_8(quint8 value)
{
   mutex->lock();
   bool changed = data.ChannelAddr[8] != value;
   data.ChannelAddr[8] = value;
   mutex->unlock();
   if (changed) emit ChannelAddr_8Changed(value);
}

quint8 ActuatorSettings::getChannelAddr_9() const
{
   QMutexLocker locker(mutex);
   return data.ChannelAddr[9];
}
void ActuatorSettings::setChannelAddr_9(quint8 value)
{
   mutex->lock();
   bool changed = data.ChannelAddr[9] != value;
   data.ChannelAddr[9] = value;
   mutex->unlock();
   if (changed) emit ChannelAddr_9Changed(value);
}

quint8 ActuatorSettings::getChannelAddr_10() const
{
   QMutexLocker locker(mutex);
   return data.ChannelAddr[10];
}
void ActuatorSettings::setChannelAddr_10(quint8 value)
{
   mutex->lock();
   bool changed = data.ChannelAddr[10] != value;
   data.ChannelAddr[10] = value;
   mutex->unlock();
   if (changed) emit ChannelAddr_10Changed(value);
}

quint8 ActuatorSettings::getChannelAddr_11() const
{
   QMutexLocker locker(mutex);
   return data.ChannelAddr[11];
}
void ActuatorSettings::setChannelAddr_11(quint8 value)
{
   mutex->lock();
   bool changed = data.ChannelAddr[11] != value;
   data.ChannelAddr[11] = value;
   mutex->unlock();
   if (changed) emit ChannelAddr_11Changed(value);
}

quint8 ActuatorSettings::getMotorsSpinWhileArmed() const
{
   QMutexLocker locker(mutex);
   return data.MotorsSpinWhileArmed;
}
void ActuatorSettings::setMotorsSpinWhileArmed(quint8 value)
{
   mutex->lock();
   bool changed = data.MotorsSpinWhileArmed != value;
   data.MotorsSpinWhileArmed = value;
   mutex->unlock();
   if (changed) emit MotorsSpinWhileArmedChanged(value);
}

quint8 ActuatorSettings::getLowThrottleZeroAxis(quint32 index) const
{
   QMutexLocker locker(mutex);
   return data.LowThrottleZeroAxis[index];
}
void ActuatorSettings::setLowThrottleZeroAxis(quint32 index, quint8 value)
{
   mutex->lock();
   bool changed = data.LowThrottleZeroAxis[index] != value;
   data.LowThrottleZeroAxis[index] = value;
   mutex->unlock();
   if (changed) emit LowThrottleZeroAxisChanged(index,value);
}

quint8 ActuatorSettings::getLowThrottleZeroAxis_Roll() const
{
   QMutexLocker locker(mutex);
   return data.LowThrottleZeroAxis[0];
}
void ActuatorSettings::setLowThrottleZeroAxis_Roll(quint8 value)
{
   mutex->lock();
   bool changed = data.LowThrottleZeroAxis[0] != value;
   data.LowThrottleZeroAxis[0] = value;
   mutex->unlock();
   if (changed) emit LowThrottleZeroAxis_RollChanged(value);
}

quint8 ActuatorSettings::getLowThrottleZeroAxis_Pitch() const
{
   QMutexLocker locker(mutex);
   return data.LowThrottleZeroAxis[1];
}
void ActuatorSettings::setLowThrottleZeroAxis_Pitch(quint8 value)
{
   mutex->lock();
   bool changed = data.LowThrottleZeroAxis[1] != value;
   data.LowThrottleZeroAxis[1] = value;
   mutex->unlock();
   if (changed) emit LowThrottleZeroAxis_PitchChanged(value);
}

quint8 ActuatorSettings::getLowThrottleZeroAxis_Yaw() const
{
   QMutexLocker locker(mutex);
   return data.LowThrottleZeroAxis[2];
}
void ActuatorSettings::setLowThrottleZeroAxis_Yaw(quint8 value)
{
   mutex->lock();
   bool changed = data.LowThrottleZeroAxis[2] != value;
   data.LowThrottleZeroAxis[2] = value;
   mutex->unlock();
   if (changed) emit LowThrottleZeroAxis_YawChanged(value);
}


