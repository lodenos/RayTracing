#ifndef RAYTRACING_H
#define RAYTRACING_H

#include <CL/cl.h>
#include <SDL2/SDL.h>
#include <stdbool.h>
#include <stdio.h>
#include <unistd.h>

typedef struct _window window_t;

#pragma pack(push, 4)

struct _window {
  uint32_t flags;
  int32_t height;
  int32_t width;
  cl_int2 position;
  char *title;
  SDL_Window *window;
};

#pragma pack(pop)

int command_argument(int argc, char **argv, char **envp);
int32_t detect_device_gpu(void);
int32_t event_capture(void);
int32_t launcher_main_window(void);

#endif
