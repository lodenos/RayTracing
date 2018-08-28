#ifndef VIDEO_H
#define VIDEO_H

#include <CL/cl.h>
#include <SDL2/SDL.h>

typedef struct _colorHDR colorHDR_t;
typedef struct _view view_t;
typedef struct _window window_t;

#pragma pack(push, 4)

struct _colorHDR {
  uint16_t red;
  uint16_t blue;
  uint16_t green;
  uint16_t alpha;
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

#pragma pack(pop)

void camera(view_t *view);
uint32_t pixel_HDR_sRGB(colorHDR_t *pixel) __attribute__((always_inline));

#endif
