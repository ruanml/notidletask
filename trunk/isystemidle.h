/*
 *  notidletask - abstract class implementation which defines idle detection policy
 *
 *  Copyright (C) 2012 by Volodymyr M. Shcherbyna <volodymyr@shcherbyna.com>
 *
 *      This file is part of notidletask.
 *
 *  notidletask is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  notidletask is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with notidletask.  If not, see <http://www.gnu.org/licenses/>.
*/

#include "crosscompiling.h"

#ifndef ISYSTEMIDLE_H
#define ISYSTEMIDLE_H

#include <qobject.h>

#include "configuration.h"

typedef unsigned long TimeSnapshot;

class ISystemIdle : public QObject
{
    Q_OBJECT
public:
    ISystemIdle(Configuration * pConfiguration);
protected:
    virtual void Start(void) = 0;
    virtual void Stop(void)  = 0;
public:
    virtual bool CheckIdle(void) = 0;
protected:
    Configuration * m_pConfiguration;
};

#endif // ISYSTEMIDLE_H
