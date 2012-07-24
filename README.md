GameServer X Project
========

Multi functional server addon for 1.00.18 and 1.00.90 gameserver series. 
The gameserver x project currently support two gameserver versions but more versions will be supported soon.
Development for support 1.00.60 and 1.00.16 has been started. The castle siege version will come latter.
Functional server file are under development and will be released asap, in mean time you can use any other 1.00.90 and 1.00.18 server files for testing.

Overral
=======
Status: Not Tested!

Current Version: 2.2

Development Change Log
==============
[Version 1.0]
 - Created Initial source.
 - Added messageBox class.
	- Information
		- Function returns button events: yes, no.
	- Function & Variables
	 	- messageBox.Show(Type, Title, Message);
	 	- messageBox.yesNo
	 	- messageBox.normal	
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
		- configReader.Read(selection,variable,fileName);

[Version 1.2]
 - Update configreader class
   - Functions
		- configReader.fileChecker();
		
[Version 1.3]
 - Updated application class
   - Functions
     - myApplications.writeLog(Message);
 - Added memorywriter class
   - Functions
	 - memoryWriter.hookThis(funcOffset,jmpOffset);
	 - memoryWriter.setNop(offset,size);
	 - memoryWriter.setRetn(offset);
	 - memoryWriter.setByte(offset,value);
 - Other minjor source changes.

Game Change Log
==============
[Version 1.0]
 - Added gameserver checksum switch
 - Added gameserver debug log options
	- Log display level
	- Log write to file
 - Added gameserver personal id switch
 - Added gameserver pvp or nonpvp switch
[Version 1.1]
 - Added support for theese gameservers
	- 1.00.90 Common and Siege
	- 1.00.18 Common and Siege
 - Added gameserver crashdump generation switch
 - Added many fixes