/********************************************************************************
@(#)File:           Main.h
@(#)Last changed:   2012/07/17
@(#)Purpose:        Plugin main entry point

@(#)Author:         Kristians Jaunzems
@(#)Copyright:      (C) Titanium Software 2012
@(#)Product:        GameServer X Project
@(#)Web:			https://github.com/KristiansJaunzems/MuOnline
/********************************************************************************/

//==================================================================================
// GameServer Version
// This variable controls gameserver version for which the project will be compiled.
//
// Supported Versions:
//	1.00.90 > 0
//  1.00.18 > 1
//==================================================================================
#define GAMESERVER_VERSION			0
//===========================================================================
// GameServer Type
// This variable controls gameserver type for which the project will be compiled.
//
// Supported Types:
//	GameServer Common		> 0
//  GameServer Castle Siege > 1
//=========================================================================================
#define GAMESERVER_TYPE				0

//=========================================================================================
// GameServer Configuration Control
// This variable controls from where server will read configuration values.
//
// Supported Types:
//	Source		> 0
//  Data		> 1
//
// Information:
//	Source - This means that gameserver configuration will be read rigth from source file.
//  Data - This means that gameserver will load configuration from data file on startup.
//=========================================================================================
#define GAMESERVER_CONFIG_CONTROL	0