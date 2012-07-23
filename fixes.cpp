/********************************************************************************
@(#)File:           fixes.cpp
@(#)Last changed:   2012/07/23
@(#)Purpose:        GameServer fixes and modifications

@(#)Author:         Kristians Jaunzems
@(#)Copyright:      (C) Titanium Software 2012
@(#)Product:        Mu Online Plugin Season 4
@(#)Web:			https://github.com/KristiansJaunzems/MuOnline
/********************************************************************************/
#include "stdAfx.h"

cfixes fixes;

void cfixes::Init(){
	if(configReader.Configuration.gameServerChecksum){
		memoryWriter.setByte(0x00438D3A, 0x74);
	}
	else{
		memoryWriter.setByte(0x00438D3A, 0xEB);
	}
	if (!configReader.Configuration.gameServerPersonalID){
		memoryWriter.setNop(0x0043B9D6, 5);	// Personal ID Fix
		memoryWriter.setNop(0x004504E9, 2);	// Guild ID Fix
		memoryWriter.setNop(0x00450376, 6);	// Guild ID Fix
	}
	if(configReader.Configuration.debugLogSave){
		if(configReader.Configuration.debugLogLevel == 0){
			memoryWriter.setNop(0x0050D1C6,6);
			memoryWriter.setNop(0x00582C56,6);
			memoryWriter.setNop(0x005938D6,6);
			memoryWriter.setNop(0x005C27D8,6);
			memoryWriter.setNop(0x005E6F60,6);
			memoryWriter.setNop(0x004B8685,6);
		}
	}
	if(configReader.Configuration.gameServerPVP){
		memoryWriter.setByte(0x00460B1C+2,0x07);	// Chaos Castle
		memoryWriter.setByte(0x0046303A+2,0x07);
		memoryWriter.setByte(0x004632A3+2,0x07);
		memoryWriter.setByte(0x0046327B+2,0x07);
		memoryWriter.setByte(0x005D945C,0x07);
		memoryWriter.setByte(0x005DAA33,0x07);
		memoryWriter.setByte(0x0046227E, 0x07);		// Blood Castle
		memoryWriter.setByte(0x00460A20, 0x07);
		memoryWriter.setByte(0x005A5714, 0x07);
		memoryWriter.setByte(0x0045FF36, 0x07);		// Devil Square
		memoryWriter.setByte(0x00460957, 0x07);
		memoryWriter.setByte(0x005A444E, 0x07);
		memoryWriter.setByte(0x004D6b46,0x3F);		// Stadium
	}
}

extern cfixes fixes;