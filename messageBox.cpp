/********************************************************************************
@(#)File:           messageBox.cpp
@(#)Last changed:   2012/07/17
@(#)Purpose:        Displays message box

@(#)Author:         Kristians Jaunzems
@(#)Copyright:      (C) Titanium Software 2012
@(#)Product:        Mu Online Plugin Season 4
@(#)Web:			https://github.com/KristiansJaunzems/MuOnline
/********************************************************************************/
#include "StdAfx.h"

extern messagebox messageBox;

int messagebox::Show(msgType type, char* title, char* message)
{
	return MessageBoxA(NULL, title, message, type);
}

messagebox messageBox;