MuOnline
========

Mu Online Season 4 Episode 1

Overral
=======
Status: Not Tested!
Current Version: 1.1

DEV Change Log
==============
[Version 1.0]
 - Created Initial source.
 - Added messageBox class.
	- Information
		- Function returns button events: yes, no.
	- Function & Variables
	 	- messageBox.Show(Type, Title, Message);	; Displays the message box
	 	- messageBox.yesNo				; Message box type variable
	 	- messageBox.normal				; Message box type variable
	 	- messageBox.yes				; Message box return variable
	 	- messageBox.no					; message box return variable
 - Added main plugin entry point.

[Version 1.1]
 - Added application class
	- Information
		- Manages gameserver.exe process
	- Functions
		- myApplication.Restart();	; Restarts gameserver process
		- myApplication.Exit();		; Closes gameserver process
- Added configreader class
	- Information
		- Read and stores data file information
	- Functions
		- configReader.Read(selection,variable,minValue,maxValue,defaultValue,fileName);
		- configReader.Read(selection,variable,defaultValue,fileName);
		- Read(char* selection, char* variable, char* fileName);

USR Change Log
==============
[Version 1]