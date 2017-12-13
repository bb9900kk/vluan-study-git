#ifndef KIPC_INTERFACE_H_
#define KIPC_INTERFACE_H_

//	=====================================================================
//	@file		[Interface.h]
//	@breif		VW MIB3 OI KIPC
//	@author		Designed by jongho.song
//	@author		Implemented by zaezins.lee
//	@date		2016.12.20.
//	@version	0.1b : Skeleton
//	=====================================================================

#include "CommunicationService.h"
#include "ReadInterface.h"
#include "WriteInterface.h"

namespace kipc{
//	=====================================================================
//	@class		<Interface>	[<Interface.h>]
//	=====================================================================
class Interface
{
private:
//	Attribute list
	CommunicationService* read_obj; 
	CommunicationService* write_obj; 
public:
//	Function list
	long recv_pkt(unsigned long int & src, int & len, char ** buf);
	long send_pkt(const unsigned long int dst, const int len, char * buf);

//	Constructor
	Interface(const unsigned long int pid);
//	Destructor
	virtual ~Interface(void);
};

}//end namespace kipc

#endif
