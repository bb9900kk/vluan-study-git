//	=====================================================================
//	@file		[Message.cpp]
//	@breif		VW MIB3 OI KIPC
//	@author		Designed by jongho.song
//	@author		Implemented by zaezins.lee
//	@date		2016.12.20.
//	@version	0.1b : Skeleton
//	=====================================================================

#include "message.h"
#include <cstdio>


namespace frame{

static const unsigned int queue_max_size = 100;

//	=====================================================================
//	@fn			RecvMsgPkt
//	@breif		Constructor of MsgPkt
//	@param		None
//	@return		None
//	@exception	None
//	@throw		None
//	@warning	None
//	=====================================================================
RecvMsgPkt::RecvMsgPkt()
: src_addr(0), len(0)
{
    memset(this->buf, 0, MAX_SIZE);
}

//	=====================================================================
//	@fn			RecvMsgPkt
//	@breif		Constructor of RecvMsgPkt
//
//	@param1		type	: const unsigned long int
//	@param1		name	: source address
//	@details
//				min		: (0x01LLU << 0)
//				max		: (0x01LLU << 63) 
//
//	@param2		type	: const int
//	@param2		name	: length
//
//	@param3		type : char *
//	@param3		name : buffer
//
//	@return		None
//	@exception	None
//	@throw		None
//	@warning	None
//	=====================================================================
RecvMsgPkt::RecvMsgPkt(const unsigned long int src, const int Len, const char * buff)
: src_addr(src), len(Len)
{
    memset(this->buf, 0, MAX_SIZE);
    memcpy(this->buf, buff, len);
}

//	=====================================================================
//	@fn			push
//	@breif		push message in the queue
//
//	@param1		type	: const unsigned long int
//	@param1		name	: source address
//	@details
//				min 	: (0x01LLU << 0)
//				max 	: (0x01LLU << 63)
//
//	@param2		type	: const int
//	@param2		name	: length
//
//	@param3		type : char *
//	@param3		name : buffer
//
//	@return		None
//
//	@exception	None
//	@throw		None
//	@warning	None
//	=====================================================================
void Message::push(const unsigned long int src, const int len, const char *  buff)
{
    RecvMsgPkt * tmp = new RecvMsgPkt(src, len, buff);
    pthread_mutex_lock(&this->mutex);
    if(this->cnt >= queue_max_size)
    {
    	return;
    }
    this->cnt++;
    this->queue.push_back(tmp);
    sem_post(&this->sem);
    pthread_mutex_unlock(&this->mutex);
}

//	=====================================================================
//	@fn			pop
//	@breif		pop message for the queue
//
//	@param		None
//
//	@return		pointer of poped message
//
//	@exception	None
//	@throw		None
//	@warning	None
//	=====================================================================
const RecvMsgPkt * Message::pop()
{
    RecvMsgPkt * ret = NULL;
    pthread_mutex_lock(&this->mutex);
    if(!queue.empty())
    {
    	this->cnt--;
        ret = this->queue.front();
        this->queue.pop_front();
    }
    else
    {
//       	fprintf(stdout,"[%s]queue is null\n", __func__);
    }
    pthread_mutex_unlock(&this->mutex);
    return ret;
}
//	=====================================================================
//	@fn			blocked_pop
//	@breif		pop message for the queue with blocking mode
//
//	@param		None
//
//	@return		pointer of poped message
//
//	@exception	None
//	@throw		None
//	@warning	None
//	=====================================================================
const RecvMsgPkt * Message::blocked_pop()
{
    const RecvMsgPkt * ret = NULL;
    sem_wait(&this->sem);
    ret = this->pop();
    return ret;
}

//	=====================================================================
//	@fn			Message
//	@breif		Constructor for Message
//
//	@return		None
//
//	@exception	None
//	@throw		None
//	@warning	None
//	=====================================================================
Message::Message()
: cnt(0)
{
	int ret  = 0;
	if((ret = pthread_mutex_init(&mutex, NULL)) != 0)
	{
        fprintf(stdout, "[%s]mutex_init fail %d\n", __func__, ret);
	}
	ret = 0;
    if((ret = sem_init(&this->sem, 0, 0)) != 0)
    {
        fprintf(stdout, "[%s]sem_init fail %d\n", __func__, ret);
    }
}
//	=====================================================================
//	@fn			~Message
//	@breif		destructor of ~Message
//
//	@param		None
//
//	@return		None
//
//	@exception	None
//	@throw		None
//	@warning	None
//	=====================================================================
Message::~Message()
{
	const RecvMsgPkt * tmp = NULL;
	pthread_mutex_destroy(&this->mutex);
	while(!this->queue.empty())
	{
        tmp = this->pop();
        delete tmp;
	}
}

}//end namespace frame
                                                                            
