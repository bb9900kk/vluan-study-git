//	=====================================================================
//	@file		[Interface.cpp]
//	@breif		VW MIB3 OI KIPC
//	@author		Designed by jongho.song
//	@author		Implemented by zaezins.lee
//	@date		2016.12.20.
//	@version	0.1b : Skeleton
//	=====================================================================
#include "Interface.h"
#include <iostream>
#include "ReadInterface.h"
#include "WriteInterface.h"
#include <cstdio>


namespace kipc{

//	=====================================================================
//	@fn			recv_pkt
//	@breif		receive packet from another process
//
//	@param1		type	: reference of unsigned long int
//	@param1		name	: source address
//	@details
//				min		: (0x01LLU << 0)
//				max		: (0x01LLU << 63) 
//
//	@param2		type		: reference of int
//	@param2		name	: length
//
//	@param3		type	: char *
//	@param3		name	: buffer
//
//	@return		If receive packet success then return zero
//				If receive packet fail then error num
//				- time out = -1
//				read buffer is empty = -2
//
//	@exception	None
//	@throw		None
//	@warning	None
//	=====================================================================

long Interface::recv_pkt(unsigned long int & src, int & len, char ** buf)  
{
	long ret = this->read_obj->read(src, len, buf);
	return ret;
}


//	=====================================================================
//	@fn			send_pkt
//	@breif		send packet to another process
//
//	@param1		type	: const unsigned long int
//	@param1		name	: destination address
//	@details
//				min		: (0x01LLU << 0)
//				max		: (0x01LLU << 0) | (0x01LLU << 1) | ... (0x01LLU << 63)
//
//	@param2		type	: const int
//	@param2		name	: length
//
//	@param3		type	: char *
//	@param3		name	: buffer
//
//	@return		If read success then return zero
//				If read fail then error num
//				- unvaild pid = -1
//				- kernel memory allocate fail = -2
//
//	@exception	None
//	@throw		None
//	@warning	None
//	=====================================================================
long Interface::send_pkt(const unsigned long int dst, const int len, char*  buf)
{
	long ret = this->write_obj->write(dst, len, buf);
	return ret;
}


//	=====================================================================
//	@fn			Interface
//	@breif		Constructor for Interface
//
//	@details 	calculate how many bit shift and set to array id
//
//	@param1		type	: const unsigned long int
//	@param1		name	: process id in <linux/processid_table.h>
//
//	@return		None
//
//	@exception	None
//	@throw		None
//	@warning	None
//	=====================================================================
Interface::Interface(const unsigned long int pid) 
{
	unsigned long int dest = pid;
	unsigned long int arr = 0;
	do{
		arr++;
		dest = dest >> 1;
	}while(dest);
	this->read_obj = new ReadInterface(pid, arr - 1); 
	this->write_obj = new WriteInterface(pid, arr - 1);
}
//	=====================================================================
//	@fn			~Interface
//	@breif		Destructor
//
//	@param		None
//
//	@return		None
//
//	@exception	None
//	@throw		None
//	@warning	None
//	=====================================================================
Interface::~Interface(void)
{
	delete this->read_obj;
	delete this->write_obj;
}

}//end namespace kipc
