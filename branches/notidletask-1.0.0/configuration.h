/*
 *  notidletask - implementation of configuration of an application
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

#ifndef CONFIGURATION_H
#define CONFIGURATION_H

#include <QtXml/QDomDocument>
#include <QFile>
#include <QtDebug>

//
#define CONFIGURATION_NAME_ROOT             "notidletask"

//
#define CONFIGURATION_FILE_NAME             "notidletask.xml"

//
#define CONFIGURATION_NAME_CONF             "Configuration"

//
#define CONFIGURATION_NAME_OPTIONS          "Options"

//
#define CONFIGURATION_NAME_OPTION           "Option"

//
#define CONFIGURATION_NAME_OPTION_VALUE     "value"

//
#define CONFIGURATION_NAME_OPTION_NAME      "name"

//
#define CONFIGURATION_NAME_OPTION_NAME_P    "Path"

//
#define CONFIGURATION_NAME_OPTION_NAME_I    "Interval"

//
#define CONFIGURATION_NAME_OPTION_NAME_K    "Kill"

///
#define CONFIGURATION_DEFAULT_VAL_INTERVAL  120

///
#define CONFIGURATION_DEFAULT_VAL_PATH      "/home/"

class Configuration
{
public:
    Configuration();

public:
    bool Parse();
    bool Flush();
    bool Parsed();

public:
    bool getFilePath(QString & szFilePath);
    bool getInterval(int & nInterval);
    bool getKillOpt(bool & bKillOpt);

public:
    bool setInterval(int nInterval);
    bool setFilePath(QString & szFilePath);
    bool setKillOpt(bool bKillOpt);

private:
    int     m_nInterval;
    bool    m_bKillWhenExiting,
            m_bParsedFile;
    QString m_szFilePath;
};

#endif // CONFIGURATION_H
