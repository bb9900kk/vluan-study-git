#ifndef KIPC_READ_INTERFACE_H_
#define KIPC_READ_INTERFACE_H_

//	=====================================================================
//	@file		[ReadInterface.h]
//	@breif		VW MIB3 OI KIPC
//	@author		Designed by jongho.song
//	@author		Implemented by zaezins.lee
//	@date		2016.12.20.
//	@version	0.1b : Skeleton
//	=====================================================================

#include "CommunicationService.h"

namespace kipc{

//	=====================================================================
//	@class		<ReadInterface>	[<ReadInterface.h>]
//	=====================================================================
class ReadInterface : public CommunicationService
{
public:
//	Constructor
	ReadInterface(const unsigned long int pid, const unsigned long int aid );
//	Destructor
	~ReadInterface(void);
};

}//end namespace kipc
#endif
