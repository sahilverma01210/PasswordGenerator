#include <jni.h>

JNIEXPORT jstring JNICALL
Java_com_example_passwordgenerator_cppfiletext_stringFro(JNIEnv *env, jclass type, jint ab) {

    // TODO


    return (*env)->NewStringUTF(env, returnValue);
}