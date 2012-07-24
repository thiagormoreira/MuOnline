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

//======================================================
// GameServer 1.00.90, Type Normal
//======================================================
#if (GAMESERVER_VERSION == 0 && GAMESERVER_TYPE == 0)

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

	// ===================================================
	// GameServer PVP Fixes
	// ===================================================

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
	}
	memoryWriter.setByte(0x004D6b46,0x3F);		// Stadium Kill

	// ===================================================
	// GameServer Core Fixes
	// ===================================================

	if(configReader.Configuration.gameServerChecksum){
		memoryWriter.setByte(0x00438D3A, 0x74);
	}
	else{
		memoryWriter.setByte(0x00438D3A, 0xEB);
	}

	memoryWriter.setRetn(0x00403233);		// Destroy gioCP error fix
	memoryWriter.setRetn(0x004069AB);		// Serial 0x00000000 error fix
	memoryWriter.setRetn(0x00404584);		// Hack tool dissconnect fix

	memoryWriter.setByte(0x00579CFF,0x74);	// Devil Square server connect fix

	memoryWriter.setByte(0x004369B7,0xEB);	// Socket Serial

	memoryWriter.setByte(0x0043880E,0x90);	// Hack reporting fix
	memoryWriter.setByte(0x0043880F,0x90);	//
	memoryWriter.setByte(0x00438830,0xE9);	//
	memoryWriter.setByte(0x00438831,0x74);	//
	memoryWriter.setByte(0x00438832,0x01);	//
	memoryWriter.setByte(0x00438833,0x00);	//
	memoryWriter.setByte(0x00438835,0x90);	//

	memoryWriter.setByte(0x004B406F,0xEB);	// Network error-l1 CloseClient error fix
	memoryWriter.setNop(0x004B33DE,6);		// Error-L2 : Index(%d) %x %x %x fix

	memoryWriter.setNop(0x00458612,27);		// Protocol error fix

	memoryWriter.setByte(0x004B409F,0x90);	// Network invalid socket fix
	memoryWriter.setByte(0x004B40A0,0x90);	//
	memoryWriter.setByte(0x004B41CF,0xEB);	//

	memoryWriter.setNop(0x0056D6F3,5);      // GameServer webzen authentication remove
    memoryWriter.setByte(0x0056D708,0xEB);  // 

	memoryWriter.setByte(0x005AAA3C,0x58);	// MonsterSkill.txt limit remove
    memoryWriter.setByte(0x005AAA3D,0x02); 

	if(configReader.Configuration.gameServerCrashdump == 0){
		memoryWriter.setByte(0x004C7041,0xE9);  // Disable dump file genaration
		memoryWriter.setByte(0x004C7042,0x2E);  // 
		memoryWriter.setByte(0x004C7043,0x01);  //
		memoryWriter.setByte(0x004C7044,0x00);  //
		memoryWriter.setByte(0x004C7046,0x90);  //
	}

	BYTE NetworkPacketSendLimit[] = {0xE9,0x42,0x01,0x00,0x00,0x90};
	memcpy((int*)0x004B10FB,NetworkPacketSendLimit,sizeof(NetworkPacketSendLimit));

#pragma message ("Compile : Version > 1.00.90, Type > Common")
#endif
//======================================================
// GameServer 1.00.90, Type Siege
//======================================================
#if GAMESERVER_VERSION == 0 && GAMESERVER_TYPE == 1
	#error "GameServer 1.00.90, Type Siege not supported yet!" 
#endif
//======================================================
// GameServer 1.00.18, Type Normal
//======================================================
#if GAMESERVER_VERSION == 1 && GAMESERVER_TYPE == 0

	// ===================================================
	// GameServer Core Fixes
	// ===================================================

	memoryWriter.setByte(0x0052D6DA,0xEB); // Remove M:// drive request

	memoryWriter.setRetn(0x00402B9E);	// Destroy gioCP error fix
	memortWriter.setNop(0x00402B9F,4);	//

	memoryWriter.setRetn(0x0040635C);	// Serial 0x00000000 error fix
	memoryWriter.setNop(0x0040635D,4);	//

	memoryWriter.setByte(0x0042FD6D,0xEB); // Socket Serial

	if(configReader.Configuration.gameServerChecksum){
		memoryWriter.setByte(0x00431C38,0x75);
	}

	#pragma message ("Compile : Version > 1.00.18, Type > Common")
#endif
//======================================================
// GameServer 1.00.18, Type Siege
//======================================================
#if GAMESERVER_VERSION == 1 && GAMESERVER_TYPE == 1
	#error "GameServer 1.00.18, Type Siege not supported yet!" 
#endif
}

extern cfixes fixes;