#ifndef PLATFORM_H
#define PLATFORM_H 1

typedef void* (*platform_thread_main_func)(void *argument);

void spawn_thread(platform_thread_main_func main_func);

#endif
