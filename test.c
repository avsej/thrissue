#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

#include "wrapper.h"
#include "platform.h"

void *
start_routine(void *arg)
{
    (void)arg;

    printf("test: in the start_routine\n");

    return NULL;
}


int
main(void)
{
    printf("test: invoke wrapper function: %d\n", foobar("hello"));

    spawn_thread(start_routine);

    printf("test: sleep for 1 seconds...\n");
    sleep(1);

    printf("test: exit\n");
    return 0;
}
