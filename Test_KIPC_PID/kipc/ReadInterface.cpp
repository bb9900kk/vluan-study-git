//	=====================================================================
//	@file		[ReadInterface.cpp]
//	@breif		VW MIB3 OI KIPC
//	@author		Designed by jongho.song
//	@author		Implemented by zaezins.lee
//	@date		2016.12.20.
//	@version	0.1b : Skeleton
//	=====================================================================
#include "ReadInterface.h"
#include <iostream>
#include <fcntl.h>
#include <unistd.h>
#include <cstring>
#include <cstdio>

namespace kipc{
//	=====================================================================
//	@fn			ReadInterface
//	@breif		Constructor of ReadInterface
//
//	@param1		type	: const unsigned long int
//	@param1		name	: process id
//	@details
//				min 	: (0x01LLU << 0)
//				max 	: (0x01LLU << 63) 
//
//	@param2		type	: const unsigned long int
//	@param2		name	: array id
//	@details
//				min		: 0
//				max		: 63
//
//	@return		None
//	@exception	None
//	@throw		None
//	@warning	None
//	=====================================================================
ReadInterface::ReadInterface(const unsigned long int pid, const unsigned long int aid)
: CommunicationService(pid, aid)
{
	this->fd = open("/dev/csr", O_RDONLY, 0666);
	this->read_buff = new MsgPkt;
	if(this->fd == -1)
	{
		fprintf(stdout, "open failed [%s]", __func__);
	}
}
//	=====================================================================
//	@fn			~ReadInterface
//	@breif		destructor of ReadInterface
//
//	@param		None
//
//	@return		None
//
//	@exception	None
//	@throw		None
//	@warning	None
//	=====================================================================
ReadInterface::~ReadInterface(void)
{
	delete this->read_buff;
	close(this->fd);
}

}//end namespace kipc