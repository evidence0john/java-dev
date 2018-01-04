#include "stdio.h"
#include "stdlib.h"

#include "jni.h"

#include "lua.h"
#include "lualib.h"
#include "lauxlib.h"

#include "jnilua.h"

static lua_State *L;
static char lua_State_status = 0;
static char lua_script_path[PATH_LEN] = "";


JNIEXPORT void JNICALL Java_jnilua_lua_initx
	(JNIEnv *env,jobject obj)
{
	if(lua_State_status)
	{
		lua_close(L);
	}
	L = luaL_newstate();
	luaL_openlibs(L);
	lua_State_status = 1;
	return;
}


JNIEXPORT void JNICALL Java_jnilua_lua_closex
	(JNIEnv *env,jobject obj)
{
	if(lua_State_status)
	{
		lua_close(L);
	}
	lua_State_status = 0;
	return;
}

JNIEXPORT void JNICALL
	Java_jnilua_lua_doStringx(JNIEnv *env,jobject obj, jstring content)
{
	const jbyte *str =
		(const jbyte *)(*env)->GetStringUTFChars(env, content, JNI_FALSE);
	luaL_dostring(L, str);
	(*env)->ReleaseStringUTFChars(env, content, (const char *)str);
	return;
}

JNIEXPORT jstring JNICALL
	Java_jnilua_lua_retx(JNIEnv *env, jobject obj)
{
	jstring rtstr = (*env)->NewStringUTF(env, "hello_JNI");
	return rtstr;
}

/*
JNIEXPORT void JNICALL Java_lua_globalString
	(JNIEnv *env, jobject obj, jstring name, jstring str)
{
	unsigned char buf[VAR_NAME_LEN]; //buf "xyz="
	const jbyte *lname =
		(const jbyte *)(*env)->GetStringUTFChars(env,name, JNI_FALSE);
	const jbyte *lstr =
		(const jbyte *)(*env)->GetStringUTFChars(env,str, JNI_FALSE);
	//function struct...
	(*env)->ReleaseStringUTFChars(env, name, (const char *)lname);
	(*env)->ReleaseStringUTFChars(env, str, (const char *)lstr);
	return;
}
*/

JNIEXPORT jstring JNICALL Java_jnilua_lua_getStringx
	(JNIEnv *env, jobject obj, jstring name)
{
	const jbyte *lname =
		(const jbyte *)(*env)->GetStringUTFChars(env, name, JNI_FALSE);
	lua_getglobal(L, lname);
	(*env)->ReleaseStringUTFChars(env, name, (const char *)lname);
	return (*env)->NewStringUTF(env, (const char*)lua_tostring(L, -1));
}

JNIEXPORT jboolean JNICALL Java_jnilua_lua_dofilex
	(JNIEnv *env, jobject obj, jstring filename)
{
	const jbyte *fname =
		(const jbyte *)(*env)->GetStringUTFChars(env, filename, JNI_FALSE);
	jboolean status = luaL_dofile(L, fname);
	(*env)->ReleaseStringUTFChars(env, filename, (const char *)fname);
	return (!status);
}

