#include "raytracing.h"

int main(int argc, char **argv, char **envp) {
  if (command_argument(argc, argv, envp) == -1)
    return -1;
  if (detect_device_gpu() == -1)
    return -1;
  if (SDL_Init(SDL_INIT_EVERYTHING))
    return -1;

  launcher_main_window();

  SDL_Quit();
  return 0;
}
