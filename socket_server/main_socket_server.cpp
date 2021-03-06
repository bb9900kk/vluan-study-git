//============================================================================
// Name        : test_socket.cpp
// Author      : nvluan
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <sys/types.h>
#include <time.h>

int main(int argc, char *argv[])
{
    int listenfd = 0, connfd = 0;
    struct sockaddr_in serv_addr;

    char sendBuff[1025];
    time_t ticks;

    listenfd = socket(AF_INET, SOCK_STREAM, 0);
    memset(&serv_addr, '0', sizeof(serv_addr));
    memset(sendBuff, '0', sizeof(sendBuff));

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    serv_addr.sin_port = htons(5000);

    bind(listenfd, (struct sockaddr*)&serv_addr, sizeof(serv_addr));

    listen(listenfd, 10);

    char recvBuff[1025] = {0,};
    int n = 0;

    connfd = accept(listenfd, (struct sockaddr*)NULL, NULL);

    while(1)
    {


        ticks = time(NULL);
        snprintf(sendBuff, sizeof(sendBuff), "%.24s\r\n", ctime(&ticks));
        printf("\n Send time = %s", sendBuff);
        write(connfd, sendBuff, strlen(sendBuff));
        memset(sendBuff, 0x00, 1025);

        //close(connfd);
        sleep(1);

        //receive data from client

        while ( (n = read(connfd, recvBuff, sizeof(recvBuff)-1)) > 0)
	   {
		   recvBuff[n] = 0;
		   printf("\n Receive buffer = %s", recvBuff);
		 //  if(fputs(recvBuff, stdout) == EOF)
		   //{
			   printf("\n Error : Fputs error\n");
		  // }
	   }
       //usleep(100);


    }
}
