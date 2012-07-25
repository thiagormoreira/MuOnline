/********************************************************************************
@(#)File:           protocol.cpp
@(#)Last changed:   2012/07/25
@(#)Purpose:        Manages GameServer and Client communication

@(#)Author:         Kristians Jaunzems
@(#)Copyright:      (C) Titanium Software 2012
@(#)Product:        GameServer X Project
@(#)Web:			https://github.com/KristiansJaunzems/MuOnline
/********************************************************************************/
#include "stdAfx.h"

void ProtocolCoreEx(BYTE protoNum, LPBYTE aRecv, DWORD aLen, DWORD aIndex, DWORD Encrypt, int Serial){
	OBJECTSTRUCT *gObj = (OBJECTSTRUCT*)GAMESERVER_OBJECT_POINTER(aIndex);

	switch(protoNum)
	{
		case 0x00: // Player Chat
		break; 
		case 0x03: // Player Connected
			sendPlayerMessage("GameServer X Project.",aIndex,0);
		break;
		case 0xBC:
			if((gObj->TargetNumber == -1) && (gObj->pTransaction==1)){ // Laphap dupe bug fix
				playerDisconnect(aIndex);
				return;
			}
		break;
	}
	dataRecv(protoNum, aRecv, aLen, aIndex, Encrypt, Serial);
}