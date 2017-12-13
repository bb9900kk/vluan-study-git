#include <stdio.h>
#include <iostream>
#include <unistd.h>
//#include <string>

//using kipc
#include "frame.h"
#include "Interface.h"

using namespace std;

char input[100] = {0,};
char** recv_get;

//#if 0
int main()
{
	//char* mStr = "0x01LLU";
	unsigned int pid2 = 0L;
   cout << "I'm a Hello 1 program. \n";
   cout << "My PID = " <<  getpid()  << "\n";

   cout << "Enter pid of Hello2 program = ";
   cin >> pid2;

   //fflush(stdin);
   cout << "You input pid: " << pid2 << "\n";
   //check if pid2 exist
   cout << "Send some text you want to Hello2 (KO CO DAU CACH NHE)= ";
   cin >> input;
   //cin.getline(input,100);
   //cin.get(input,100);


   cout << "Your text input is: " << input << "\n";
   cout << "\nStart send kipc message:\n";

   kipc::Interface* serv = NULL;
   serv = new kipc::Interface(pid2);
   serv->send_pkt(pid2, 100, input);

   cout << "\n I will waitting for Hello2 program 10 second befor exit...";
   sleep(10);
   cout << "\nExit program\n";
return 0;
}
//#endif

#if 0
int main()
{
	char ** mStr = new char * [100];


	int buffer_size = 100;
   long unsigned int pid1 = 0L;
   cout << "\n I'm a Hello2 program.";
   cout << "\n My PID = " <<  getpid()  ;
   cout << "\n Hello2 will get some text from Hello1";
   cout << "\n Enter pid of Hello1 program = ";
   cin >> pid1;
   //fflush(stdin);
   cout << "You input pid: " << pid1 << "\n";
   //check if pid2 exist
   //cout << "Send some text you want to Hello2 (KO CO DAU CACH NHE)= ";
   //cin >> input;
   //cin.getline(input,100);
   //cin.get(input,100);


   //cout << "Your text input is: " << input << "\n";
   cout << "\n Starting get kipc message:";

   kipc::Interface* serv = NULL;
   serv = new kipc::Interface(pid1);
   serv->recv_pkt(pid1, buffer_size, mStr);

   cout << "Hello2 get value = " << mStr << "\n";


    cout << "\nExit program\n";
return 0;
}
#endif
