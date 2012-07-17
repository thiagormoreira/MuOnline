/********************************************************************************
@(#)File:           Main.cpp
@(#)Last changed:   2012/07/17
@(#)Purpose:        Plugin main entry point

@(#)Author:         Kristians Jaunzems
@(#)Copyright:      (C) Titanium Software 2012
@(#)Product:        Mu Online Plugin Season 4
@(#)Web:			https://github.com/KristiansJaunzems/MuOnline
/********************************************************************************/
#include "StdAfx.h"

extern "C" __declspec (dllexport) void __cdecl initPlugin(){
	DWORD oldProtect;
	if(VirtualProtect(LPVOID(0x401000),3543191,PAGE_EXECUTE_READWRITE,&oldProtect)){
		// TODO: Add Plugin loading points
	}
	else{
		if(messageBox.Show(messageBox.yesNo,"Plugin Init Problems","GameServer 'WzAG.dll' load error!\nDo you wan't to restart gameserver?") == messageBox.yes){
			// TODO: Add GameServer restart code
		}
		else{
			ExitProcess(0);
		}
	}
}