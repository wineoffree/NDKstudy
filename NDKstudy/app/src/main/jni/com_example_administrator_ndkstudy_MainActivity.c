//
// Created by Administrator on 2016/7/16.
//
#include <jni.h>
#include <android/log.h>
#include <stdio.h>
#include <string.h>
#ifndef LOG_TAG
#define LOG_TAG "ANDROID_LAB"
#define LOGE(...) __android_log_print(ANDROID_LOG_ERROR, LOG_TAG, __VA_ARGS__)
#endif

/* Header for class lab_sodino_jnitest_MainActivity */

#ifndef _Included_com_example_administrator_ndkstudy_MainActivity
#define _Included_com_example_administrator_ndkstudy_MainActivity
#ifdef __cplusplus
extern "C" {
#endif
/*
 * Class: lab_sodino_jnitest_MainActivity
 * Method: getStringFromNative
 * Signature: ()Ljava/lang/String;
 */
JNIEXPORT jstring JNICALL Java_com_example_administrator_ndkstudy_MainActivity_getStringFromNative
        (JNIEnv * env, jobject jObj,jstring jstr){
     char tstr[128];
    int length=0;

    const char *str = (*env)->GetStringUTFChars(env, jstr,NULL);
    length=strlen(str);
    strcpy(tstr,str);
    //tstr=strrev(str);
    int  i=0;
    while (i<length){
        tstr[i]=str[length-i-1];
        i++;
        printf("6666");
    }
    (*env)->ReleaseStringUTFChars(env,jstr, str);
    return (*env)->NewStringUTF(env,tstr);

}


#ifdef __cplusplus
}
#endif
#endif
