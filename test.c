#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

#include "wrapper.h"
#include "platform.h"

void
load_plugin(char *soname)
{
    char *error_msg;
    platform_dlhandle_t handle;
    void *symbol;
    union my_hack {
        void (*initialize)();
        void* voidptr;
    } hack;

    handle = platform_dlopen(soname, &error_msg);
    if (handle == NULL) {
        fprintf(stderr, "Failed to open library \"%s\": %s\n",
                    soname, error_msg);
        free(error_msg);
        return;
    }

    symbol = platform_dlsym(handle, "plugin_init", &error_msg);
    if (symbol == NULL) {
        fprintf(stderr, "Could not find symbol \"memcached_extensions_"
                "initialize\" in %s: %s\n", soname, error_msg);
        free(error_msg);
        return;
    }
    hack.voidptr = symbol;
    (*hack.initialize)();
}

int
main(void)
{
    printf("test: invoke wrapper function: %d\n", foobar("hello"));

    load_plugin("plugin.so");

    printf("test: sleep for 1 seconds...\n");
    sleep(1);

    printf("test: exit\n");
    return 0;
}
