#include <jni.h>
#include<iostream>
#include<string>
#include <cstdlib>
#include<ctime>
#include<cstdlib>
#include<cstring>
#include<typeinfo>
#include<cstdio>
#include <fstream>
#include <string>
using namespace std;

extern "C"
JNIEXPORT jobjectArray JNICALL Java_com_example_passwordgenerator_cppuser_stringFromUser(JNIEnv *env, jobject instance,jobjectArray stringArray) {
    int stringCount = env->GetArrayLength(stringArray);
    char p[4][100];
    jstring g;
    for (int i=0; i<stringCount; i++) {
        jstring string = (jstring) (env->GetObjectArrayElement(stringArray, i));
        const char *rawString = env->GetStringUTFChars(string, 0);
        for(int j=0;j<strlen(rawString);j++){
            p[i][j]=rawString[j];
        }
        p[i][strlen(rawString)]='\0';
    }
//----------------------------------------------
    int q= static_cast<int>(strlen(p[0]));
    char n[q];
    strcpy(n,p[0]);
    int r= static_cast<int>(strlen(p[1]));
    char m[r];
    strcpy(m,p[1]);
    int s= static_cast<int>(strlen(p[2]));
    char o[s];
    strcpy(o,p[2]);
    int t= static_cast<int>(strlen(p[3]));
    char h[t];
    strcpy(h,p[3]);
    jobjectArray ret;
    ret = (jobjectArray) env->NewObjectArray(2, env->FindClass("java/lang/String"), NULL);
    string hint;
//-----------------------------------------------
    int size[4]={q,r,s,t};
    char a[100],b[100];int c;
    srand(time(NULL));
    int ch=rand()%12;
    switch (ch){
        case 0:{
            for(int j=0;j<strlen(p[0]);j++){
                p[0][j]++;
            }
            strcpy(a,p[0]);
            a[q]='\0';
            hint="Hint:- letters in your name incremented";
            break;
        }
        case 1:{
            for(int i=0;i<r;i++){
                if(i==2 || i==5 ){
                    m[i]='@';
                }
                if(i==6 || i==7){
                    m[i]='#';
                }
            }
            strcpy(a,m);
            a[r]='\0';
            hint="Hint:- dob dd@mm@##yy + friend's name";
            break;
        }
        case 2:{
            for(int j=0;j<strlen(p[1]);j++){
                    p[1][j]++;
            }
            strcpy(a,p[2]);
            a[s]='\0';
            hint="Hint:- letters in friend's name incremented";
            break;
        }
        case 3:{
            for(int j=0;j<strlen(p[3]);j++){
                p[3][j]++;
            }
            for(int i=0;i<4;i++){
                for(int j=0;j<strlen(p[i]);j++){
                    p[i][j]++;
                }
            }
            strcpy(a,p[3]);
            a[t]='\0';
            hint="Hint:- favourite place letters incremented twice";
            break;
        }
        case 4:{
            for(int i=0;i<3;i++){
                b[i]=n[i];
            }
            b[3]='&';
            for(int j=0;j<3;j++){
                b[j+4]=o[j];
            }
            strcpy(a,b);
            a[7]='\0';
            hint="Hint:- your name + friend's name";
            break;
        }
        case 5:{
            for(int i=0;i<3;i++){
                b[i]=n[i];
            }
            b[3]='@';
            for(int j=0;j<3;j++){
                b[j+4]=h[j];
            }
            strcpy(a,b);
            a[7]='\0';
            hint="Hint:- your name + favourite place";
            break;
        }
        case 6:{
            for(int i=0;i<3;i++){
                b[i]=n[i];
            }
            b[3]='^';
            srand(time(NULL));
            int k=rand()%3;
            if(k==0){
                for(int j=0;j<2;j++){
                    b[j+4]=m[j];
                }
            }
            else if(k==1){
                for(int j=0;j<2;j++){
                    b[j+4]=m[j+3];
                }
            }
            else if(k==2){
                for(int j=0;j<2;j++){
                    b[j+4]=m[j+8];
                }
            }
            strcpy(a,b);
            a[6]='\0';
            if(k==0){
                hint="Hint:- your name + dob";
            }
            else if(k==1){
                hint="Hint:- your name + dob month";
            }
            else if(k==2){
                hint="Hint:- your name + dob yr";
            } else{
                hint="none";
            }
            break;
        }
        case 7:{
            for(int i=0;i<2;i++){
                b[i]=n[i];
            }
            b[2]='&';
            for(int j=0;j<2;j++){
                b[j+3]=o[j];
            }
            b[5]='@';
            for(int j=0;j<2;j++){
                b[j+6]=h[j];
            }
            b[8]='^';
            for(int j=0;j<2;j++){
                b[j+9]=m[j];
            }
            strcpy(a,b);
            a[11]='\0';
            hint="Hint:- your name + friend's name + favourite place + dob";
            break;
        }
        case 8:{
            for(int i=0;i<q/2;i++){
                char d=n[i];
                n[i]=n[q-i-1];
                n[q-i-1]=d;
            }
            strcpy(a,n);
            a[q]='\0';
            hint="Hint:- your name is reversed";
            break;
        }
        case 9:{
            for(int i=0;i<r;i++){
                if(i==2 || i==5 ){
                    m[i]='@';
                }
                if(i==6 || i==7){
                    m[i]='#';
                }
            }
            for(int i=0;i<r/2;i++){
                char d=m[i];
                m[i]=m[r-i-1];
                m[r-i-1]=d;
            }
            strcpy(a,m);
            a[11]='\0';
            hint="Hint:- dob yy##@mm@dd + friend's name in reverse";
            break;
        }
        case 10:{
            for(int i=0;i<s/2;i++){
                char d=o[i];
                o[i]=o[s-i-1];
                o[s-i-1]=d;
            }
            strcpy(a,o);
            a[s]='\0';
            hint="Hint:- your friend's name is reversed";
            break;
        }
        case 11: {
            for (int i = 0; i < t / 2; i++) {
                char d = h[i];
                h[i] = h[t - i - 1];
                h[t - i - 1] = d;
            }
            strcpy(a, h);
            a[t]='\0';
            hint="Hint:- favourite place is reversed";
            break;
        }
        default:{
            break;
        }
    }
    char* y= const_cast<char *>(a);
    const char* test = y;
    env->SetObjectArrayElement(ret, 0, env->NewStringUTF(test));
    env->SetObjectArrayElement(ret, 1, env->NewStringUTF(hint.c_str()));
    return ret;
}
