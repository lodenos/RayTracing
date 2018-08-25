#ifndef RAYTRACING_H
#define RAYTRACING_H

#include <CL/cl.h>
#include <SDL2/SDL.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

typedef struct _env env_t;
typedef struct _colorHDR colorHDR_t;
typedef struct _object object_t;
typedef struct _scene scene_t;
typedef struct _view view_t;
typedef struct _window window_t;

#pragma pack(push, 4)

struct _colorHDR {
  uint16_t red;
  uint16_t blue;
  uint16_t green;
  uint16_t alpha;
};

struct _object {
  cl_float4 position;
  float radius;
  uint32_t type;
};

struct _view {
  cl_float4 direction;
  cl_float4 origin;
  cl_float4 *projection;
  float fov;
  uint32_t size;
  uint32_t height;
  uint32_t width;
};

struct _scene {
  object_t *object;
  uint32_t numObject;
  view_t view;
};

struct _window {
  SDL_Texture *buffer;
  uint32_t flags;
  int32_t height;
  int32_t width;
  int pitch;
  uint32_t *pixelsData;
  cl_int2 position;
  SDL_Renderer *renderer;
  char *title;
  SDL_Window *window;
};

struct _env {
  window_t window;
  scene_t *scene;
  uint32_t numScene;
};

#pragma pack(pop)

void camera(view_t *view);
int command_argument(env_t *env, int argc, char **argv, char **envp);
int32_t detect_device_gpu(void);
int32_t event_capture(void);
float intersection_point(object_t *object, cl_float4 *origin,
                         cl_float4 *direction);
int32_t launcher_main_window(window_t *window);
void main_loop(env_t *env);
uint32_t pixel_HDR_sRGB(colorHDR_t *pixel) __attribute__((always_inline));
colorHDR_t ray_tracing(scene_t *scene, uint32_t index);

#endif
