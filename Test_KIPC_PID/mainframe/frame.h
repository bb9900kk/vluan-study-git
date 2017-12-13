#ifndef KIPC_FRAME_H_
#define KIPC_FRAME_H_

//	=====================================================================
//	@file		[frame.h]
//	@breif		VW MIB3 OI KIPC
//	@author		Designed by jongho.song
//	@author		Implemented by zaezins.lee
//	@date		2016.12.20.
//	@version	0.1b : Skeleton
//	=====================================================================

#include <iostream>
#include <string>
#include <pthread.h>
#include <list>
#include <deque>
#include <vector>
#include "Interface.h"
#include "message.h"

namespace BLOCK{

enum FLAG
{
	DISABLE = 0,
	ENABLE = 1,
};

}// end namespace BLOCK


namespace frame{

//	=====================================================================
//	@struct 	<QueueInfo>	[<frame.h>]
//	=====================================================================
struct QueueInfo
{
public:
//	Attribute list
	const char * name;
	Message * msg;
//	Constructor
	QueueInfo();
	QueueInfo(const char * name, Message * msg);
};

//	=====================================================================
//	@class		<Frame>	[<frame.h>]
//	=====================================================================
class Frame
{
private:
//	Attribute list
	kipc::Interface * process;
	pthread_t thread;
	bool d_flag;
	BLOCK::FLAG blk;
	Message * pop_queue;
	std::vector<QueueInfo> pushlst;

//	Thread function list
	static void * event_checker_kipc(void * arg);
	static void * event_checker_message(void * arg);
	static void * event_checker_no_message(void * arg);

//	Pure virtual function
	virtual void event_handler( unsigned long int src = 0, unsigned  int len = 0,  char * str = NULL) = 0;

//	Function list
	Message * find(const char * name);
	void add_lst(const std::vector<QueueInfo> & lst);

public:
//	Function list
	long send(const unsigned long int pid, const int len, char * buff) const;
	void push(const char * name, const unsigned long int src, const int len, const char *  buff);
	const RecvMsgPkt * pop(void);
	kipc::Interface* get_Interface(void) const;
//	to avoid unused variable
	void run(void);

//	Constructor for KIPC
	Frame(const unsigned long int pid);
//	Constructor for KIPC / push received messages in the queues
	Frame(const unsigned long int pid, const std::vector<QueueInfo> & lst);


//	Constructor for internal thread without IPC / without message queue
	Frame(void);


//	Constructor for internal thread without IPC / with message queue
	Frame(const BLOCK::FLAG & block, Message * message);
//	Constructor for internal thread without IPC / with message queue / push received messages in the queues
	Frame(const BLOCK::FLAG & block, Message * message, const std::vector<QueueInfo> & lst);


//	Constructor for internal thread with IPC / without message queue
	Frame(kipc::Interface * process);


//	Constructor for internal thread with IPC / with message queue
	Frame(kipc::Interface * process, const BLOCK::FLAG & block, Message * message);
	
//	Constructor for internal thread with IPC / with message queue / push received messages in the queues
	Frame(kipc::Interface * process, const BLOCK::FLAG & block, Message * message, const std::vector<QueueInfo> & lst);

//	Destructor
	virtual ~Frame();
};//end Frame class

}//end namespace frame

#endif	/* KIPC_FRAME_H_ */
