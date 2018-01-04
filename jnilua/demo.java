import jnilua.lua;


public class demo
{
	public static void main(String[] args) {
		lua.init();
		lua.doString("print('hello from native lua')");
		if(lua.dofile("./test.lua")){
			System.out.println("success");
			System.out.println(lua.getString("var"));
		}else{
			System.out.println("failed");
		}
	}
}
