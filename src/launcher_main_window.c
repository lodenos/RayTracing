#include "raytracing.h"

int32_t launcher_main_window(void) {
  window_t win;
  win.title = strdup("RayTracing");
  win.position.x = SDL_WINDOWPOS_CENTERED;
  win.position.y = SDL_WINDOWPOS_CENTERED;
  win.height = 150;
  win.width = 300;
  win.window = SDL_CreateWindow(win.title, win.position.x, win.position.y,
                                win.width, win.height, win.flags);
  if (win.window == NULL)
    return -1;
  return 0;
}
