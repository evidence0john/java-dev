#include "jni.h"

#define PATH_LEN 		256
#define VAR_NAME_LEN	256

#ifdef __cplusplus
	extern "C" {
#endif

//initialize lua state or reset lua state
JNIEXPORT void JNICALL Java_jnilua_lua_initx
						(JNIEnv *, jobject);
//close lua state
JNIEXPORT void JNICALL Java_jnilua_lua_closex
						(JNIEnv *, jobject);
//do lua string
JNIEXPORT void JNICALL
	Java_jnilua_lua_doStringx(JNIEnv *env,jobject obj, jstring content);

/*
//set globalString
JNIEXPORT void JNICALL Java_lua_globalString
	(JNIEnv *env, jobject obj, jstring name, jstring str);
*/

//get global variable string
JNIEXPORT jstring JNICALL Java_jnilua_lua_getStringx
						(JNIEnv *env, jobject obj, jstring name);

JNIEXPORT jboolean JNICALL Java_jnilua_lua_dofilex
	(JNIEnv *env, jobject obj, jstring filename);

#ifdef __cplusplus
	}
#endif
