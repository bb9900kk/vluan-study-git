#ifndef KIPC_COMMUNICATION_SERVICE_H_
#define KIPC_COMMUNICATION_SERVICE_H_

//	=====================================================================
//	@file		[CommunicationService.h]
//	@breif		VW MIB3 OI KIPC
//	@author		Designed by jongho.song
//	@author		Implemented by zaezins.lee
//	@date		2016.12.20.
//	@version	0.1b : Skeleton
//	=====================================================================

#include <cstring>
#include <processid_table.h>

namespace kipc{

//	=====================================================================
//	@struct 	<MsgPkt>	[<CommunicationService.h>]
//	=====================================================================
struct MsgPkt
{
public:
//	Attribute list
	unsigned long int src_addr;
	unsigned long int dst_addr;
	int len;
	char buf[MAX_SIZE];	
//	Constructor
	MsgPkt();
	MsgPkt(const unsigned long int src,const unsigned long int dst, const int len, char *buf);
};

//	=====================================================================
//	@class		<CommunicationService>	[<CommunicationService.h>]
//	=====================================================================
class CommunicationService
{
private:
//	Attribute list
	unsigned long int pid;
	unsigned long int array_id;

protected:
//	Attribute list
	int fd;
	MsgPkt * read_buff;

public:
//	Setter list
	void set_pid(const unsigned long int pid);
	void set_array_id(const unsigned long int aid);

//	Getter list
	unsigned long int get_pid(void) const;
	unsigned long int get_array_id(void) const;

//	Function list
	long read(unsigned long int & src, int & len, char ** buffer);
	long write(const unsigned long int dst, const int len, char * buf);

//	Constructor
	CommunicationService(void);
	CommunicationService(const unsigned long int pid, const unsigned long int arrayid);

//	Destructor
	virtual ~CommunicationService(void);
};// end CommunicationService class

}//end namespace kipc

#endif	/* KIPC_COMMUNICATION_SERVICE_H_ */
