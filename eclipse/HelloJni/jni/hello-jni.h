#include <jni.h>

#ifdef __cplusplus
extern "C" {
#endif

JNIEXPORT jstring JNICALL Java_com_example_hellojni_HelloJni_stringFromJNI(
    JNIEnv* env, jobject thiz);

#ifdef __cplusplus
}
#endif
