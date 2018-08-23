#include "raytracing.h"

int main(int argc, char **argv, char **envp) {
  env_t env;
  if (command_argument(&env, argc, argv, envp) == -1)
    return -1;
  if (detect_device_gpu() == -1)
    return -1;
  if (SDL_Init(SDL_INIT_EVERYTHING))
    return -1;
  if (launcher_main_window(&env.window) == -1)
    return -1;
  if (event_capture() == -1)
    return -1;
  main_loop(&env);
  SDL_Quit();
  return 0;
}
