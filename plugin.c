#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

#include "platform.h"

void *
start_routine(void *arg)
{
    (void)arg;

    printf("plugin: in the start_routine\n");

    return NULL;
}

void
plugin_init()
{
    platform_spawn_thread(start_routine);
}
