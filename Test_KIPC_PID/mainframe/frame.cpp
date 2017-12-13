//	=====================================================================
//	@file		[frame.cpp]
//	@breif		VW MIB3 OI KIPC
//	@author		Designed by jongho.song
//	@author		Implemented by zaezins.lee
//	@date		2016.12.20.
//	@version	0.1b : Skeleton
//	=====================================================================

#include "frame.h"
#include <cstdio>

namespace frame{
//	=====================================================================
//	@fn			QueueInfo
//	@breif		Constructor of QueueInfo
//
//	@param1		None
//
//	@return		None
//	@exception	None
//	@throw		None
//	@warning	None
//	=====================================================================

QueueInfo::QueueInfo()
{
	this->name = NULL;
	this->msg = NULL;
}
//	=====================================================================
//	@fn			QueueInfo
//	@breif		Constructor of QueueInfo
//
//	@param1		type	: const pointer of char
//	@param1		name	: name of queue
//
//	@param2		type	: pointer of Message queue
//
//	@return		None
//	@exception	None
//	@throw		None
//	@warning	None
//	=====================================================================
QueueInfo::QueueInfo(const char * name, Message * msg)
{
	this->name = name;
	this->msg = msg;
}//end QueueInfo

//	=====================================================================
//	@fn			eventchecker_kipc
//	@breif		thread function for kipc
//
//	@details 	to-do
//
//	@param		None
//
//	@return		None
//
//	@exception	None
//	@throw		None
//	@warning	None
//	=====================================================================
void * Frame::event_checker_kipc(void * arg)
{
	Frame * pthis = static_cast<Frame *>(arg);

	if(pthis != NULL)
	{
		while(true)
		{
			int len = 0;
			char * buff = NULL;
			unsigned long int src  = 0;
			if (pthis->process->recv_pkt(src, len, &buff) == 0)
			{
				pthis->event_handler(src, len, buff);
			}// end if recv_pkt
		}// end while
	}// end if
	else
	{
		fprintf(stdout,"[%s]arg is NULL\n", __func__);	
	}// end else

	return NULL;
}// end event_checker_kipc

//	=====================================================================
//	@fn			event_checker_message
//	@breif		thread function for handling message queue
//
//	@details 	to-do
//
//	@param		None
//
//	@return		None
//
//	@exception	None
//	@throw		None
//	@warning	None
//	=====================================================================
void * Frame::event_checker_message(void * arg)
{
	Frame* pthis = static_cast<Frame*>(arg);
	if(pthis != NULL)
	{
		while(true)
		{
			if(pthis->blk == BLOCK::ENABLE)
			{
				const RecvMsgPkt * tmp = pthis->pop_queue->blocked_pop();
				if(tmp != NULL)
				{
					pthis->event_handler(tmp->src_addr, tmp->len, (char*)tmp->buf);
					delete tmp;
				} // end tmp != NULL
			} // end if BLOCK::ENABLE
			else
			{
				const RecvMsgPkt * tmp = pthis->pop();
				if(tmp != NULL)
				{
					pthis->event_handler(tmp->src_addr, tmp->len, (char*)tmp->buf);
					delete tmp;
				}// end if tmp != NULL
				else
				{
					pthis->event_handler(static_cast<unsigned long int>(0), static_cast<unsigned long int>(0), NULL);
				}// tmp == NULL
			} // end BLOCK::DISABLE
		}// end while true
	}// end if pthis != NULL
	else
	{
		fprintf(stdout,"[%s]arg is NULL\n", __func__);	
	}// end else

	return NULL;
}// end event_checker_message


//	=====================================================================
//	@fn			event_checker_no_message
//	@breif		thread function for handling without message queue
//
//	@details 	to-do
//
//	@param		None
//
//	@return		None
//
//	@exception	None
//	@throw		None
//	@warning	None
//	=====================================================================
void * Frame::event_checker_no_message(void * arg)
{
	Frame* pthis = static_cast<Frame*>(arg);
	while(true)
	{
		pthis->event_handler();
	}// end while true
	return NULL;
}// end event_checker_no_message


//	=====================================================================
//	@fn			find
//	@breif		find message queue pointer with argument
//
//	@param		type	: const pointer of char
//	@param		name	: name of message queue
//
//	@return		If find success then return pointer of message queue
//				If find fail then return NULL
//
//	@exception	None
//	@throw		None
//	@warning	None
//	=====================================================================
Message * Frame::find(const char * name)
{
	Message * ret = NULL;

	std::vector<QueueInfo>::iterator iter = this->pushlst.begin();
	std::vector<QueueInfo>::iterator end = this->pushlst.end();

	for( ; iter != end; iter++)
	{
		if(strcmp(iter->name, name) == 0)
		{
			ret = iter->msg;
			return ret;
		}
	}
	return ret;
}

//	=====================================================================
//	@fn			add_lst
//	@breif		add list of QueueInfo struct
//				(pointer of message queue and name of message queue)
//
//
//	@param		type	: const reference of vector contains QueueInfo
//
//	@return		void
//
//	@exception	None
//	@throw		None
//	@warning	None
//	=====================================================================
void Frame::add_lst(const std::vector<QueueInfo> & lst)
{
	this->pushlst = lst;
}




//	=====================================================================
//	@fn			send
//	@breif		send packet to another process
//
//	@details 	to-do
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
//	@return		type	: long
//	@return		name	: error code
//
//	@exception	None
//	@throw		None
//	@warning	None
//	=====================================================================

long Frame::send(unsigned long int dest, int len, char * buff) const
{
    long ret = -3;
    if(this->process != NULL)
    {
        ret = this->process->send_pkt(dest, len, buff);
    }    	
    return ret;
}

//	=====================================================================
//	@fn			push
//	@breif		push message in the queue
//
//	@param1		type	: const pointer of char
//	@param1		name	: name of queue
//
//	@param2		type	: unsigned long int
//	@param2		name	: source address
//	@details
//				min 	: (0x01LLU << 0)
//				max 	: (0x01LLU << 63)
//
//	@param3		type	: int
//	@param3		name	: length
//
//	@param4		type : char *
//	@param4		name : buffer
//
//	@return		None
//
//	@exception	None
//	@throw		None
//	@warning	None
//	=====================================================================
void Frame::push(const char * name, unsigned long int src, int len, const char *  buff)
{
	Message * ret = this->find(name);
	if(ret != NULL)
	{
		ret->push(src, len, buff);
	}// end if
}// end push


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
const RecvMsgPkt * Frame::pop()
{
	const RecvMsgPkt * ret = this->pop_queue->pop();
	return ret;
}//end pop



//	=====================================================================
//	@fn			get_Interface
//	@breif		get pointer of Interface instance
//
//	@param		None
//
//	@return		type	: pointer of Interface instance
//
//	@exception	None
//	@throw		None
//	@warning	None
//	=====================================================================
kipc::Interface* Frame::get_Interface() const
{
	return this->process;
}

//	=====================================================================
//	@fn			run
//	@breif		to avoid unused variable
//
//	@param		None
//
//	@return		None
//
//	@exception	None
//	@throw		None
//	@warning	None
//	=====================================================================
void Frame::run(void)
{
	;
}

//	=====================================================================
//	@fn			Frame
//	@breif		Constructor for KIPC
//
//	@param		type	: const unsigned long int
//	@param		name	: process id in <linux/processid_table.h>
//
//	@return		None
//
//	@exception	None
//	@throw		None
//	@warning	None
//	=====================================================================

Frame::Frame(const unsigned long int pid)
: d_flag(true), blk(BLOCK::DISABLE), pop_queue(NULL)
{
    this->process = new kipc::Interface(pid);
    if(pthread_create(&this->thread, NULL, event_checker_kipc, this) != 0)
    {
    	fprintf(stdout,"[%s]pthread create fail\n", __func__);
    }
}

//	=====================================================================
//	@fn			Frame
//	@breif		Constructor for KIPC / push received messages in the queues
//
//	@param1		type	: const unsigned long int
//	@param1		name	: process id in <linux/processid_table.h>
//
//	@param2		type	: const reference of vector contains QueueInfo
//
//	@return		None
//
//	@exception	None
//	@throw		None
//	@warning	None
//	=====================================================================
Frame::Frame(const unsigned long int pid, const std::vector<QueueInfo> & lst)
: d_flag(true), blk(BLOCK::DISABLE), pop_queue(NULL)
{
    this->process = new kipc::Interface(pid);
    this->add_lst(lst);
    if(pthread_create(&this->thread, NULL, event_checker_kipc, this) != 0)
    {
    	fprintf(stdout,"[%s]pthread create fail\n", __func__);
    }
}


//	=====================================================================
//	@fn			Frame
//	@breif		Constructor for internal thread without IPC / without message queue
//
//	@param		None
//
//	@return		None
//
//	@exception	None
//	@throw		None
//	@warning	None
//	=====================================================================
Frame::Frame(void)
: process(NULL), d_flag(false), blk(BLOCK::DISABLE)
{
    if(pthread_create(&this->thread, NULL, event_checker_no_message, this) != 0)
    {
    	fprintf(stdout,"[%s]pthread create fail\n", __func__);
    }
}

//	=====================================================================
//	@fn			Frame
//	@breif		Constructor for internal thread without IPC / with message queue
//
//	@param1		type	: const reference of BLOCK enum class
//
//	@param2		type	: pointer of Message queue
//
//	@return		None
//
//	@exception	None
//	@throw		None
//	@warning	None
//	=====================================================================
Frame::Frame(const BLOCK::FLAG & block, Message * message)
: process(NULL), d_flag(false), blk(block), pop_queue(message)
{
    if(pthread_create(&this->thread, NULL, event_checker_message, this) != 0)
    {
    	fprintf(stdout,"[%s]pthread create fail\n", __func__);
    }
}

//	=====================================================================
//	@fn			Frame
//	@breif		Constructor for internal thread without IPC / with message queue / 
//				push received messages in the queues
//
//	@param1		type	: const reference of BLOCK enum class
//
//	@param2		type	: pointer of Message queue
//
//	@param3		type	: const reference of vector contains QueueInfo
//
//	@return		None
//
//	@exception	None
//	@throw		None
//	@warning	None
//	=====================================================================
Frame::Frame(const BLOCK::FLAG & block, Message * message, const std::vector<QueueInfo> & lst)
: d_flag(false), blk(block), pop_queue(message)
{
    this->add_lst(lst);
    if(pthread_create(&this->thread, NULL, event_checker_message, this) != 0)
    {
    	fprintf(stdout,"[%s]pthread create fail\n", __func__);
    }
}

//	=====================================================================
//	@fn			Frame
//	@breif		Constructor for internal thread with IPC / without message queue
//
//	@param1		type	: pointer of Interface
//
//	@return		None
//
//	@exception	None
//	@throw		None
//	@warning	None
//	=====================================================================
Frame::Frame(kipc::Interface * process)
: process(process), d_flag(false), pop_queue(NULL)
{
    if(pthread_create(&this->thread, NULL, event_checker_no_message, this) != 0)
    {
    	fprintf(stdout,"[%s]pthread create fail\n", __func__);
    }
}

//	=====================================================================
//	@fn			Frame
//	@breif		Constructor for internal thread with IPC / with message queue
//
//	@param1		type	: pointer of Interface
//
//	@param2		type	: const reference of BLOCK enum class
//
//	@param3		type	: pointer of Message queue
//
//	@return		None
//
//	@exception	None
//	@throw		None
//	@warning	None
//	=====================================================================
Frame::Frame(kipc::Interface * process, const BLOCK::FLAG &block, Message * message)
: process(process), d_flag(false), blk(block), pop_queue(message)
{
    if(pthread_create(&this->thread, NULL, event_checker_message, this) != 0)
    {
    	fprintf(stdout,"[%s]pthread create fail\n", __func__);
    }
}

//	=====================================================================
//	@fn			Frame
//	@breif		Constructor for internal thread with IPC / with message queue /
//				push received messages in the queues
//
//	@param1		type	: pointer of Interface
//
//	@param2		type	: const reference of BLOCK enum class
//
//	@param3		type	: pointer of Message queue
//
//	@param4		type	: const reference of vector contains QueueInfo
//
//	@return		None
//
//	@exception	None
//	@throw		None
//	@warning	None
//	=====================================================================
Frame::Frame(kipc::Interface * process, const BLOCK::FLAG & block, Message * message, const std::vector<QueueInfo> & lst)
: process(process), d_flag(false), blk(block), pop_queue(message)
{
    this->add_lst(lst);
    if(pthread_create(&this->thread, NULL, event_checker_message, this) != 0)
    {
    	fprintf(stdout,"[%s]pthread create fail\n", __func__);
    }
}

//	=====================================================================
//	@fn			~Frame
//	@breif		Destructor
//
//	@details 	It doesn't deallocate message queue
//				becuase no guarantee only one thread or process use message queue
//	@return		None
//
//	@exception	None
//	@throw		None
//	@warning	None
//	=====================================================================
Frame::~Frame()
{
    if(this->d_flag)
    {
        delete this->process;
    }
    // thread cancel, noty to nbr;
}

}//end namespace frame
