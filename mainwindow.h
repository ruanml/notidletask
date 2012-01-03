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

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSystemTrayIcon>
#include <QtGui>

#include <QProcess>

#include "main.h"

namespace Ui
{
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();

protected:
    void changeEvent(QEvent *e);

private slots:
     void on_CHECKBOX_KILL_APP_IF_EXIT_stateChanged(int );
     void on_BUTTON_CANCEL_clicked();
     void RelaunchAction();
     void PropertiesAction();
     void AboutAction();
     void ExitAction();
     void TimerUpdate();

private:
    Ui::MainWindow  *ui;
    QSystemTrayIcon *m_pTrayIcon;
    QMenu *m_pTrayIconMenu;
    QAction *m_pRelaunchAction;
    QAction *m_pPropertiesAction;
    QAction *m_pAboutAction;
    QAction *m_pExitAction;
    QComboBox * m_pImageItems;
    QTimer    * m_pTimer;
private:
    Configuration m_Configuration;
    ISystemIdle * m_pIdleImplementation;
    QProcess m_Process;
    bool m_bJustDisabled;

private slots:
    void on_BUTTON_OK_clicked();
};

#endif // MAINWINDOW_H
