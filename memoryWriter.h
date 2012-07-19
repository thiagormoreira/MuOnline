/********************************************************************************
@(#)File:           memoryWriter.h
@(#)Last changed:   2012/07/19
@(#)Purpose:        Edit and Correct gameserver memory offsets.

@(#)Author:         Kristians Jaunzems
@(#)Copyright:      (C) Titanium Software 2012
@(#)Product:        Mu Online Plugin Season 4
@(#)Web:			https://github.com/KristiansJaunzems/MuOnline
/********************************************************************************/

class memorywriter
{
public:
	void hookThis(DWORD funcOffset,DWORD jmpOffset);
	void setNop(DWORD offset,int size);
	void setRetn(DWORD offset);
	void setByte(DWORD offset,BYTE value);
};

extern memorywriter memoryWriter;