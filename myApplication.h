/********************************************************************************
@(#)File:           application.h
@(#)Last changed:   2012/07/17
@(#)Purpose:        GameServer process managment

@(#)Author:         Kristians Jaunzems
@(#)Copyright:      (C) Titanium Software 2012
@(#)Product:        Mu Online Plugin Season 4
@(#)Web:			https://github.com/KristiansJaunzems/MuOnline
/********************************************************************************/
class application
{
private:
	char fileName[100];

public:
	void Restart();
	void Exit();
	void writeLog(char* message);
};

extern application myApplication;