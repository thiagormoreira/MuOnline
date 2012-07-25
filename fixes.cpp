/********************************************************************************
@(#)File:           fixes.cpp
@(#)Last changed:   2012/07/25
@(#)Purpose:        GameServer fixes and modifications

@(#)Author:         Kristians Jaunzems
@(#)Copyright:      (C) Titanium Software 2012
@(#)Product:        GameServer X Project
@(#)Web:			https://github.com/KristiansJaunzems/MuOnline
/********************************************************************************/
#include "stdAfx.h"

cfixes fixes;

void cfixes::Init(){
	if(GAMESERVER_CHECKSUM_DISABLE != DEFINE_DISABLED && configReader.Configuration.gameServerChecksum == 0){
		memoryWriter.setByte(GAMESERVER_CHECKSUM_DISABLE,0x75);
	}
	if(GAMESERVER_REMOVE_MDRIVE != DEFINE_DISABLED){
		memoryWriter.setByte(GAMESERVER_REMOVE_MDRIVE,0xEB);
	}
	if(GAMESERVER_SOCKET_SERIAL_FIX != DEFINE_DISABLED){
		memoryWriter.setByte(GAMESERVER_SOCKET_SERIAL_FIX,0xEB);
	}
	if(GAMESERVER_DESTROY_GIOCP_FIX_01 != DEFINE_DISABLED){
		memoryWriter.setRetn(GAMESERVER_DESTROY_GIOCP_FIX_01);
	}else if(GAMESERVER_DESTROY_GIOCP_FIX_02 != DEFINE_DISABLED){
		memoryWriter.setNop(GAMESERVER_DESTROY_GIOCP_FIX_02,4);
	}
	if(GAMESERVER_SERIAL_0x00000000_FIX_01 != DEFINE_DISABLED){
		memoryWriter.setRetn(GAMESERVER_SERIAL_0x00000000_FIX_01);
	}else if(GAMESERVER_SERIAL_0x00000000_FIX_02 != DEFINE_DISABLED){
		memoryWriter.setNop(GAMESERVER_SERIAL_0x00000000_FIX_02,4);
	}
	if(GAMESERVER_HACK_TOOL_DISCONNECT_FIX != DEFINE_DISABLED){
		memoryWriter.setRetn(GAMESERVER_HACK_TOOL_DISCONNECT_FIX);
	}
}

extern cfixes fixes;