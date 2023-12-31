//
// Created by 曹璐韬 on 2023/10/8.
//

#ifndef OPENGLES3_0_LOG_UTILS_H
#define OPENGLES3_0_LOG_UTILS_H

#include "android/log.h"
#include "sys/time.h"

#define LOG_TAG "lucas-native-log"
#define LOGI(...)  __android_log_print(ANDROID_LOG_INFO, LOG_TAG, __VA_ARGS__)
#define LOGE(...)  __android_log_print(ANDROID_LOG_ERROR, LOG_TAG, __VA_ARGS__)
#define LOGD(...)  __android_log_print(ANDROID_LOG_DEBUG, LOG_TAG, __VA_ARGS__)
#define LOGW(...)  __android_log_print(ANDROID_LOG_WARN, LOG_TAG, __VA_ARGS__)
#define LOGV(...)  __android_log_print(ANDROID_LOG_VERBOSE, LOG_TAG, __VA_ARGS__)


#define FUN_BEGIN_TIME(FUN) {\
    LOGE("%s:%s func start", __FILE__, FUN); \
    long long t0 = GetSysCurrentTime();

#define FUN_END_TIME(FUN) \
    long long t1 = GetSysCurrentTime(); \
    LOGE("%s:%s func cost time %ldms", __FILE__, FUN, (long)(t1-t0));}

#define BEGIN_TIME(FUN) {\
    LOGE("%s func start", FUN); \
    long long t0 = GetSysCurrentTime();

#define END_TIME(FUN) \
    long long t1 = GetSysCurrentTime(); \
    LOGE("%s func cost time %ldms", FUN, (long)(t1-t0));}

static long long GetSysCurrentTime() {
  struct timeval time;
  gettimeofday(&time, NULL);
  long long curTime = ((long long) (time.tv_sec)) * 1000 + time.tv_usec / 1000;
  return curTime;
}

#define GO_CHECK_GL_ERROR(...) \
LOGE("CHECK_GL_ERROR %s glGetError = %d, line = %d, ",  __FUNCTION__, glGetError(), __LINE__)

#endif //OPENGLES3_0_LOG_UTILS_H
