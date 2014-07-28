/**
 ******************************************************************************
 *
 * @file       pathstatus.h
 * @author     The OpenPilot Team, http://www.openpilot.org Copyright (C) 2010.
 * @see        The GNU Public License (GPL) Version 3
 * @addtogroup GCSPlugins GCS Plugins
 * @{
 * @addtogroup UAVObjectsPlugin UAVObjects Plugin
 * @{
 *   
 * @note       Object definition file: pathstatus.xml. 
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
#ifndef PATHSTATUS_H
#define PATHSTATUS_H

#include "uavdataobject.h"
#include "uavobjectmanager.h"

class UAVOBJECTS_EXPORT PathStatus: public UAVDataObject
{
    Q_OBJECT
    Q_PROPERTY(float fractional_progress READ getfractional_progress WRITE setfractional_progress NOTIFY fractional_progressChanged);
    Q_PROPERTY(float error READ geterror WRITE seterror NOTIFY errorChanged);
    Q_PROPERTY(qint16 UID READ getUID WRITE setUID NOTIFY UIDChanged);
    Q_PROPERTY(quint8 Status READ getStatus WRITE setStatus NOTIFY StatusChanged);


public:
    // Field structure
    typedef struct {
        float fractional_progress;
        float error;
        qint16 UID;
        quint8 Status;

    } __attribute__((packed)) DataFields;

    // Field information
    // Field fractional_progress information
    // Field error information
    // Field UID information
    // Field Status information
    /* Enumeration options for field Status */
    typedef enum { STATUS_INPROGRESS=0, STATUS_COMPLETED=1, STATUS_WARNING=2, STATUS_CRITICAL=3 } StatusOptions;

  
    // Constants
    static const quint32 OBJID = 0x198B9702;
    static const QString NAME;
    static const QString DESCRIPTION;
    static const QString CATEGORY;
    static const bool ISSINGLEINST = 1;
    static const bool ISSETTINGS = 0;
    static const quint32 NUMBYTES = sizeof(DataFields);

    // Functions
    PathStatus();

    DataFields getData();
    void setData(const DataFields& data);
    Metadata getDefaultMetadata();
    UAVDataObject* clone(quint32 instID);
	UAVDataObject* dirtyClone();
	
    static PathStatus* GetInstance(UAVObjectManager* objMngr, quint32 instID = 0);

    Q_INVOKABLE float getfractional_progress() const;
    Q_INVOKABLE float geterror() const;
    Q_INVOKABLE qint16 getUID() const;
    Q_INVOKABLE quint8 getStatus() const;


public slots:
    void setfractional_progress(float value);
    void seterror(float value);
    void setUID(qint16 value);
    void setStatus(quint8 value);


signals:
    void fractional_progressChanged(float value);
    void errorChanged(float value);
    void UIDChanged(qint16 value);
    void StatusChanged(quint8 value);


private slots:
    void emitNotifications();
	
private:
    DataFields data;

    void setDefaultFieldValues();

};

#endif // PATHSTATUS_H
