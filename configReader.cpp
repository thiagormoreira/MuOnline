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


extern configreader configReader;