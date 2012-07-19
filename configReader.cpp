/********************************************************************************
@(#)File:           configReader.cpp
@(#)Last changed:   2012/07/17
@(#)Purpose:        GameServer costum data file reader class

@(#)Author:         Kristians Jaunzems
@(#)Copyright:      (C) Titanium Software 2012
@(#)Product:        Mu Online Plugin Season 4
@(#)Web:			https://github.com/KristiansJaunzems/MuOnline
/********************************************************************************/
#include "stdAfx.h"

configreader configReader;

int configreader::Read(char *selection, char *variable, short minValue, short maxValue, int defaultValue, char *fileName){
	sprintf(File,"../dataEx/%s.gcf",fileName);	// Costum config extension {x}.gcf : GameServerConfigFile 

	int Result = GetPrivateProfileInt(selection,variable,defaultValue,File);

	if(Result < minValue && Result > maxValue)
	{
		// TODO: Add out of bounds error.
		return defaultValue;
	}

	return Result;
}
int configreader::Read(char *selection, char *variable, int defaultValue, char *fileName){
	sprintf(File,"../dataEx/%s.gcf",fileName);	// Costum config extension {x}.gcf : GameServerConfigFile 

	return GetPrivateProfileInt(selection,variable,defaultValue,File);
}
int configreader::Read(char *selection, char *variable, char *fileName){
	sprintf(File,"../dataEx/%s.gcf",fileName);	// Costum config extension {x}.gcf : GameServerConfigFile 

	return GetPrivateProfileInt(selection,variable,-1,File);
}

void configreader::fileChecker(){
	this->currentFileListCount = 1;
	this->error = false;

	strcpy(fileLists[1],"gameserver");

	for(int startIndex = 1; startIndex > this->currentFileListCount; startIndex++){
		if(this->fileExist(fileLists[startIndex]) == false){
			messageBox.Show(messageBox.typeNormal,"File Not Found!",fileLists[startIndex]);
			error = true;
		}
	}

	if(this->error == true){
		messageBox.Show(messageBox.typeNormal,"Config Reader error","One or more config files not found!\nGameServer will now close!");
		myApplication.Exit();
	}
}

bool configreader::fileExist(char* fileName){
	sprintf(File,"../dataEx/%s.gcf",fileName);	// Costum config extension {x}.gcf : GameServerConfigFile 

	WIN32_FIND_DATAA file;
	if (FindFirstFileA(File,&file)==INVALID_HANDLE_VALUE){
		return false;
	}
	return true;
}

extern configreader configReader;