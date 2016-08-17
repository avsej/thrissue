#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include <dlfcn.h>
#include <pthread.h>

static int (*pthread_create_fptr)(pthread_t *__restrict, const pthread_attr_t *, void *(*)(void *), void *__restrict);

static void
pthread_create_once(void)
{

    pthread_create_fptr = dlsym(RTLD_NEXT, "pthread_create");
    if (pthread_create_fptr == NULL) {
        fprintf(stderr, "wrapper: Error in dlsym(RTLD_NEXT, \"pthread_create\")\n");
        abort();
    }

    printf("wrapper: this is threaded environment\n");
}

int
pthread_create(pthread_t *__restrict thread,
               const pthread_attr_t *__restrict attr, void *(*start_routine)(void *),
               void *__restrict arg)
{
    static pthread_once_t once_control = PTHREAD_ONCE_INIT;

    pthread_once(&once_control, pthread_create_once);

    return (pthread_create_fptr(thread, attr, start_routine, arg));
}

int
foobar(char *str)
{
    return strlen(str) + 42;
}
