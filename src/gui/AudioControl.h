/****************************************************************************
* VLC-Qt - Qt and libvlc connector library
* Copyright (C) 2010 Tadej Novak <tadej@tano.si>
*
* This program is free software: you can redistribute it and/or modify
* it under the terms of the GNU General Public License as published by
* the Free Software Foundation, either version 3 of the License, or
* (at your option) any later version.
*
* This program is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
* GNU General Public License for more details.
*
* You should have received a copy of the GNU General Public License
* along with this program. If not, see <http://www.gnu.org/licenses/>.
*****************************************************************************/

#ifndef VLCQT_AUDIOCONTROL_H_
#define VLCQT_AUDIOCONTROL_H_

#include <QtCore/QList>
#include <QtCore/QMap>
#include <QtCore/QTimer>
#include <QtGui/QAction>

#include "Enums.h"

/*!
	\class VlcAudioControl AudioControl.h vlc-qt/AudioControl.h
	\brief Audio control class

	This is one of VLC-Qt control classes.
	It provides audio tracks management.
*/
class VlcAudioControl : public QObject
{
Q_OBJECT
public:
	/*!
		\brief VlcAudioControl constructor
		\param parent audio controller's parent object (QObject)
	*/
	VlcAudioControl(QObject *parent = 0);

	/*!
		AudioControl destructor
	*/
	~VlcAudioControl();


	/*!
		\brief Reset all settings and selected audio tracks.

		Usually called on media change.
	*/
	void reset();


signals:
	/*!
		\brief Signal sending actions for changing audio tracks

		\param Vlc::ActionsType type of actions
		\param QList<QAction*> list of actions
	*/
	void actions(const Vlc::ActionsType,
				 const QList<QAction *>);


private slots:
	void clean();
	void update();
	void updateActions();

private:
	QTimer *_timer;

	QList<QAction *> _actionList;
	QMap<QString, int> _map;
};

#endif // VLCQT_AUDIOCONTROL_H_
