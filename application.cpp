/********************************************************************************
@(#)File:           application.cpp
@(#)Last changed:   2012/07/17
@(#)Purpose:        GameServer process managment

@(#)Author:         Kristians Jaunzems
@(#)Copyright:      (C) Titanium Software 2012
@(#)Product:        Mu Online Plugin Season 4
@(#)Web:			https://github.com/KristiansJaunzems/MuOnline
/********************************************************************************/
#include "stdAfx.h"

application myApplication;

void application::Restart(){
	STARTUPINFO si;
	PROCESS_INFORMATION pi;

	ZeroMemory(&si, sizeof(si));
    si.cb = sizeof(si);

	if(!CreateProcess("gameserver.exe",0,NULL,NULL,FALSE,0,NULL,NULL,&si,&pi)){
      messageBox.Show(messageBox.normal,"GameServer Restart","Restart has failed, application will now close!");
	  this->Exit();
    }
}

void application::Exit(){
	// TODO: Add data saving procedure
	ExitProcess(0);
}

extern application myApplication;