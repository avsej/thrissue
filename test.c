#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

#include "platform.h"

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
    spawn_thread(start_routine);
    printf("sleep for 1 seconds...\n");
    sleep(1);

    return 0;
}
