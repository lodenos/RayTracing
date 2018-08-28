#include "video.h"

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
  window->renderer =
      SDL_CreateRenderer(window->window, -1, SDL_RENDERER_PRESENTVSYNC);
  window->buffer = SDL_CreateTexture(window->renderer, SDL_PIXELFORMAT_RGBA8888,
                                     SDL_TEXTUREACCESS_STREAMING, window->width,
                                     window->height);
  SDL_LockTexture(window->buffer, NULL, (void *)&window->pixelsData,
                  &window->pitch);
  bzero(window->pixelsData,
        sizeof(uint32_t) * (uint32_t)window->width * (uint32_t)window->height);
  SDL_RenderPresent(window->renderer);
  return 0;
}
