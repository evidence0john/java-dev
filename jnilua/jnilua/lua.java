package jnilua;

import java.util.*;

public class lua{
	static
	{
		try{
			System.loadLibrary("jnilua");
		}catch(Exception e){
            e.printStackTrace();
        }
	}
	public native void initx();
	public native void closex();
	public native void doStringx(String content); 
	public native String getStringx(String name);
	public native boolean dofilex(String filename);
	//this function don't have native implemention now
	//public native void globalString(String name, String content);
	//public native void localStringx(String name, String var);
	public static void init(){
		new lua().initx();
		return;
	}
	public static void close(){
		new lua().closex();
		return;
	}
	public static void doString(String content){
		new lua().doStringx(content);
		return;
	}
	public static String getString(String name){
		return new lua().getStringx(name);
	}
	public static boolean dofile(String filename){
		return new lua().dofilex(filename);
	}
}
