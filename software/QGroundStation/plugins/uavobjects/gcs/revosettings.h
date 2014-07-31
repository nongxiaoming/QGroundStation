/**
 ******************************************************************************
 *
 * @file       revosettings.h
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
#ifndef REVOSETTINGS_H
#define REVOSETTINGS_H

#include "uavobjects/uavdataobject.h"
#include "uavobjects/uavobjectmanager.h"

class UAVOBJECTS_EXPORT RevoSettings: public UAVDataObject
{
    Q_OBJECT
    Q_PROPERTY(float BaroGPSOffsetCorrectionAlpha READ getBaroGPSOffsetCorrectionAlpha WRITE setBaroGPSOffsetCorrectionAlpha NOTIFY BaroGPSOffsetCorrectionAlphaChanged);
    Q_PROPERTY(float MagnetometerMaxDeviation_Warning READ getMagnetometerMaxDeviation_Warning WRITE setMagnetometerMaxDeviation_Warning NOTIFY MagnetometerMaxDeviation_WarningChanged);
    Q_PROPERTY(float MagnetometerMaxDeviation_Error READ getMagnetometerMaxDeviation_Error WRITE setMagnetometerMaxDeviation_Error NOTIFY MagnetometerMaxDeviation_ErrorChanged);
    Q_PROPERTY(float BaroTempCorrectionPolynomial_a READ getBaroTempCorrectionPolynomial_a WRITE setBaroTempCorrectionPolynomial_a NOTIFY BaroTempCorrectionPolynomial_aChanged);
    Q_PROPERTY(float BaroTempCorrectionPolynomial_b READ getBaroTempCorrectionPolynomial_b WRITE setBaroTempCorrectionPolynomial_b NOTIFY BaroTempCorrectionPolynomial_bChanged);
    Q_PROPERTY(float BaroTempCorrectionPolynomial_c READ getBaroTempCorrectionPolynomial_c WRITE setBaroTempCorrectionPolynomial_c NOTIFY BaroTempCorrectionPolynomial_cChanged);
    Q_PROPERTY(float BaroTempCorrectionPolynomial_d READ getBaroTempCorrectionPolynomial_d WRITE setBaroTempCorrectionPolynomial_d NOTIFY BaroTempCorrectionPolynomial_dChanged);
    Q_PROPERTY(float BaroTempCorrectionExtent_min READ getBaroTempCorrectionExtent_min WRITE setBaroTempCorrectionExtent_min NOTIFY BaroTempCorrectionExtent_minChanged);
    Q_PROPERTY(float BaroTempCorrectionExtent_max READ getBaroTempCorrectionExtent_max WRITE setBaroTempCorrectionExtent_max NOTIFY BaroTempCorrectionExtent_maxChanged);
    Q_PROPERTY(quint8 FusionAlgorithm READ getFusionAlgorithm WRITE setFusionAlgorithm NOTIFY FusionAlgorithmChanged);


public:
    // Field structure
    typedef struct {
        float BaroGPSOffsetCorrectionAlpha;
        float MagnetometerMaxDeviation[2];
        float BaroTempCorrectionPolynomial[4];
        float BaroTempCorrectionExtent[2];
        quint8 FusionAlgorithm;

    } __attribute__((packed)) DataFields;

    // Field information
    // Field BaroGPSOffsetCorrectionAlpha information
    // Field MagnetometerMaxDeviation information
    /* Array element names for field MagnetometerMaxDeviation */
    typedef enum { MAGNETOMETERMAXDEVIATION_WARNING=0, MAGNETOMETERMAXDEVIATION_ERROR=1 } MagnetometerMaxDeviationElem;
    /* Number of elements for field MagnetometerMaxDeviation */
    static const quint32 MAGNETOMETERMAXDEVIATION_NUMELEM = 2;
    // Field BaroTempCorrectionPolynomial information
    /* Array element names for field BaroTempCorrectionPolynomial */
    typedef enum { BAROTEMPCORRECTIONPOLYNOMIAL_A=0, BAROTEMPCORRECTIONPOLYNOMIAL_B=1, BAROTEMPCORRECTIONPOLYNOMIAL_C=2, BAROTEMPCORRECTIONPOLYNOMIAL_D=3 } BaroTempCorrectionPolynomialElem;
    /* Number of elements for field BaroTempCorrectionPolynomial */
    static const quint32 BAROTEMPCORRECTIONPOLYNOMIAL_NUMELEM = 4;
    // Field BaroTempCorrectionExtent information
    /* Array element names for field BaroTempCorrectionExtent */
    typedef enum { BAROTEMPCORRECTIONEXTENT_MIN=0, BAROTEMPCORRECTIONEXTENT_MAX=1 } BaroTempCorrectionExtentElem;
    /* Number of elements for field BaroTempCorrectionExtent */
    static const quint32 BAROTEMPCORRECTIONEXTENT_NUMELEM = 2;
    // Field FusionAlgorithm information
    /* Enumeration options for field FusionAlgorithm */
    typedef enum { FUSIONALGORITHM_NONE=0, FUSIONALGORITHM_COMPLEMENTARY=1, FUSIONALGORITHM_COMPLEMENTARYMAG=2, FUSIONALGORITHM_COMPLEMENTARYMAGGPSOUTDOOR=3, FUSIONALGORITHM_INS13INDOOR=4, FUSIONALGORITHM_INS13GPSOUTDOOR=5 } FusionAlgorithmOptions;

  
    // Constants
    static const quint32 OBJID = 0xC8F9D718;
    static const QString NAME;
    static const QString DESCRIPTION;
    static const QString CATEGORY;
    static const bool ISSINGLEINST = 1;
    static const bool ISSETTINGS = 1;
    static const quint32 NUMBYTES = sizeof(DataFields);

    // Functions
    RevoSettings();

    DataFields getData();
    void setData(const DataFields& data);
    Metadata getDefaultMetadata();
    UAVDataObject* clone(quint32 instID);
	UAVDataObject* dirtyClone();
	
    static RevoSettings* GetInstance(UAVObjectManager* objMngr, quint32 instID = 0);

    Q_INVOKABLE float getBaroGPSOffsetCorrectionAlpha() const;
    Q_INVOKABLE float getMagnetometerMaxDeviation(quint32 index) const;
    Q_INVOKABLE float getMagnetometerMaxDeviation_Warning() const;
    Q_INVOKABLE float getMagnetometerMaxDeviation_Error() const;
    Q_INVOKABLE float getBaroTempCorrectionPolynomial(quint32 index) const;
    Q_INVOKABLE float getBaroTempCorrectionPolynomial_a() const;
    Q_INVOKABLE float getBaroTempCorrectionPolynomial_b() const;
    Q_INVOKABLE float getBaroTempCorrectionPolynomial_c() const;
    Q_INVOKABLE float getBaroTempCorrectionPolynomial_d() const;
    Q_INVOKABLE float getBaroTempCorrectionExtent(quint32 index) const;
    Q_INVOKABLE float getBaroTempCorrectionExtent_min() const;
    Q_INVOKABLE float getBaroTempCorrectionExtent_max() const;
    Q_INVOKABLE quint8 getFusionAlgorithm() const;


