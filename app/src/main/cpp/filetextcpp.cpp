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
using namespace std;
int coun=0;
struct Node{
    string num;
    Node *next;
};
struct Node *head= nullptr;
void insertNode(string n){
    struct Node *newNode=new Node;
    newNode->num=n;
    newNode->next=head;
    head=newNode;
}
string pickout(int c){
    int count=0;
    struct Node *temp=head;
    while(count!=c){
        count++;
        temp=temp->next;
    }
    return temp->num;
}
int count(){
    int count=0;
    struct Node *temp=head;
    while(temp!= nullptr){
        count++;
        temp=temp->next;
    }
    return count;
}
const int TABLE_SIZE = 128;
class HashNode
{
public:
    int key;
    string value;
    HashNode* next;
    HashNode(int key, string value){
        this->key = key;
        this->value = value;
        this->next = nullptr;
    }
};
class HashMap
{
public:
    HashNode** htable;
public:
    HashMap(){
        htable = new HashNode*[TABLE_SIZE];
        for (int i = 0; i < TABLE_SIZE; i++)
            htable[i] = nullptr;
    }
    ~HashMap(){
        for (int i = 0; i < TABLE_SIZE; ++i){
            HashNode* entry = htable[i];
            while (entry != nullptr){
                HashNode* prev = entry;
                entry = entry->next;
                delete prev;
            }
        }
        delete[] htable;
    }
    void Insert(int key, string value){
        int hash_val =key;
        HashNode* prev = nullptr;
        HashNode* entry = htable[hash_val];
        while (entry != nullptr){
            prev = entry;
            entry = entry->next;
        }
        entry = new HashNode(key, std::move(value));
        if (prev == nullptr){
            htable[hash_val] = entry;
        }
        else{
            prev->next = entry;
        }
    }

    void Search(int key){
        HashNode* entry = htable[key];
        if(entry!= nullptr){
            while (entry != nullptr){
                insertNode(entry->value);
                entry = entry->next;
            }
        }
        else{
            coun=0;
        }

    }
};
std::string jstring2string(JNIEnv *env, jstring jStr) {
    if (!jStr)
        return "";

    const jclass stringClass = env->GetObjectClass(jStr);
    const jmethodID getBytes = env->GetMethodID(stringClass, "getBytes", "(Ljava/lang/String;)[B");
    const jbyteArray stringJbytes = (jbyteArray) env->CallObjectMethod(jStr, getBytes, env->NewStringUTF("UTF-8"));

    size_t length = (size_t) env->GetArrayLength(stringJbytes);
    jbyte* pBytes = env->GetByteArrayElements(stringJbytes, NULL);

    std::string ret = std::string((char *)pBytes, length);
    env->ReleaseByteArrayElements(stringJbytes, pBytes, JNI_ABORT);

    env->DeleteLocalRef(stringJbytes);
    env->DeleteLocalRef(stringClass);
    return ret;
}

extern "C"
JNIEXPORT jobjectArray  JNICALL Java_com_example_passwordgenerator_cppfiletext_stringFro(JNIEnv *env, jobject instance, jint ab, jobjectArray stringArray) {
    HashMap hash;
    string sen,t, q;
    int key;
    int stringCount = env->GetArrayLength(stringArray);
    for (int i=0; i<stringCount; i++) {
        jstring string = (jstring) (env->GetObjectArrayElement(stringArray, i));
        sen=jstring2string(env,string);
        key=1;
        for(int j=0;j<sen.length();j++){
            if(sen[j]==' '){
                key++;
            }
        }

         hash.Insert(key,sen);
    }
    hash.Search((int)ab);
    coun=count();
    srand(time(NULL));
    int p=rand()%coun;
    string selected;
    selected=pickout(p);
    int c=1;
    char pw[ab];
    pw[0]=selected[0];
    for(int i=0;i<selected.length();i++){
        if(selected[i]==' '){
            pw[c]=selected[i+1];
            c++;
        }
    }
    jobjectArray joa;
    pw[ab]='\0';
    char* y= const_cast<char *>(pw);
    const char* test = y;
    jstring s[2];
    s[0] = env->NewStringUTF(test);
    s[1]=env->NewStringUTF(selected.c_str());
    jobjectArray ret;
    ret = (jobjectArray) env->NewObjectArray(2, env->FindClass("java/lang/String"), NULL);
    env->SetObjectArrayElement(ret, 0, env->NewStringUTF(test));
    env->SetObjectArrayElement(ret, 1, env->NewStringUTF(selected.c_str()));
    return ret;
}
