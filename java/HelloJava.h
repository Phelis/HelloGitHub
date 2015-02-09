/* DO NOT EDIT THIS FILE - it is machine generated */
#include <jni.h>
/* Header for class HelloJava */

#ifndef _Included_HelloJava
#define _Included_HelloJava
#ifdef __cplusplus
extern "C" {
#endif
/*
 * Class:     HelloJava
 * Method:    sayHello
 * Signature: ()V
 */
JNIEXPORT void JNICALL Java_HelloJava_sayHello
  (JNIEnv *, jobject);

/*
 * Class:     HelloJava
 * Method:    setGraphic
 * Signature: ()V
 */
JNIEXPORT void JNICALL Java_HelloJava_setGraphic
  (JNIEnv *, jobject);

/*
 * Class:     HelloJava
 * Method:    testNativeInteger
 * Signature: ()I
 */
JNIEXPORT jint JNICALL Java_HelloJava_testNativeInteger
  (JNIEnv *, jobject);

/*
 * Class:     HelloJava
 * Method:    testNativeIntegerWithDoubleIntArguments
 * Signature: (II)I
 */
JNIEXPORT jint JNICALL Java_HelloJava_testNativeIntegerWithDoubleIntArguments
  (JNIEnv *, jobject, jint, jint);

/*
 * Class:     HelloJava
 * Method:    testNativeString
 * Signature: ()Ljava/lang/String;
 */
JNIEXPORT jstring JNICALL Java_HelloJava_testNativeString
  (JNIEnv *, jobject);

/*
 * Class:     HelloJava
 * Method:    testNativeStringWithDoubleStringArguments
 * Signature: (Ljava/lang/String;Ljava/lang/String;)Ljava/lang/String;
 */
JNIEXPORT jstring JNICALL Java_HelloJava_testNativeStringWithDoubleStringArguments
  (JNIEnv *, jobject, jstring, jstring);

/*
 * Class:     HelloJava
 * Method:    testNativeBoolean
 * Signature: ()Z
 */
JNIEXPORT jboolean JNICALL Java_HelloJava_testNativeBoolean
  (JNIEnv *, jobject);

/*
 * Class:     HelloJava
 * Method:    testNativeBooleanWithDoubleBooleanArguments
 * Signature: (ZZ)Z
 */
JNIEXPORT jboolean JNICALL Java_HelloJava_testNativeBooleanWithDoubleBooleanArguments
  (JNIEnv *, jobject, jboolean, jboolean);

/*
 * Class:     HelloJava
 * Method:    GCD
 * Signature: (II)I
 */
JNIEXPORT jint JNICALL Java_HelloJava_GCD
  (JNIEnv *, jobject, jint, jint);

#ifdef __cplusplus
}
#endif
#endif