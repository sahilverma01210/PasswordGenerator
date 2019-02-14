#include <jni.h>
#include<iostream>
#include<string>
#include <stdlib.h>
#include<ctime>
#include<cstdlib>
#include<cstring>
#include<typeinfo>
#include<cstdio>
#include <fstream>
#include <string>
using namespace std;

extern "C"
JNIEXPORT jstring JNICALL Java_com_example_passwordgenerator_cpprandom_stringFrom(JNIEnv *env, jobject instance,jint ab) {
    char all[]="012@#*cdeYZa+?<{[ABpqrsCDEF345]}>)GHIJKL789MNOPQR$%^&STUVWXbvwx(_fghijklm6!notuyz";
    int len=81,p;
    char k[ab];
    srand(time(NULL));
    p=rand()%len;
    for(jint i=0;i<ab;i++){
        p=rand()%len;
        k[i]=all[p];
    }
    k[ab]='\0';
    char* y= const_cast<char *>(k);
    const char* test = y;
    jstring s;
    s = env->NewStringUTF(test);
    return s;
}

