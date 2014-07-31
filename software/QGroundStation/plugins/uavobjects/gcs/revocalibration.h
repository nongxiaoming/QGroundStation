/**
 ******************************************************************************
 *
 * @file       revocalibration.h
 * @author     The OpenPilot Team, http://www.openpilot.org Copyright (C) 2010.
 * @see        The GNU Public License (GPL) Version 3
 * @addtogroup GCSPlugins GCS Plugins
 * @{
 * @addtogroup UAVObjectsPlugin UAVObjects Plugin
 * @{
 *   
 * @note       Object definition file: revocalibration.xml. 
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
#ifndef REVOCALIBRATION_H
#define REVOCALIBRATION_H

#include "uavobjects/uavdataobject.h"
#include "uavobjects/uavobjectmanager.h"

class UAVOBJECTS_EXPORT RevoCalibration: public UAVDataObject
{
    Q_OBJECT
    Q_PROPERTY(float mag_bias_X READ getmag_bias_X WRITE setmag_bias_X NOTIFY mag_bias_XChanged);
    Q_PROPERTY(float mag_bias_Y READ getmag_bias_Y WRITE setmag_bias_Y NOTIFY mag_bias_YChanged);
    Q_PROPERTY(float mag_bias_Z READ getmag_bias_Z WRITE setmag_bias_Z NOTIFY mag_bias_ZChanged);
    Q_PROPERTY(float mag_transform_r0c0 READ getmag_transform_r0c0 WRITE setmag_transform_r0c0 NOTIFY mag_transform_r0c0Changed);
    Q_PROPERTY(float mag_transform_r0c1 READ getmag_transform_r0c1 WRITE setmag_transform_r0c1 NOTIFY mag_transform_r0c1Changed);
    Q_PROPERTY(float mag_transform_r0c2 READ getmag_transform_r0c2 WRITE setmag_transform_r0c2 NOTIFY mag_transform_r0c2Changed);
    Q_PROPERTY(float mag_transform_r1c0 READ getmag_transform_r1c0 WRITE setmag_transform_r1c0 NOTIFY mag_transform_r1c0Changed);
    Q_PROPERTY(float mag_transform_r1c1 READ getmag_transform_r1c1 WRITE setmag_transform_r1c1 NOTIFY mag_transform_r1c1Changed);
    Q_PROPERTY(float mag_transform_r1c2 READ getmag_transform_r1c2 WRITE setmag_transform_r1c2 NOTIFY mag_transform_r1c2Changed);
    Q_PROPERTY(float mag_transform_r2c0 READ getmag_transform_r2c0 WRITE setmag_transform_r2c0 NOTIFY mag_transform_r2c0Changed);
    Q_PROPERTY(float mag_transform_r2c1 READ getmag_transform_r2c1 WRITE setmag_transform_r2c1 NOTIFY mag_transform_r2c1Changed);
    Q_PROPERTY(float mag_transform_r2c2 READ getmag_transform_r2c2 WRITE setmag_transform_r2c2 NOTIFY mag_transform_r2c2Changed);
    Q_PROPERTY(float MagBiasNullingRate READ getMagBiasNullingRate WRITE setMagBiasNullingRate NOTIFY MagBiasNullingRateChanged);
    Q_PROPERTY(quint8 BiasCorrectedRaw READ getBiasCorrectedRaw WRITE setBiasCorrectedRaw NOTIFY BiasCorrectedRawChanged);


public:
    // Field structure
    typedef struct {
        float mag_bias[3];
        float mag_transform[9];
        float MagBiasNullingRate;
        quint8 BiasCorrectedRaw;

    } __attribute__((packed)) DataFields;

    // Field information
    // Field mag_bias information
    /* Array element names for field mag_bias */
    typedef enum { MAG_BIAS_X=0, MAG_BIAS_Y=1, MAG_BIAS_Z=2 } mag_biasElem;
    /* Number of elements for field mag_bias */
    static const quint32 MAG_BIAS_NUMELEM = 3;
    // Field mag_transform information
    /* Array element names for field mag_transform */
    typedef enum { MAG_TRANSFORM_R0C0=0, MAG_TRANSFORM_R0C1=1, MAG_TRANSFORM_R0C2=2, MAG_TRANSFORM_R1C0=3, MAG_TRANSFORM_R1C1=4, MAG_TRANSFORM_R1C2=5, MAG_TRANSFORM_R2C0=6, MAG_TRANSFORM_R2C1=7, MAG_TRANSFORM_R2C2=8 } mag_transformElem;
    /* Number of elements for field mag_transform */
    static const quint32 MAG_TRANSFORM_NUMELEM = 9;
    // Field MagBiasNullingRate information
    // Field BiasCorrectedRaw information
    /* Enumeration options for field BiasCorrectedRaw */
    typedef enum { BIASCORRECTEDRAW_FALSE=0, BIASCORRECTEDRAW_TRUE=1 } BiasCorrectedRawOptions;

  
    // Constants
    static const quint32 OBJID = 0xA3633042;
    static const QString NAME;
    static const QString DESCRIPTION;
    static const QString CATEGORY;
    static const bool ISSINGLEINST = 1;
    static const bool ISSETTINGS = 1;
    static const quint32 NUMBYTES = sizeof(DataFields);

    // Functions
    RevoCalibration();

    DataFields getData();
    void setData(const DataFields& data);
    Metadata getDefaultMetadata();
    UAVDataObject* clone(quint32 instID);
	UAVDataObject* dirtyClone();
	
    static RevoCalibration* GetInstance(UAVObjectManager* objMngr, quint32 instID = 0);

    Q_INVOKABLE float getmag_bias(quint32 index) const;
    Q_INVOKABLE float getmag_bias_X() const;
    Q_INVOKABLE float getmag_bias_Y() const;
    Q_INVOKABLE float getmag_bias_Z() const;
    Q_INVOKABLE float getmag_transform(quint32 index) const;
    Q_INVOKABLE float getmag_transform_r0c0() const;
    Q_INVOKABLE float getmag_transform_r0c1() const;
    Q_INVOKABLE float getmag_transform_r0c2() const;
    Q_INVOKABLE float getmag_transform_r1c0() const;
    Q_INVOKABLE float getmag_transform_r1c1() const;
    Q_INVOKABLE float getmag_transform_r1c2() const;
    Q_INVOKABLE float getmag_transform_r2c0() const;
    Q_INVOKABLE float getmag_transform_r2c1() const;
    Q_INVOKABLE float getmag_transform_r2c2() const;
    Q_INVOKABLE float getMagBiasNullingRate() const;
    Q_INVOKABLE quint8 getBiasCorrectedRaw() const;