public slots:
    void setBaroGPSOffsetCorrectionAlpha(float value);
    void setMagnetometerMaxDeviation(quint32 index, float value);
    void setMagnetometerMaxDeviation_Warning(float value);
    void setMagnetometerMaxDeviation_Error(float value);
    void setBaroTempCorrectionPolynomial(quint32 index, float value);
    void setBaroTempCorrectionPolynomial_a(float value);
    void setBaroTempCorrectionPolynomial_b(float value);
    void setBaroTempCorrectionPolynomial_c(float value);
    void setBaroTempCorrectionPolynomial_d(float value);
    void setBaroTempCorrectionExtent(quint32 index, float value);
    void setBaroTempCorrectionExtent_min(float value);
    void setBaroTempCorrectionExtent_max(float value);
    void setFusionAlgorithm(quint8 value);


signals:
    void BaroGPSOffsetCorrectionAlphaChanged(float value);
    void MagnetometerMaxDeviationChanged(quint32 index, float value);
    void MagnetometerMaxDeviation_WarningChanged(float value);
    void MagnetometerMaxDeviation_ErrorChanged(float value);
    void BaroTempCorrectionPolynomialChanged(quint32 index, float value);
    void BaroTempCorrectionPolynomial_aChanged(float value);
    void BaroTempCorrectionPolynomial_bChanged(float value);
    void BaroTempCorrectionPolynomial_cChanged(float value);
    void BaroTempCorrectionPolynomial_dChanged(float value);
    void BaroTempCorrectionExtentChanged(quint32 index, float value);
    void BaroTempCorrectionExtent_minChanged(float value);
    void BaroTempCorrectionExtent_maxChanged(float value);
    void FusionAlgorithmChanged(quint8 value);


private slots:
    void emitNotifications();
	
private:
    DataFields data;

    void setDefaultFieldValues();

};

#endif // REVOSETTINGS_H
