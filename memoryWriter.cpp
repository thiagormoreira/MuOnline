/********************************************************************************
@(#)File:           memoryWriter.cpp
@(#)Last changed:   2012/07/19
@(#)Purpose:        Edit and Correct gameserver memory offsets.

@(#)Author:         Kristians Jaunzems
@(#)Copyright:      (C) Titanium Software 2012
@(#)Product:        GameServer X Project
@(#)Web:			https://github.com/KristiansJaunzems/MuOnline
/********************************************************************************/
#include "stdAfx.h"

memorywriter memoryWriter;

void memorywriter::hookThis(DWORD funcOffset, DWORD jmpOffset){
	*(DWORD*)(jmpOffset+1) = funcOffset - (jmpOffset+5);
}

void memorywriter::setByte(DWORD offset, BYTE value){
	*(BYTE*)(offset) = value;
}

void memorywriter::setNop(DWORD offset, int size){
	for(int n=0;n<size; n++){
		*(BYTE*)(offset+n) = 0x90;
	}
}

void memorywriter::setRetn(DWORD offset){
	*(BYTE*)(offset) = 0xC3;
}

extern memorywriter memoryWriter;