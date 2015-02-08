import java.io.*;

class HelloJava {
	static {
		System.loadLibrary("hello");
	}

	public static void main(String[] args) throws IOException {
		System.out.println ("hello java");
                // setGraphic();

		new HelloJava().testNativeInteger();
        new HelloJava().testNativeIntegerWithDoubleIntArguments(1, 255);
        new HelloJava().testNativeString();
        new HelloJava().testNativeStringWithDoubleStringArguments("number 1", "number 2");
        new HelloJava().testNativeBoolean();
        new HelloJava().testNativeBooleanWithDoubleBooleanArguments(true, false);
	}

	private native void sayHello();
        private native void setGraphic();
	
	//  
	private native int testNativeInteger();
	private native int testNativeIntegerWithDoubleIntArguments(int num1, int num2);
	private native String testNativeString();
	private native String testNativeStringWithDoubleStringArguments(String str1, String str2);
	private native boolean testNativeBoolean();	
	private native boolean testNativeBooleanWithDoubleBooleanArguments(boolean bool1, boolean bool2);
}
