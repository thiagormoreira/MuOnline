/********************************************************************************
@(#)File:           application.cpp
@(#)Last changed:   2012/07/17
@(#)Purpose:        GameServer process managment

@(#)Author:         Kristians Jaunzems
@(#)Copyright:      (C) Titanium Software 2012
@(#)Product:        GameServer X Project
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
      messageBox.Show(messageBox.typeNormal,"GameServer Restart","Restart has failed, application will now close!");
	  this->Exit();
    }
}

void application::Exit(){
	// TODO: Add data saving procedure
	ExitProcess(0);
}

void application::writeLog(char *Message){
	SYSTEMTIME time;
	GetLocalTime(&time);

	sprintf(fileName,".\\Log\\Console(%02d.%02d.%02d).log", time.wDay, time.wMonth, time.wYear);

	FILE *logFile = fopen(fileName,"a+");
	fputs(Message,logFile);
	fclose(logFile);
}

extern application myApplication;