#include <stdio.h>
#include <iostream>
#include "MyTestJNIPackage_nativeMethods.h"
#include "MyProtoJava.pb.h"

using namespace std;

static JNIEnv *JavaEnv = NULL;
static jclass callJavaClass = NULL;
static jmethodID callJavaResponseMethod = NULL;
const char* callJavaClassPath = "MyTestJNIPackage/nativeMethods"; //This is your Java package name
const char* callJavaResponseMethodName = "getResponseFromNative";

using namespace MyTestProtobufJava;

void updateResponseMassage(void* data, int msgSize, int domainId, int interfaceId);

JNIEXPORT void JNICALL
Java_MyTestJNIPackage_nativeMethods_initSaveJavaEnv (JNIEnv * env, jobject thisObj)
{
	printf("\n[Native CPP]Hello Java - this function is initSaveJavaEnv() run in nativeLib\n");
	if (JavaEnv == NULL)
	{
			JavaEnv = env;
			if (JavaEnv == NULL){
			printf("\n[Native CPP]JavEnv was null, we can't assign value for it.");
			}
	}

	if (callJavaClass == NULL)
	{
		callJavaClass = env->FindClass(callJavaClassPath); //This is your Java package name
	}

	if (callJavaResponseMethod == NULL)
	{
		callJavaResponseMethod = JavaEnv->GetStaticMethodID(callJavaClass, callJavaResponseMethodName, "([BII)V");
	}

	printf("\n[Native CPP]Exit function initSaveJavaEnv() run in nativeLib\n");

}

JNIEXPORT jint JNICALL Java_MyTestJNIPackage_nativeMethods_sendMessage
  (JNIEnv * env, jobject thisObj, jbyteArray msg, jint comandCode, jint interfaceId)
{
	printf("\n[Native CPP]Hello Java - this function is sendMessage() run in nativeLib\n");
	printf("\n[Native CPP] commandCode = %d, interfaceId = %d", comandCode, interfaceId);
	printf(" <---------------------------------------------------");

	int result = 0;

	int lenReceiv = env->GetArrayLength(msg);
	if (lenReceiv < 0)
	{
		printf("\n[Native CPP]Length byte array received < 0, so system exit.");
		return -1;

	}
	//Get byte array
	jbyte *bDataReceived = env->GetByteArrayElements(msg, 0);
	printf("\n[Native CPP] - Message received:");
	for(int i=0; i < lenReceiv; i++)
	{
		printf("%c",bDataReceived[i]);

	}
	printf("\n");


	if(comandCode == 1 && interfaceId == 1)
	{
		printf("\n[Native CPP]Process for commandCode =1 and interfaceId = 1");
		printf("\n[Native CPP]Call updateResponseMessage() to Java");
		char bDataResponse[] = {'V','I','E','T','N','A','M'};//7
		updateResponseMassage((void *)bDataResponse, 7, 1, 1);

	}


	if(comandCode == 1 && interfaceId == 10)
	{
		printf("\n[Native CPP]Trying parse from binary array above to get value:");
		SendMyDataTest smdt;
		smdt.ParseFromArray((void*)bDataReceived, lenReceiv);
		cout << "\n[Native CPP] Name = " << smdt.name() << "\n";
		cout << "\n[Native CPP] Id = " << smdt.id() << "\n";
		//cout << "\n[Native CPP] Salary1 = " << smdt.salary1() << "\n";
		printf("\n[Native CPP] Salary1 = %0.12f ", smdt.salary1());

		//cout << "\n[Native CPP] Salary2 = " << smdt.salary2() << "\n";
		printf("\n[Native CPP] Salary2 = %0.12f ", smdt.salary2());

		cout << "\n[Native CPP] Key Private = ";
		//cout << "\n[Native CPP] Key Private = " << smdt.keyprivate() << "\n";

		for(int i=0; i < smdt.keyprivate().length(); i++)
		{
			printf("0x%2d ",smdt.keyprivate()[i]);

		}
	}





	/*
	switch (comandCode)
	{
		case 0:
		{
			printf("Native processing comandCode = %d", interfaceId);
		}
			break;
		case 1:
		{
			printf("Native processing comandCode = %d", interfaceId);
		}
			break;
		default:
			break;


	}
	*/


	return result;
}


void updateResponseMassage(void* data, int msgSize, int domainId, int interfaceId)
{
	//This will call to Java function:
	//public static void getResponseFromNative(byte[] bdata, int len, int responseCode)
	printf("\n[Native CPP]Hello Java - this function is updateResponseMassage() in nativeLib call upward to Java");

	if(JavaEnv != NULL)
	{
		callJavaClass = JavaEnv->FindClass(callJavaClassPath); //Because in this don't have env, so we must store it to JavaEnv
		callJavaResponseMethod = JavaEnv->GetStaticMethodID(callJavaClass, callJavaResponseMethodName, "([BII)V");

		jbyteArray reponseMsg;
		reponseMsg = JavaEnv->NewByteArray(msgSize);
		JavaEnv->SetByteArrayRegion(reponseMsg, 0, msgSize, (jbyte*)data);
		JavaEnv->CallStaticVoidMethod(callJavaClass, callJavaResponseMethod,reponseMsg,msgSize,interfaceId);
	}
	else
	{
		printf("\n[Native CPP]JavEnv was null, please assign for it.");
	}
}

