/*
 *  notidletask - implementation of idle detection under Linux
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

#include "linuxsystemidle.h"

#include <X11/Xlib.h>
#include <X11/Xutil.h>
#include <X11/extensions/scrnsaver.h>

/**   C'tor of the object

    * @return initialized object
*/
LinuxSystemIdle::LinuxSystemIdle(Configuration * pConfiguration) : ISystemIdle::ISystemIdle(pConfiguration)
{

}

/**   Start routine: not implemented for the moment

    * @return void
*/
void LinuxSystemIdle::Start(void)
{

}

/**   Stop routine: not implemented for the moment

    * @return void
*/
void LinuxSystemIdle::Stop(void)
{

}

/**   Platform specific routine for checking the idle state

    * @return bool
*/
bool LinuxSystemIdle::CheckIdle(void)
{
    TimeSnapshot retVal  = 0;
    int          nScreen = 0;

    XScreenSaverInfo    * pIdleInfo  = NULL;
    Display             * pDisplay   = NULL;

    pIdleInfo = XScreenSaverAllocInfo();

    if ((pDisplay = XOpenDisplay(NULL)) == NULL)
    {
        XFree(pIdleInfo);

        return retVal;
    }

    nScreen = DefaultScreen(pDisplay);

    XScreenSaverQueryInfo(pDisplay, RootWindow(pDisplay, nScreen), pIdleInfo);

    retVal = (pIdleInfo->idle) / 1000;

    XFree(pIdleInfo);
    XCloseDisplay(pDisplay);
    
    int nInterval = 0;
    
    m_pConfiguration->getInterval(nInterval);

    return (retVal >= nInterval);
}
