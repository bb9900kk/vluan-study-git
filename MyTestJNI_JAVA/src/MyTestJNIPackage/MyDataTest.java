package MyTestJNIPackage;

//import java.util.Arrays;

public class MyDataTest {
	public String name;
	public int		id;
	public float salary1;
	public double salary2;
	public byte[] keyPrivate;

	public MyDataTest()
	{
		name = "";
		id = 0;
		salary1 = 0.0f;
		salary2 = 0.0d;
		keyPrivate = new byte[64]; //It will auto fill 0 for all value
		//Arrays.fill(keyPrivate, (byte)1);
		
	}
	
	public MyDataTest(String iName, int iId, float iSalary1, double iSalary2, byte[] iKeyPrivate)
	{
		name = iName;
		id = iId;
		salary1 = iSalary1;
		salary2 = iSalary2;
		keyPrivate = iKeyPrivate;
	}
}
