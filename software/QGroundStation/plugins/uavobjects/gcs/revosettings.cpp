/**
 ******************************************************************************
 *
 * @file       revosettings.cpp
 * @author     The OpenPilot Team, http://www.openpilot.org Copyright (C) 2010.
 * @see        The GNU Public License (GPL) Version 3
 * @addtogroup GCSPlugins GCS Plugins
 * @{
 * @addtogroup UAVObjectsPlugin UAVObjects Plugin
 * @{
 *
 * @note       Object definition file: revosettings.xml.
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

#include "revosettings.h"
#include "uavobjectfield.h"

const QString RevoSettings::NAME = QString("RevoSettings");
const QString RevoSettings::DESCRIPTION = QString("Settings for the revo to control the algorithm and what is updated");
const QString RevoSettings::CATEGORY = QString("State");

/**
 * Constructor
 */
RevoSettings::RevoSettings(): UAVDataObject(OBJID, ISSINGLEINST, ISSETTINGS, NAME)
{
    // Create fields
    QList<UAVObjectField *> fields;
    QStringList BaroGPSOffsetCorrectionAlphaElemNames;
    BaroGPSOffsetCorrectionAlphaElemNames.append("0");
    fields.append( new UAVObjectField(QString("BaroGPSOffsetCorrectionAlpha"), QString(""), UAVObjectField::FLOAT32, BaroGPSOffsetCorrectionAlphaElemNames, QStringList(), QString("")));
    QStringList MagnetometerMaxDeviationElemNames;
    MagnetometerMaxDeviationElemNames.append("Warning");
    MagnetometerMaxDeviationElemNames.append("Error");
    fields.append( new UAVObjectField(QString("MagnetometerMaxDeviation"), QString("%"), UAVObjectField::FLOAT32, MagnetometerMaxDeviationElemNames, QStringList(), QString("")));
    QStringList BaroTempCorrectionPolynomialElemNames;
    BaroTempCorrectionPolynomialElemNames.append("a");
    BaroTempCorrectionPolynomialElemNames.append("b");
    BaroTempCorrectionPolynomialElemNames.append("c");
    BaroTempCorrectionPolynomialElemNames.append("d");
    fields.append( new UAVObjectField(QString("BaroTempCorrectionPolynomial"), QString(""), UAVObjectField::FLOAT32, BaroTempCorrectionPolynomialElemNames, QStringList(), QString("")));
    QStringList BaroTempCorrectionExtentElemNames;
    BaroTempCorrectionExtentElemNames.append("min");
    BaroTempCorrectionExtentElemNames.append("max");
    fields.append( new UAVObjectField(QString("BaroTempCorrectionExtent"), QString(""), UAVObjectField::FLOAT32, BaroTempCorrectionExtentElemNames, QStringList(), QString("")));
    QStringList FusionAlgorithmElemNames;
    FusionAlgorithmElemNames.append("0");
    QStringList FusionAlgorithmEnumOptions;
    FusionAlgorithmEnumOptions.append("None");
    FusionAlgorithmEnumOptions.append("Complementary");
    FusionAlgorithmEnumOptions.append("Complementary+Mag");
    FusionAlgorithmEnumOptions.append("Complementary+Mag+GPSOutdoor");
    FusionAlgorithmEnumOptions.append("INS13Indoor");
    FusionAlgorithmEnumOptions.append("INS13GPSOutdoor");
    fields.append( new UAVObjectField(QString("FusionAlgorithm"), QString(""), UAVObjectField::ENUM, FusionAlgorithmElemNames, FusionAlgorithmEnumOptions, QString("")));

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
UAVObject::Metadata RevoSettings::getDefaultMetadata()
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
void RevoSettings::setDefaultFieldValues()
{
    data.BaroGPSOffsetCorrectionAlpha = 0.999334;
    data.MagnetometerMaxDeviation[0] = 0.05;
    data.MagnetometerMaxDeviation[1] = 0.15;
    data.BaroTempCorrectionPolynomial[0] = 0;
    data.BaroTempCorrectionPolynomial[1] = 0;
    data.BaroTempCorrectionPolynomial[2] = 0;
    data.BaroTempCorrectionPolynomial[3] = 0;
    data.BaroTempCorrectionExtent[0] = 0;
    data.BaroTempCorrectionExtent[1] = 0;
    data.FusionAlgorithm = 1;

}

/**
 * Get the object data fields
 */
RevoSettings::DataFields RevoSettings::getData()
{
    QMutexLocker locker(mutex);
    return data;
}

/**
 * Set the object data fields
 */
void RevoSettings::setData(const DataFields& data)
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

void RevoSettings::emitNotifications()
{
            //if (data.BaroGPSOffsetCorrectionAlpha != oldData.BaroGPSOffsetCorrectionAlpha)
            emit BaroGPSOffsetCorrectionAlphaChanged(data.BaroGPSOffsetCorrectionAlpha);
        //if (data.MagnetometerMaxDeviation[0] != oldData.MagnetometerMaxDeviation[0])
            emit MagnetometerMaxDeviation_WarningChanged(data.MagnetometerMaxDeviation[0]);
        //if (data.MagnetometerMaxDeviation[1] != oldData.MagnetometerMaxDeviation[1])
            emit MagnetometerMaxDeviation_ErrorChanged(data.MagnetometerMaxDeviation[1]);
        //if (data.BaroTempCorrectionPolynomial[0] != oldData.BaroTempCorrectionPolynomial[0])
            emit BaroTempCorrectionPolynomial_aChanged(data.BaroTempCorrectionPolynomial[0]);
        //if (data.BaroTempCorrectionPolynomial[1] != oldData.BaroTempCorrectionPolynomial[1])
            emit BaroTempCorrectionPolynomial_bChanged(data.BaroTempCorrectionPolynomial[1]);
        //if (data.BaroTempCorrectionPolynomial[2] != oldData.BaroTempCorrectionPolynomial[2])
            emit BaroTempCorrectionPolynomial_cChanged(data.BaroTempCorrectionPolynomial[2]);
        //if (data.BaroTempCorrectionPolynomial[3] != oldData.BaroTempCorrectionPolynomial[3])
            emit BaroTempCorrectionPolynomial_dChanged(data.BaroTempCorrectionPolynomial[3]);
        //if (data.BaroTempCorrectionExtent[0] != oldData.BaroTempCorrectionExtent[0])
            emit BaroTempCorrectionExtent_minChanged(data.BaroTempCorrectionExtent[0]);
        //if (data.BaroTempCorrectionExtent[1] != oldData.BaroTempCorrectionExtent[1])
            emit BaroTempCorrectionExtent_maxChanged(data.BaroTempCorrectionExtent[1]);
        //if (data.FusionAlgorithm != oldData.FusionAlgorithm)
            emit FusionAlgorithmChanged(data.FusionAlgorithm);

}

/**
 * Create a clone of this object, a new instance ID must be specified.
 * Do not use this function directly to create new instances, the
 * UAVObjectManager should be used instead.
 */
UAVDataObject *RevoSettings::clone(quint32 instID)
{
    RevoSettings *obj = new RevoSettings();
    obj->initialize(instID, this->getMetaObject());
    return obj;
}

/**
 * Create a clone of this object only to be used to retrieve defaults
 */
UAVDataObject *RevoSettings::dirtyClone()
{
    RevoSettings *obj = new RevoSettings();
    return obj;
}

/**
 * Static function to retrieve an instance of the object.
 */
RevoSettings *RevoSettings::GetInstance(UAVObjectManager *objMngr, quint32 instID)
{
    return dynamic_cast<RevoSettings *>(objMngr->getObject(RevoSettings::OBJID, instID));
}

float RevoSettings::getBaroGPSOffsetCorrectionAlpha() const
{
   QMutexLocker locker(mutex);
   return data.BaroGPSOffsetCorrectionAlpha;
}
void RevoSettings::setBaroGPSOffsetCorrectionAlpha(float value)
{
   mutex->lock();
   bool changed = data.BaroGPSOffsetCorrectionAlpha != value;
   data.BaroGPSOffsetCorrectionAlpha = value;
   mutex->unlock();
   if (changed) emit BaroGPSOffsetCorrectionAlphaChanged(value);
}

float RevoSettings::getMagnetometerMaxDeviation(quint32 index) const
{
   QMutexLocker locker(mutex);
   return data.MagnetometerMaxDeviation[index];
}
void RevoSettings::setMagnetometerMaxDeviation(quint32 index, float value)
{
   mutex->lock();
   bool changed = data.MagnetometerMaxDeviation[index] != value;
   data.MagnetometerMaxDeviation[index] = value;
   mutex->unlock();
   if (changed) emit MagnetometerMaxDeviationChanged(index,value);
}

float RevoSettings::getMagnetometerMaxDeviation_Warning() const
{
   QMutexLocker locker(mutex);
   return data.MagnetometerMaxDeviation[0];
}
void RevoSettings::setMagnetometerMaxDeviation_Warning(float value)
{
   mutex->lock();
   bool changed = data.MagnetometerMaxDeviation[0] != value;
   data.MagnetometerMaxDeviation[0] = value;
   mutex->unlock();
   if (changed) emit MagnetometerMaxDeviation_WarningChanged(value);
}

float RevoSettings::getMagnetometerMaxDeviation_Error() const
{
   QMutexLocker locker(mutex);
   return data.MagnetometerMaxDeviation[1];
}
void RevoSettings::setMagnetometerMaxDeviation_Error(float value)
{
   mutex->lock();
   bool changed = data.MagnetometerMaxDeviation[1] != value;
   data.MagnetometerMaxDeviation[1] = value;
   mutex->unlock();
   if (changed) emit MagnetometerMaxDeviation_ErrorChanged(value);
}

float RevoSettings::getBaroTempCorrectionPolynomial(quint32 index) const
{
   QMutexLocker locker(mutex);
   return data.BaroTempCorrectionPolynomial[index];
}
void RevoSettings::setBaroTempCorrectionPolynomial(quint32 index, float value)
{
   mutex->lock();
   bool changed = data.BaroTempCorrectionPolynomial[index] != value;
   data.BaroTempCorrectionPolynomial[index] = value;
   mutex->unlock();
   if (changed) emit BaroTempCorrectionPolynomialChanged(index,value);
}

float RevoSettings::getBaroTempCorrectionPolynomial_a() const
{
   QMutexLocker locker(mutex);
   return data.BaroTempCorrectionPolynomial[0];
}
void RevoSettings::setBaroTempCorrectionPolynomial_a(float value)
{
   mutex->lock();
   bool changed = data.BaroTempCorrectionPolynomial[0] != value;
   data.BaroTempCorrectionPolynomial[0] = value;
   mutex->unlock();
   if (changed) emit BaroTempCorrectionPolynomial_aChanged(value);
}

float RevoSettings::getBaroTempCorrectionPolynomial_b() const
{
   QMutexLocker locker(mutex);
   return data.BaroTempCorrectionPolynomial[1];
}
void RevoSettings::setBaroTempCorrectionPolynomial_b(float value)
{
   mutex->lock();
   bool changed = data.BaroTempCorrectionPolynomial[1] != value;
   data.BaroTempCorrectionPolynomial[1] = value;
   mutex->unlock();
   if (changed) emit BaroTempCorrectionPolynomial_bChanged(value);
}

float RevoSettings::getBaroTempCorrectionPolynomial_c() const
{
   QMutexLocker locker(mutex);
   return data.BaroTempCorrectionPolynomial[2];
}
void RevoSettings::setBaroTempCorrectionPolynomial_c(float value)
{
   mutex->lock();
   bool changed = data.BaroTempCorrectionPolynomial[2] != value;
   data.BaroTempCorrectionPolynomial[2] = value;
   mutex->unlock();
   if (changed) emit BaroTempCorrectionPolynomial_cChanged(value);
}

float RevoSettings::getBaroTempCorrectionPolynomial_d() const
{
   QMutexLocker locker(mutex);
   return data.BaroTempCorrectionPolynomial[3];
}
void RevoSettings::setBaroTempCorrectionPolynomial_d(float value)
{
   mutex->lock();
   bool changed = data.BaroTempCorrectionPolynomial[3] != value;
   data.BaroTempCorrectionPolynomial[3] = value;
   mutex->unlock();
   if (changed) emit BaroTempCorrectionPolynomial_dChanged(value);
}

float RevoSettings::getBaroTempCorrectionExtent(quint32 index) const
{
   QMutexLocker locker(mutex);
   return data.BaroTempCorrectionExtent[index];
}
void RevoSettings::setBaroTempCorrectionExtent(quint32 index, float value)
{
   mutex->lock();
   bool changed = data.BaroTempCorrectionExtent[index] != value;
   data.BaroTempCorrectionExtent[index] = value;
   mutex->unlock();
   if (changed) emit BaroTempCorrectionExtentChanged(index,value);
}

float RevoSettings::getBaroTempCorrectionExtent_min() const
{
   QMutexLocker locker(mutex);
   return data.BaroTempCorrectionExtent[0];
}
void RevoSettings::setBaroTempCorrectionExtent_min(float value)
{
   mutex->lock();
   bool changed = data.BaroTempCorrectionExtent[0] != value;
   data.BaroTempCorrectionExtent[0] = value;
   mutex->unlock();
   if (changed) emit BaroTempCorrectionExtent_minChanged(value);
}

float RevoSettings::getBaroTempCorrectionExtent_max() const
{
   QMutexLocker locker(mutex);
   return data.BaroTempCorrectionExtent[1];
}
void RevoSettings::setBaroTempCorrectionExtent_max(float value)
{
   mutex->lock();
   bool changed = data.BaroTempCorrectionExtent[1] != value;
   data.BaroTempCorrectionExtent[1] = value;
   mutex->unlock();
   if (changed) emit BaroTempCorrectionExtent_maxChanged(value);
}

quint8 RevoSettings::getFusionAlgorithm() const
{
   QMutexLocker locker(mutex);
   return data.FusionAlgorithm;
}
void RevoSettings::setFusionAlgorithm(quint8 value)
{
   mutex->lock();
   bool changed = data.FusionAlgorithm != value;
   data.FusionAlgorithm = value;
   mutex->unlock();
   if (changed) emit FusionAlgorithmChanged(value);
}


