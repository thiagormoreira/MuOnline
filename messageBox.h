/********************************************************************************
@(#)File:           messageBox.h
@(#)Last changed:   2012/07/17
@(#)Purpose:        Displays message box

@(#)Author:         Kristians Jaunzems
@(#)Copyright:      (C) Titanium Software 2012
@(#)Product:        Mu Online Plugin Season 4
@(#)Web:			https://github.com/KristiansJaunzems/MuOnline
/********************************************************************************/

class messagebox
{
public:
	enum msgType{
		normal = MB_OK, 
		yesNo = MB_YESNO
	};

	enum msgReturn{
		yes = 6,
		no = 7
	};

	int Show(msgType type, char* title, char* message);
};

extern messagebox messageBox;