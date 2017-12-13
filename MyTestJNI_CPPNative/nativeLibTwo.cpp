/*
 * Implement nativeTwo methods
 *
 */

#include <stdio.h>
#include "MyTestJNIPackage_nativeMethods.h"

JNIEXPORT void JNICALL
Java_MyTestJNIPackage_nativeMethods_nativeTwo (JNIEnv * env, jobject thisObj)
{
	printf("\n[Native CPP]Hello Java - this function is nativeTwo() run in nativeLib");
}

