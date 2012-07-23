/********************************************************************************
@(#)File:           Main.cpp
@(#)Last changed:   2012/07/23
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
		fixes.Init();
	}
	else{
		if(messageBox.Show(messageBox.typeYesNo,"Plugin Init Problems","GameServer 'WzAG.dll' load error!\nDo you wan't to restart gameserver?") == messageBox.returnYes){
			myApplication.Restart();
			myApplication.Exit();
		}
		else{
			myApplication.Exit();
		}
	}
}