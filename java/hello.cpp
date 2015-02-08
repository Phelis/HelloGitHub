#include <stdio.h>
#include "HelloJava.h"

JNIEXPORT void JNICALL Java_HelloJava_sayHello
  (JNIEnv * env, jobject obj){
    printf("native hello");
}

JNIEXPORT void JNICALL Java_HelloJava_setGraphic
(JNIEnv * env, jobject obj) {
    printf("native setGraphic");
}

/*
 * Class:     HelloJava
 * Method:    testNativeInteger
 * Signature: ()I
 */
JNIEXPORT jint JNICALL Java_HelloJava_testNativeInteger
(JNIEnv * env, jobject obj) {
    printf("testNativeInteger \n");
    
    __int32_t num;
    num = 1;
    
    return num;
}

/*
 * Class:     HelloJava
 * Method:    testNativeIntegerWithDoubleIntArguments
 * Signature: (II)I
 */
JNIEXPORT jint JNICALL Java_HelloJava_testNativeIntegerWithDoubleIntArguments
(JNIEnv * env, jobject obj, jint num1, jint num2) {
    printf("testNativeIntegerWithDoubleIntArguments: num1 %d, num2 %d \n", num1, num2);
    jint total = 0;
    total = num1 + num2;
    return total;
}

/*
 * Class:     HelloJava
 * Method:    testNativeString
 * Signature: ()Ljava/lang/String;
 */
JNIEXPORT jstring JNICALL Java_HelloJava_testNativeString
(JNIEnv * env, jobject obj) {
    printf("testNativeString \n");
    jstring str;
    const char * c_string;
    // the different env struture defined in jni.h
    str = env->NewStringUTF(c_string);
    return str;
}

/*
 * Class:     HelloJava
 * Method:    testNativeStringWithDoubleStringArguments
 * Signature: (Ljava/lang/String;Ljava/lang/String;)Ljava/lang/String;
 */
JNIEXPORT jstring JNICALL Java_HelloJava_testNativeStringWithDoubleStringArguments
(JNIEnv * env, jobject obj, jstring str1, jstring str2) {
    printf("testNativeStringWithDoubleStringArguments \n");
    const char * c_str_1 = NULL;
    c_str_1 = env->GetStringUTFChars(str1, NULL);
    
    const char * c_str_2;
    c_str_2 = env->GetStringUTFChars(str2, NULL);
    printf("testNativeStringWithDoubleStringArguments str_1: %s, str_2: %s \n",
           c_str_1, c_str_2);
    
    jstring java_str_ok = NULL;
    java_str_ok = env->NewStringUTF("OK");
    return java_str_ok;
}

/*
 * Class:     HelloJava
 * Method:    testNativeBoolean
 * Signature: ()Z
 */
JNIEXPORT jboolean JNICALL Java_HelloJava_testNativeBoolean
(JNIEnv * env, jobject obj) {
    printf("testNativeBoolean \n");
    jboolean c_bool;
    c_bool = true;
    return c_bool;
}

/*
 * Class:     HelloJava
 * Method:    testNativeBooleanWithDoubleBooleanArguments
 * Signature: (ZZ)Z
 */
JNIEXPORT jboolean JNICALL Java_HelloJava_testNativeBooleanWithDoubleBooleanArguments
(JNIEnv * env, jobject obj, jboolean bool1, jboolean bool2) {
    printf("testNativeBooleanWithDoubleBooleanArguments \n");
    printf("boolean 1: %d \n", bool1);
    printf("boolean 2: %d \n", bool2);
    jboolean bool3;
    bool3 = bool1 | bool2;
    return bool3;
}
