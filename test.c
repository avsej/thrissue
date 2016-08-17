#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

#include <dlfcn.h>
#include <pthread.h>

void *
start_routine(void *arg)
{
    (void)arg;

    printf("in the start_routine\n");

    return NULL;
}


int
main(void)
{
    pthread_attr_t attr;
    pthread_t id;
    int ret;

    if (pthread_attr_init(&attr) != 0) {
        return EXIT_FAILURE;
    }
    if (pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_DETACHED) != 0) {
        return EXIT_FAILURE;
    }

    ret = pthread_create(&id, &attr, start_routine, NULL);
    pthread_attr_destroy(&attr);
    printf("pthread created: %d\n", ret);

    return 0;
}
