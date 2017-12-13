//	=====================================================================
//	@file		[CommunicationService.cpp]
//	@breif		VW MIB3 OI KIPC
//	@author		Designed by jongho.song
//	@author		Implemented by zaezins.lee
//	@date		2016.12.20.
//	@version	0.1b : Skeleton
//	=====================================================================

#include "CommunicationService.h"
#include <sys/ioctl.h>
#include <string.h>
#include <cstdio>
#include <iostream>
#include <cstring>
#include <unistd.h>

namespace kipc{

//	=====================================================================
//	@fn			MsgPkt
//	@breif		Constructor of MsgPkt
//	@param		None
//	@return		None
//	@exception	None
//	@throw		None
//	@warning	None
//	=====================================================================
MsgPkt::MsgPkt()
: src_addr(0), dst_addr(0), len(0)
{
	memset(this->buf, 0, sizeof(this->buf));
}

//	=====================================================================
//	@fn			MsgPkt
//	@breif		Constructor of MsgPkt
//
//	@param1		type	: const unsigned long int
//	@param1		name	: source address
//	@details
//				min		: (0x01LLU << 0)
//				max		: (0x01LLU << 63) 
//
//	@param2		type	: const unsigned long int
//	@param2		name	: destination address
//
//	@details
//				min		: (0x01LLU << 0)
//				max		: (0x01LLU << 0) | (0x01LLU << 1) | ... (0x01LLU << 63)
//
//	@param3		type	: const int
//	@param3		name	: length
//
//	@param4		type : char *
//	@param4		name : buffer
//
//	@return		None
//	@exception	None
//	@throw		None
//	@warning	None
//	=====================================================================
MsgPkt::MsgPkt(const unsigned long int src, const unsigned long int dst, const int len, char * const buf)
: src_addr(src), dst_addr(dst), len(len)
{
	if(len > MAX_SIZE)
	{
		this->len = MAX_SIZE;
	}
	else
	{
		this->len = len;
	}
	memcpy(this->buf, buf, this->len);
}

//	=====================================================================
//	@fn			set_pid
//	@breif		set process id
//
//	@param1		type	: const unsigned long int
//	@param1		name	: process id
//	@details
//				min		: (0x01LLU << 0)
//				max		: (0x01LLU << 63) 
//
//	@return		void
//	@exception	None
//	@throw		None
//	@warning	None
//	=====================================================================
void CommunicationService::set_pid(const unsigned long int pid)
{
	this->pid = pid;
}

//	=====================================================================
//	@fn			set_array_id
//	@breif		set process id
//
//	@param1		type	: const unsigned long int
//	@param1		name	: array id
//	@details
//				min		: 0
//				max		: 63 
//
//	@return		void
//	@exception	None
//	@throw		None
//	@warning	None
//	=====================================================================
void CommunicationService::set_array_id(const unsigned long int aid)
{
	this->array_id = aid;
}

//	=====================================================================
//	@fn			get_pid
//	@breif		return process id
//
//	@param		None
//
//	@return		type	: const unsigned long int
//	@return		name	: process id
//
//	@exception	None
//	@throw		None
//	@warning	None
//	=====================================================================
unsigned long int CommunicationService::get_pid(void) const
{
	return this->pid;
}

//	=====================================================================
//	@fn			get_array_id
//	@breif		return array id
//
//	@param		None
//	@return		type	: const unsigned long int
//
//	@exception	None
//	@throw		None
//	@warning	None
//	=====================================================================
unsigned long int CommunicationService::get_array_id(void) const
{
	return this->array_id;
}

//	=====================================================================
//	@fn			read
//	@breif		call ioctl (csr_ioctl)
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
//	@return		If read success then return zero
//				If read fail then error num
//				- time out = -1
//				- read buffer is empty = -2
//
//	@exception	None
//	@throw		None
//	@warning	None
//	=====================================================================
long CommunicationService::read(unsigned long int & src, int & len, char ** buffer)
{
	this->read_buff->src_addr = get_array_id();
	long ret = ioctl(this->fd, 0, (char *)this->read_buff);
	if(ret == -1)
	{
//		fprintf(stdout,"[%s]sem time out\n", __func__);
	}
	else if (ret == -2)
	{
//		fprintf(stdout,"[%s]read buff is null\n", __func__);
	}
	else if (ret >= 0)
	{
		src = this->read_buff->src_addr;
		len = this->read_buff->len;
		*buffer = this->read_buff->buf;
	}

	return ret; 
}
//	=====================================================================
//	@fn			write
//	@breif		call ioctl (css_ioctl)
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
long CommunicationService::write(const unsigned long int dst, const int len, char *const  buf)
{
	long ret = 0;
	struct MsgPkt tmp(get_pid(), dst, len, buf);
	
	ret = ioctl(this->fd, 0, &tmp);

	if(ret == -1)
	{
//		fprintf(stdout,"[%s]unvalid pid\n", __func__);
	}
	else if (ret == -2)
	{
//		fprintf(stdout,"[%s]kQueue kmalloc fail\n", __func__);
	}
	else if(ret == 0)
	{
//		fprintf(stdout,"[%s]success\n", __func__);
	}
	return ret;
}
//	=====================================================================
//	@fn			CommunicationService
//	@breif		constructor of CommunicationService
//
//	@param		None
//
//	@return		None
//
//	@exception	None
//	@throw		None
//	@warning	None
//	=====================================================================
CommunicationService::CommunicationService(void)
{
	;
}

//	=====================================================================
//	@fn			CommunicationService
//	@breif		Constructor of CommunicationService
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
CommunicationService::CommunicationService(const unsigned long int pid,const unsigned long int arrayid)
: pid(pid), array_id(arrayid)
{
	;
}


//	=====================================================================
//	@fn			~CommunicationService
//	@breif		destructor of CommunicationService
//
//	@param		None
//
//	@return		None
//
//	@exception	None
//	@throw		None
//	@warning	None
//	=====================================================================
CommunicationService::~CommunicationService(void)
{
	;
}

}//end namespace kipc

