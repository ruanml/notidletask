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

//#ifdef WINDOWS_BUILD

#include "windowssystemidle.h"

#include <windows.h>

WindowsSystemIdle::WindowsSystemIdle(Configuration * pConfiguration) : ISystemIdle::ISystemIdle(pConfiguration)
{
}

void WindowsSystemIdle::Start(void)
{

}

void WindowsSystemIdle::Stop(void)
{

}

bool WindowsSystemIdle::CheckIdle(void)
{
    LASTINPUTINFO inputInfo  = {0};
    DWORD         dwTicksNow = 0;

    inputInfo.cbSize = sizeof(inputInfo);

    if (GetLastInputInfo(&inputInfo) == FALSE)
    {
        return false;
    }

    dwTicksNow = GetTickCount();

    inputInfo.dwTime /= 1000;
    dwTicksNow /= 1000;

    dwTicksNow -= inputInfo.dwTime;

    int nInterval = 0;

    m_pConfiguration->getInterval(nInterval);

    return (dwTicksNow >= nInterval);
}

//#endif // WINDOWS_BUILD
