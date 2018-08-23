#include "raytracing.h"

static int _event_capture(void *ptr) {
  (void)ptr;
  SDL_Event event;
  while (true) {
    SDL_WaitEvent(&event);
    switch (event.type) {
    case SDL_QUIT:
      exit(0);
    }
  }
}

int32_t event_capture(void) {
  SDL_Thread *thread;
  thread = SDL_CreateThread(_event_capture, "_event_capture", NULL);
  if (thread == NULL)
    return -1;
  return 0;
}
