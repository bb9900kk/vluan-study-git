#ifndef KIPC_WRITE_INTERFACE_H_
#define KIPC_WRITE_INTERFACE_H_

//	=====================================================================
//	@file		[WriteInterface.h]
//	@breif		VW MIB3 OI KIPC
//	@author		Designed by jongho.song
//	@author		Implemented by zaezins.lee
//	@date		2016.12.20.
//	@version	0.1b : Skeleton
//	=====================================================================

#include "CommunicationService.h"
namespace kipc{

class WriteInterface : public CommunicationService
{
//	=====================================================================
//	@class		<WriteInterface>	[<WriteInterface.h>]
//	=====================================================================
public:
//	Constructor
	WriteInterface(const unsigned long int pid, const unsigned long int aid);
//	Destructor
	~WriteInterface(void);
};

}//end namespace kipc

#endif
