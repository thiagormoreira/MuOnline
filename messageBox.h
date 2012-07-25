/********************************************************************************
@(#)File:           messageBox.h
@(#)Last changed:   2012/07/17
@(#)Purpose:        Displays message box

@(#)Author:         Kristians Jaunzems
@(#)Copyright:      (C) Titanium Software 2012
@(#)Product:        GameServer X Project
@(#)Web:			https://github.com/KristiansJaunzems/MuOnline
/********************************************************************************/

class messagebox
{
public:
	enum msgType{
		typeNormal = MB_OK, 
		typeYesNo = MB_YESNO
	};

	enum msgReturn{
		returnYes = 6,
		returnNo = 7
	};

	int Show(msgType type, char* title, char* message);
};

extern messagebox messageBox;