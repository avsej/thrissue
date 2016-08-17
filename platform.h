#ifndef PLATFORM_H
#define PLATFORM_H 1

typedef void* (*platform_thread_main_func)(void *argument);
typedef void *platform_dlhandle_t;

void platform_spawn_thread(platform_thread_main_func main_func);
platform_dlhandle_t platform_dlopen(const char *library, char **errmsg);
void *platform_dlsym(platform_dlhandle_t handle, const char *symbol, char **errmsg);

#endif
