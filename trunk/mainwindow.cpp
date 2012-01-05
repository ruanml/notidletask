/*
 *  notidletask - implementation of a main window of application
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

#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "isystemidle.h"
#include "linuxsystemidle.h"

/**   C'tor of main window. It builds the UI layout and shows up the main window

    * @return initialized object
*/
MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow), m_pIdleImplementation(NULL), m_bJustDisabled(false), m_bTrayMessageShown(false)
{
    QString szValue     = "";
    int     nInterval   = 0;
    bool    bChecked    = false;

    ui->setupUi(this);

    // set configuration options to the main window
    m_Configuration.getInterval(nInterval);
    szValue = QString::number(nInterval);
    ui->EDIT_INTERVAL->setText(szValue);

    m_Configuration.getKillOpt(bChecked);
    ui->CHECKBOX_KILL_APP_IF_EXIT->setCheckState(bChecked == true ? Qt::Checked : Qt::Unchecked);

    m_Configuration.getFilePath(szValue);
    ui->EDIT_PATH->setText(szValue);

    // create context menu for tray icon
    m_pRelaunchAction = new QAction(tr("Re&launch"), this);
    connect(m_pRelaunchAction, SIGNAL(triggered()), this, SLOT(RelaunchAction()));

    m_pPropertiesAction = new QAction(tr("Pro&perties"), this);
    connect(m_pPropertiesAction, SIGNAL(triggered()), this, SLOT(PropertiesAction()));

    m_pAboutAction = new QAction(tr("Ab&out"), this);
    connect(m_pAboutAction, SIGNAL(triggered()), this, SLOT(AboutAction()));

    m_pExitAction = new QAction(tr("Ex&it"), this);
    connect(m_pExitAction, SIGNAL(triggered()), this, SLOT(ExitAction()));

    // form actual context menu layout
    m_pTrayIconMenu = new QMenu(this);
    m_pTrayIconMenu->addAction(m_pRelaunchAction);
    m_pTrayIconMenu->addAction(m_pPropertiesAction);
    m_pTrayIconMenu->addAction(m_pAboutAction);
    m_pTrayIconMenu->addSeparator();
    m_pTrayIconMenu->addAction(m_pExitAction);

    // create tray icon and connect context menu to it
    m_pTrayIcon = new QSystemTrayIcon(this);
    m_pTrayIcon->setContextMenu(m_pTrayIconMenu);

    // create image for the tray icon
    m_pImageItems = new QComboBox();
    m_pImageItems->addItem(QIcon(":/new/app/appicon.ico"), tr("Main"));
    //m_pImageItems->addItem(QIcon("appicon.ico"), tr("Main"));

    QIcon icon = m_pImageItems->itemIcon(0);
    m_pTrayIcon->setIcon(icon);

    // finally, show it all:
    m_pTrayIcon->show();
    m_pTrayIcon->setToolTip("Application is not set");

    m_pIdleImplementation = new LinuxSystemIdle(&m_Configuration);

    m_pTimer = new QTimer(this);
    connect(m_pTimer, SIGNAL(timeout()), this, SLOT(TimerUpdate()));
    m_pTimer->start(3000);

    RelaunchAction();

    QWidget::setFixedSize(579, 172);
}

/**   D'tor of main window. Pretty much deystros everything

    * @return de-initialized object
*/
MainWindow::~MainWindow()
{
    bool bKill = false;

    m_Configuration.getKillOpt(bKill);

    if (bKill)
    {
        m_Process.kill();
    }

    delete ui;
}

/**   Qt event dispatch routine

    * @return void
*/
void MainWindow::changeEvent(QEvent *e)
{
    QMainWindow::changeEvent(e);

    switch (e->type())
    {
    case QEvent::LanguageChange:
        ui->retranslateUi(this);
        break;

    default:
        break;
    }
}

/**   Handler of "OK" button click event

    * @return void
*/
void MainWindow::on_BUTTON_OK_clicked()
{
    bool    bParsed = false;
    QString szVal   = ui->EDIT_PATH->toPlainText();

    m_Configuration.setFilePath(szVal);

    szVal = ui->EDIT_INTERVAL->toPlainText();
    m_Configuration.setInterval(szVal.toInt(&bParsed, 0x0A));
    m_Configuration.setKillOpt(ui->CHECKBOX_KILL_APP_IF_EXIT->checkState() == Qt::Checked ? true : false);

    m_Configuration.Flush();

    hide();

    if (m_bTrayMessageShown == false)
    {
        QSystemTrayIcon::MessageIcon icon;
        m_pTrayIcon->showMessage("NotIdleTask", "Application is running in tray since now", icon, 6000);

        m_bTrayMessageShown = true;
    }
}

/**   Handler of checkbox state change event

    * @return void
*/
void MainWindow::on_CHECKBOX_KILL_APP_IF_EXIT_stateChanged(int nCheckState)
{
    //m_Configuration.setKillOpt(nCheckState == 0 ? false : true);
    //m_Configuration.Flush();
}

/**   Handler of "Cancel" button click event

    * @return void
*/
void MainWindow::on_BUTTON_CANCEL_clicked()
{
    hide();

    if (m_bTrayMessageShown == false)
    {
        QSystemTrayIcon::MessageIcon icon;
        m_pTrayIcon->showMessage("NotIdleTask", "Application is running in tray since now", icon, 6000);

        m_bTrayMessageShown = true;
    }
}

/**   Handler of "Relaunch" menu item click event

    * @return void
*/
void MainWindow::RelaunchAction()
{
    m_bJustDisabled = false;

    if (m_Configuration.Parsed())
    {
        QString szValue;

        m_Configuration.getFilePath(szValue);

        qDebug() << szValue;

        QStringList procParams;
        QString     szPattern("\"");
        QStringList szSplit = szValue.split(szPattern);

        if (szSplit.count())
        {
            szValue = "";

            for (QStringList::iterator it = szSplit.begin(); it != szSplit.end(); it++)
            {
                if (it->size())
                {
                    while(it->endsWith(' ')) it->chop(1);

                    qDebug()   << *it;
                    procParams << *it;

                    if (!szValue.size())
                    {
                        szValue = *it;
                    }
                }
            }
        }

        while(szValue.endsWith(' ')) szValue.chop(1);

        qDebug() << szValue;

        m_Process.kill();
        m_Process.start(szValue, procParams);
        m_pTrayIcon->setToolTip("Application is set");

        hide();
    }
}

/**   Handler of "Properties" menu item click event

    * @return void
*/
void MainWindow::PropertiesAction()
{
    show();
}

/**   Handler of "About" menu item click event

    * @return void
*/
void MainWindow::AboutAction()
{
    QMessageBox::about(this, QObject::tr("notidletask"), QObject::tr("Not Idle Task ver 1.0.0.2 by Volodymyr Shcherbyna"));
}

/**   Handler of "Exit" menu item click event

    * @return void
*/
void MainWindow::ExitAction()
{
    this->close();
}

void MainWindow::TimerUpdate()
{
    if (m_pIdleImplementation->CheckIdle())
    {
        m_Process.kill();
        m_bJustDisabled = true;
    }
    else if (m_bJustDisabled)
    {
        RelaunchAction();
    }
}
