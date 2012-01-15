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

#include "configuration.h"

/**   C'tor of the configuration object

    * @return initialized object
*/
Configuration::Configuration() : m_nInterval(CONFIGURATION_DEFAULT_VAL_INTERVAL), m_bKillWhenExiting(true), m_bParsedFile(false)
{
    if (Parse() == false)
    {
        m_szFilePath = CONFIGURATION_DEFAULT_VAL_PATH;
        m_nInterval  = CONFIGURATION_DEFAULT_VAL_INTERVAL;

        Flush();
    }
}

/**   Storing configuration as XML file on a disk

    * @return boolean
*/
bool Configuration::Flush()
{
    QDomDocument doc(CONFIGURATION_NAME_ROOT);
    QDomElement elementConfiguration = doc.createElement(CONFIGURATION_NAME_CONF);
    QDomElement notidletask = doc.createElement(CONFIGURATION_NAME_ROOT);
    QDomElement options = doc.createElement(CONFIGURATION_NAME_OPTIONS);

    QDomElement optionPath = doc.createElement(CONFIGURATION_NAME_OPTION);

    optionPath.setAttribute(CONFIGURATION_NAME_OPTION_NAME, CONFIGURATION_NAME_OPTION_NAME_P);
    optionPath.setAttribute(CONFIGURATION_NAME_OPTION_VALUE, m_szFilePath);

    QDomElement optioninterval = doc.createElement(CONFIGURATION_NAME_OPTION);

    optioninterval.setAttribute(CONFIGURATION_NAME_OPTION_NAME, CONFIGURATION_NAME_OPTION_NAME_I);
    optioninterval.setAttribute(CONFIGURATION_NAME_OPTION_VALUE, m_nInterval);

    QDomElement optionKill = doc.createElement(CONFIGURATION_NAME_OPTION);

    optionKill.setAttribute(CONFIGURATION_NAME_OPTION_NAME, CONFIGURATION_NAME_OPTION_NAME_K);
    optionKill.setAttribute(CONFIGURATION_NAME_OPTION_VALUE, m_bKillWhenExiting);

    options.appendChild(optionPath);
    options.appendChild(optioninterval);
    options.appendChild(optionKill);

    notidletask.appendChild(options);
    elementConfiguration.appendChild(notidletask);

    doc.appendChild(elementConfiguration);

    QFile File(CONFIGURATION_FILE_NAME);

    if (File.open(QIODevice::WriteOnly))
    {
        QTextStream TextStream(&File);
        TextStream << doc.toString();

        File.close();

        return true;
    }

    return false;
}

/**   Reading configuration as XML file from a disk to memory

    * @return boolean
*/
bool Configuration::Parse()
{
    QDomDocument doc(CONFIGURATION_NAME_ROOT);
    QFile file(CONFIGURATION_FILE_NAME);

    if (!file.open(QIODevice::ReadOnly))
    {
        return false;
    }

    if (!doc.setContent(&file))
    {
        return false;
    }

    file.close(); m_bParsedFile = false;

    QDomElement  docElem  = doc.documentElement();
    QDomNodeList nodeList = docElem.elementsByTagName(CONFIGURATION_NAME_ROOT).at(0).toElement().elementsByTagName(CONFIGURATION_NAME_OPTIONS).at(0).childNodes();

    int nCount = nodeList.count();

    for (int i = 0; i < nCount; i++)
    {
        QDomNode         nodeItem   = nodeList.at(i);
        QDomNamedNodeMap attributes = nodeItem.attributes();

        if (attributes.contains(CONFIGURATION_NAME_OPTION_NAME) && attributes.contains(CONFIGURATION_NAME_OPTION_VALUE))
        {
            QDomNode AttributeName  = attributes.namedItem(CONFIGURATION_NAME_OPTION_NAME);
            QDomNode AttributeValue = attributes.namedItem(CONFIGURATION_NAME_OPTION_VALUE);

            QString  szName  = AttributeName.nodeValue();
            QString  szValue = AttributeValue.nodeValue();

            if (szName == CONFIGURATION_NAME_OPTION_NAME_P)
            {
                m_szFilePath = szValue;
            }
            else if (szName == CONFIGURATION_NAME_OPTION_NAME_I)
            {
                m_nInterval = szValue.toInt(&m_bParsedFile, 0x0A);
            }
            else if (szName == CONFIGURATION_NAME_OPTION_NAME_K)
            {
                m_bKillWhenExiting = szValue.toInt(&m_bParsedFile, 0x0A);
            }
        }
    }

    return m_bParsedFile;
}

/**   Indicating if configuration was parsed properly

    * @return boolean
*/
bool Configuration::Parsed()
{
    return m_bParsedFile;
}

/**   Getting path of a file to execute

    * @return boolean
*/
bool Configuration::getFilePath(QString & szFilePath)
{
    szFilePath = m_szFilePath;

    return m_bParsedFile;
}

/**   Getting interval after which to terminate the running program

    * @return boolean
*/
bool Configuration::getInterval(int & nInterval)
{
    nInterval = m_nInterval;

    return m_bParsedFile;
}

/**   Setting interval after which to terminate the running program

    * @return boolean
*/
bool Configuration::setInterval(int nInterval)
{
    m_nInterval = nInterval;

    return true;
}

/**   Setting path of file to execute

    * @return boolean
*/
bool Configuration::setFilePath(QString & szFilePath)
{
    m_szFilePath = szFilePath;

    return true;
}

/**   Getting value of option "kill if exiting"

    * @return boolean
*/
bool Configuration::getKillOpt(bool & bKillOpt)
{
    bKillOpt = m_bKillWhenExiting;

    return m_bParsedFile;
}

/**   Setting value for option "kill if exiting"

    * @return boolean
*/
bool Configuration::setKillOpt(bool bKillOpt)
{
    m_bKillWhenExiting = bKillOpt;

    return true;
}
