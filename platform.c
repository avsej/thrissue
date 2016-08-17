#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include <pthread.h>
#include <dlfcn.h>

#include "platform.h"

void
platform_spawn_thread(platform_thread_main_func main_func)
{
    pthread_attr_t attr;
    pthread_t id;
    int ret;

    if (pthread_attr_init(&attr) != 0) {
        fprintf(stderr, "failed to create thread attribute\n");
        return;
    }
    if (pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_DETACHED) != 0) {
        fprintf(stderr, "failed to set detached state thread attribute\n");
        return;
    }

    ret = pthread_create(&id, &attr, main_func, NULL);
    printf("platform: pthread created: %d\n", ret);

    pthread_attr_destroy(&attr);
}


platform_dlhandle_t
platform_dlopen(const char *library, char **errmsg)
{
    platform_dlhandle_t handle;

    if (library == NULL) {
        handle = dlopen(NULL, RTLD_NOW | RTLD_LOCAL);
    } else {
        handle = dlopen(library, RTLD_NOW | RTLD_LOCAL);
    }

    if (handle == NULL && errmsg != NULL) {
        *errmsg = strdup(dlerror());
    }

    return handle;
}

void *
platform_dlsym(platform_dlhandle_t handle, const char *symbol, char **errmsg)
{
    void *ret = dlsym(handle, symbol);
    if (ret == NULL && errmsg) {
        *errmsg = strdup(dlerror());
    }
    return ret;
}
