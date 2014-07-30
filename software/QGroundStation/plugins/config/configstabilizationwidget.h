/**
 ******************************************************************************
 *
 * @file       configstabilizationwidget.h
 * @author     The OpenPilot Team, http://www.openpilot.org Copyright (C) 2010.
 * @addtogroup GCSPlugins GCS Plugins
 * @{
 * @addtogroup ConfigPlugin Config Plugin
 * @{
 * @brief Stabilization configuration panel
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
#ifndef CONFIGSTABILIZATIONWIDGET_H
#define CONFIGSTABILIZATIONWIDGET_H

#include "ui_stabilization.h"
#include "uavobjectwidgetutils/configtaskwidget.h"
#include "extensionsystem/pluginmanager.h"
#include "uavobjects/uavobjectmanager.h"
#include "uavobjects/uavobject.h"
#include "uavobjects/gcs/stabilizationsettings.h"
#include <QWidget>
#include <QTimer>


class ConfigStabilizationWidget : public ConfigTaskWidget {
    Q_OBJECT

public:
    ConfigStabilizationWidget(QWidget *parent = 0);
    ~ConfigStabilizationWidget();
    bool shouldObjectBeSaved(UAVObject *object);

private:
    Ui_StabilizationWidget *ui;
    QTimer *realtimeUpdates;
    QList<QTabBar *> m_pidTabBars;
    QString m_stabilizationObjectsString;

    // Milliseconds between automatic 'Instant Updates'
    static const int AUTOMATIC_UPDATE_RATE = 500;

    int boardModel;
    int m_pidBankCount;
    int m_currentPIDBank;
protected:
    QString mapObjectName(const QString objectName);

protected slots:
    void refreshWidgetsValues(UAVObject *o = NULL);

private slots:
    void realtimeUpdatesSlot(bool value);
    void linkCheckBoxes(bool value);
    void processLinkedWidgets(QWidget *);
    void onBoardConnected();
    void pidBankChanged(int index);
};

#endif // ConfigStabilizationWidget_H
