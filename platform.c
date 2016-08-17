#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

#include <pthread.h>

#include "platform.h"

void
spawn_thread(platform_thread_main_func main_func)
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
    printf("pthread created: %d\n", ret);

    pthread_attr_destroy(&attr);
}
