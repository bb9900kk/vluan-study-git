#ifndef KIPC_PROCESS_ID_H
#define KIPC_PROCESS_ID_H


/* process id must be bit mask */

#define LOG_KIPC 							(0x01LLU << 0)	/*	0	*/
#define NETWORK 							(0x01LLU << 1)
#define SPEECH_ASR 						(0x01LLU << 2)
#define WLAN 								(0x01LLU << 3)
#define BT 									(0x01LLU << 4)
#define LOG_MCU 							(0x01LLU << 5)	/*	5	*/
#define SPEECH_TTS 						(0x01LLU << 6)
#define DCMANAGER 							(0x01LLU << 7)
#define AUDIOMANAGEMENT 					(0x01LLU << 8)
#define PID_AUDIOMANAGEMENT 					(0x01LLU << 8)
#define WAVEPLAYER 						(0x01LLU << 9)
#define MIRRORLINK 						(0x01LLU << 10)	/*	10	*/ 
#define TUNER 								(0x01LLU << 11)
#define VKMS 								(0x01LLU << 12)
#define PROCESSMGR 						(0x01LLU << 13)
#define SWUP 								(0x01LLU << 14)
#define ONLINE_UPDATE 						(0x01LLU << 15)	/*	15	*/
#define ONL_SERVICE_MGT 					(0x01LLU << 16)
#define ONL_SERVICE_COMM 					(0x01LLU << 17)
#define ONL_SERVICE_AUTH 					(0x01LLU << 18)
#define ONL_IDENTIFICATION 				(0x01LLU << 19)
#define ONL_ROLE_RIGHT 					(0x01LLU << 20)	/*	20	*/
#define ONL_DIAG 							(0x01LLU << 21)
#define WEBAPP_MGR_MAIN 					(0x01LLU << 22)
#define WEBAPP_MGR_DOWNLOADER 			(0x01LLU << 23)
#define WEBENGINE_BROWSER_PROCESS 		(0x01LLU << 24)
#define WEBENGINE_REDERER_PROCESS 		(0x01LLU << 25)	/*	25	*/
#define WEBENGINE_GPU_PROCESS 			(0x01LLU << 26)
#define WEBENGINE_ZYGOTE_PROCESS 			(0x01LLU << 27)
#define ETHERNET 							(0x01LLU << 28)
#define BAP_CAR_FUNCTION_ADAPTOR_PROCESS	(0x01LLU << 29)
#define BAP_VIWI_CAR_SERVICE_PROCESS 		(0x01LLU << 30)	/*	30	*/
#define BAP_CAR_INTERFACE_PROCESS 		(0x01LLU << 31)
#define CARPLAY	 							(0x01LLU << 32)
#define ANDROIDAUTO						(0x01LLU << 33)
#define JSENGINE_JSWEPAPP 					(0x01LLU << 34)
#define MEDIA 								(0x01LLU << 35)	/*	35	*/
#define PID_MEDIA 								(0x01LLU << 35)	/*	35	*/
#define INTERENET_RADIO 					(0x01LLU << 36)
#define DISPLAY_MGR						(0x01LLU << 37)
#define WESTON								(0x01LLU << 38)
#define DSI_SERVICE						(0x01LLU << 39)
#define PID_DSI_SERVICE						(0x01LLU << 39)
#define TOUCH								(0x01LLU << 40)	/*	40	*/
#define CP									(0x01LLU << 41)
#define TUNER_HMI							(0x01LLU << 42)
#define MERCURY								(0x01LLU << 43)
#define TITAN								(0x01LLU << 44)
#define MERLIN								(0x01LLU << 45)	/*	45	*/
#define LOG_CPU								(0x01LLU << 46)
#define SWAP_MCU							(0x01LLU << 47)
#define SWAP_CPU							(0x01LLU << 48)
#define TEST_IFACE                          (0x01LLU << 49)
#define SDARS								(0x01LLU << 50)
/* add contents here*/


#define MAX_ID (51)	/* have to be last process id + 1*/
#define MAX_SIZE  (4096)

#define PROCESS_NUM (MAX_ID)
#define MAX_QUEUE  (PROCESS_NUM + 1)


#endif
