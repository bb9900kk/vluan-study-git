package MyTestJNIPackage;

import java.util.Arrays;

import com.google.protobuf.ByteString;

import MyTestProtobufJava.MyTestProtobufJavaMsg.SendMyDataTest;

public class Main 
{
	static 
	{
		try{
			System.out.println("Trying to load native library libMyTestNativeLib.so");
			System.loadLibrary("MyTestNativeLib");//this will load libMyTestNativeLib.so
			//System.load("/home/test/workspace/MyTestJNI_CPPNative/Debug/libMyTestNativeLib.so");
		}
		catch (UnsatisfiedLinkError e) {
		      System.err.println("Library file .so failed to load.\n" + e.toString());
		      e.printStackTrace(System.out);
		      System.exit(1);
		}
		System.out.println("Success loaded native library libMyTestNativeLib.so");
	}
		
	public static void main(String [] args)
	{
		System.out.println("-----------Test to call native method in .so library--------------");
		nativeMethods nm = new nativeMethods();
		
		System.out.println("Start call to nativeOne()");
		nm.nativeOne();
		System.out.println("Start call to nativTwo()");
		nm.nativeTwo();
		
		System.out.println("Start call to sendMessage()");
		byte[] btest = {'a','b','c','x','y','z'};
		nm.sendMessage(btest, 1, 1);
		
		byte[] vluanKeyPrivate = new byte[128];
		Arrays.fill(vluanKeyPrivate, (byte)99);
		ByteString bStr = ByteString.copyFrom(vluanKeyPrivate);
		
		//MyDataTest mdt = new MyDataTest("Nguyen Van Luan", 30, 1.23456f, 9.87654321d, vluanKeyPrivate);
		
		//ProcessMyDataTest pMDT = new ProcessMyDataTest();
		//pMDT.SendMyDataTest(mdt);
		//Convert MDT to byte stream
		
		SendMyDataTest.Builder data = SendMyDataTest.newBuilder();
		data.setName("Nguyen Van Luan");
		data.setId(30);
		data.setSalary1(1.1234567890123456789f);
		data.setSalary2(9.9876543210987654321d);
		data.setKeyPrivate(bStr);
		//Store the Serialized data(Message) into Message Queue		
		byte[]  bMsg = data.build().toByteArray();
		
		//send it to native
		nm.sendMessage(bMsg, 1, 10);
		
		
		
		
		
		
		System.out.println("----------All finished. Program on Main() JAVA exit.------------");
	}
}
