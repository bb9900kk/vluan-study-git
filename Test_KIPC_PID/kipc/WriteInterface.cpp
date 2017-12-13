//	=====================================================================
//	@file		[WriteInterface.cpp]
//	@breif		VW MIB3 OI KIPC
//	@author		Designed by jongho.song
//	@author		Implemented by zaezins.lee
//	@date		2016.12.20.
//	@version	0.1b : Skeleton
//	=====================================================================

#include "WriteInterface.h"
#include <iostream>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
namespace kipc{
//	=====================================================================
//	@fn			WriteInterface
//	@breif		Constructor of WriteInterface
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
WriteInterface::WriteInterface(const unsigned long int pid, const unsigned long int aid )
: CommunicationService(pid, aid)
{
	this->fd = open("/dev/css", O_WRONLY, 0666);
	if(this->fd == -1)
	{
		fprintf(stdout, "open failed [%s]", __func__);
	}
}
//	=====================================================================
//	@fn			~WriteInterface
//	@breif		destructor of WriteInterface
//
//	@param		None
//
//	@return		None
//
//	@exception	None
//	@throw		None
//	@warning	None
//	=====================================================================
WriteInterface::~WriteInterface(void)
{
	close(this->fd);
}

}//end namespace kipc