#include "raytracing.h"

int32_t launcher_main_window(window_t *window) {
  window->flags = SDL_WINDOW_RESIZABLE;
  window->title = strdup("RayTracing");
  window->position.x = SDL_WINDOWPOS_CENTERED;
  window->position.y = SDL_WINDOWPOS_CENTERED;
  window->height = 540;
  window->width = 960;
  window->window =
      SDL_CreateWindow(window->title, window->position.x, window->position.y,
                       window->width, window->height, window->flags);
  if (window->window == NULL)
    return -1;
  return 0;
}
