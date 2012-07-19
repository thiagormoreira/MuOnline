/********************************************************************************
@(#)File:           configReader.h
@(#)Last changed:   2012/07/17
@(#)Purpose:        GameServer costum data file reader class

@(#)Author:         Kristians Jaunzems
@(#)Copyright:      (C) Titanium Software 2012
@(#)Product:        Mu Online Plugin Season 4
@(#)Web:			https://github.com/KristiansJaunzems/MuOnline
/********************************************************************************/

class configreader
{
private:
	char File[100];
	char fileLists[4][100];
	int currentFileListCount;
	bool error;
public:

	struct configuration
	{
		int debugLogLevel;		// 0: None, 1: Minimal, 2: Full
		int debugLogSave;		// 0: Disabled, 1: Enabled
		int gameServerLogSave;	// 0: Disabled, 1: Enabled
	}Configuration;

	///
	///

	int Read(char* selection, char* variable, short minValue, short maxValue, int defaultValue, char* fileName);
	int Read(char* selection, char* variable,int defaultValue, char* fileName);
	int Read(char* selection, char* variable, char* fileName);

	void fileChecker();
	bool fileExist(char* fileName);
};

extern configreader configReader;