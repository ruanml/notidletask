/*
 *  notidletask - implementation of idle detection under Windows
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

//#define WINDOWS_BUILD

#ifdef WINDOWS_BUILD

#ifndef WINDOWSSYSTEMIDLE_H
#define WINDOWSSYSTEMIDLE_H

#include "isystemidle.h"

class WindowsSystemIdle : public ISystemIdle
{
public:
    WindowsSystemIdle(Configuration * pConfiguration);

public:
    virtual void Start(void);
    virtual void Stop(void);
    virtual bool CheckIdle(void);
};

#endif // WINDOWSSYSTEMIDLE_H

#endif // WINDOWS_BUILD