public slots:
    void setmag_bias(quint32 index, float value);
    void setmag_bias_X(float value);
    void setmag_bias_Y(float value);
    void setmag_bias_Z(float value);
    void setmag_transform(quint32 index, float value);
    void setmag_transform_r0c0(float value);
    void setmag_transform_r0c1(float value);
    void setmag_transform_r0c2(float value);
    void setmag_transform_r1c0(float value);
    void setmag_transform_r1c1(float value);
    void setmag_transform_r1c2(float value);
    void setmag_transform_r2c0(float value);
    void setmag_transform_r2c1(float value);
    void setmag_transform_r2c2(float value);
    void setMagBiasNullingRate(float value);
    void setBiasCorrectedRaw(quint8 value);


signals:
    void mag_biasChanged(quint32 index, float value);
    void mag_bias_XChanged(float value);
    void mag_bias_YChanged(float value);
    void mag_bias_ZChanged(float value);
    void mag_transformChanged(quint32 index, float value);
    void mag_transform_r0c0Changed(float value);
    void mag_transform_r0c1Changed(float value);
    void mag_transform_r0c2Changed(float value);
    void mag_transform_r1c0Changed(float value);
    void mag_transform_r1c1Changed(float value);
    void mag_transform_r1c2Changed(float value);
    void mag_transform_r2c0Changed(float value);
    void mag_transform_r2c1Changed(float value);
    void mag_transform_r2c2Changed(float value);
    void MagBiasNullingRateChanged(float value);
    void BiasCorrectedRawChanged(quint8 value);


private slots:
    void emitNotifications();
	
private:
    DataFields data;

    void setDefaultFieldValues();

};

#endif // REVOCALIBRATION_H
