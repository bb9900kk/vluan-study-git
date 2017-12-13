package MyTestJNIPackage;

import java.util.Arrays;

public class nativeMethods {
	public native void initSaveJavaEnv();
	public native void nativeOne();
	public native void nativeTwo();
	public native int sendMessage(byte[] msg, int domaintID, int interfaceId);
	
	
	public static void getResponseFromNative(byte[] bdata, int len, int responseCode)
	{
		System.out.println("I'm a Java function: getResponseFromNative()");
		System.out.println("Get byte data length = " + len);
		System.out.println("responseCode = " + responseCode);
		//String strReceived = new String(bdata, "UTF-8");
		System.out.print("Get byte content:" +  Arrays.toString(bdata) + "= "); 
		for(int i=0; i < len; i++)
		{
			System.out.print((char)(bdata[i]));
		}
		System.out.println("");
		
	}
	
	public nativeMethods ()
	{
		System.out.println("Constructor of: nativeMethods called");
		initSaveJavaEnv(); //This is a constructor, autorun when this object created
	}

}
