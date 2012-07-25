/********************************************************************************
@(#)File:           gameServer.h
@(#)Last changed:   2012/07/25
@(#)Purpose:        GameServer version function and offsets control

@(#)Author:         Kristians Jaunzems
@(#)Copyright:      (C) Titanium Software 2012
@(#)Product:        GameServer X Project
@(#)Web:			https://github.com/KristiansJaunzems/MuOnline
/********************************************************************************/
#include "stdAfx.h"

DEC_FUNC(GCServerMsgStringSend,sendPlayerMessage,GAMESERVER_GC_SERVER_MSG_STRING_SEND);
DEC_FUNC(CloseClient,playerDisconnect,GAMESERVER_CLOSE_CLIENT);
DEC_FUNC(ItemSerialCreateSend,playerItemSend,GAMESERVER_ITEM_SERIAL_CREATE_SEND);
DEC_FUNC(DataSend,dataSend,GAMESERVER_DATA_SEND);