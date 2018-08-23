#ifndef RAYTRACING_H
#define RAYTRACING_H

#include <CL/cl.h>
#include <SDL2/SDL.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

typedef struct _env env_t;
typedef struct _object object_t;
typedef struct _window window_t;

#pragma pack(push, 4)

struct _object {
  cl_float4 position;
  float radius;
  uint32_t type;
};

#pragma pack(pop)

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

struct _env {
  window_t window;
};

void camera(cl_float4 *projection, cl_float4 direction, cl_int2 resoltion,
            float fov);
int command_argument(env_t *env, int argc, char **argv, char **envp);
int32_t detect_device_gpu(void);
int32_t event_capture(void);
void intersection_point(object_t *object, cl_float4 *origin,
                        cl_float4 *direction);
int32_t launcher_main_window(window_t *window);
void main_loop(env_t *env);

#endif
