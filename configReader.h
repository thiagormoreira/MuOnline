/********************************************************************************
@(#)File:           configReader.h
@(#)Last changed:   2012/07/17
@(#)Purpose:        GameServer costum data file reader class

@(#)Author:         Kristians Jaunzems
@(#)Copyright:      (C) Titanium Software 2012
@(#)Product:        GameServer X Project
@(#)Web:			https://github.com/KristiansJaunzems/MuOnline
/********************************************************************************/

#define	DISABLED	0
#define ENABLED		1

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
		short debugLogLevel;		// 0: None, 1: Minimal, 2: Full
		short debugLogSave;			// 0: Disabled, 1: Enabled
		short gameServerLogSave;	// 0: Disabled, 1: Enabled
		short gameServerChecksum;	// 0: Disabled, 1: Enabled
		short gameServerPersonalID;	// 0: Disabled, 1: Enabled
		short gameServerPVP;		// 0: Disabled, 1: Enabled
		short gameServerCrashdump;	// 0: Disabled, 1: Enabled

	}Configuration;

	///
	///

	int Read(char* selection, char* variable, short minValue, short maxValue, int defaultValue, char* fileName);
	int Read(char* selection, char* variable,int defaultValue, char* fileName);
	int Read(char* selection, char* variable, char* fileName);

	void fileChecker();
	bool fileExist(char* fileName);
	void Init();
};

extern configreader configReader;