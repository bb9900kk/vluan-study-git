#ifndef KIPC_MESSAGE_H_
#define KIPC_MESSAGE_H_

//	=====================================================================
//	@file		[Message.h]
//	@breif		VW MIB3 OI KIPC
//	@author		Designed by jongho.song
//	@author		Implemented by zaezins.lee
//	@date		2016.12.20.
//	@version	0.1b : Skeleton
//	=====================================================================

#include <pthread.h>
#include <deque>
#include <semaphore.h>
#include <cstring>
#include "CommunicationService.h"

namespace frame{

//	=====================================================================
//	@struct 	<RecvMsgPkt>	[<Message.h>]
//	=====================================================================

struct RecvMsgPkt
{
public:
//	Attribute list
	unsigned long int src_addr;
	int len;
	char buf[MAX_SIZE];
	
//	Constructor
    RecvMsgPkt();
    RecvMsgPkt(const unsigned long int src, const int Len, const char *  buff);
};

//	=====================================================================
//	@class		<Message>	[<Message.h>]
//	=====================================================================
class Message
{
private:
//	Attribute list
	unsigned int cnt;
	pthread_mutex_t mutex;
	sem_t sem;
	std::deque<RecvMsgPkt *> queue;

public:
//	Function list
	void push(const unsigned long int src,const int len, const char *  buff);
	const RecvMsgPkt * pop();
	const RecvMsgPkt * blocked_pop();

//	Constructor
	Message();
//	Destructor
	~Message();
};// end Message class

}//end namespace frame

#endif /* MIB_MESSAGE_H_ */
