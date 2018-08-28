#include "raytracing.h"

int command_argument(env_t *env, int argc, char **argv, char **envp) {
  (void)env;
  (void)envp;
  if (argc == 1)
    return 0;
  for (int32_t itr = 1; itr < argc; ++itr) {
    if (strcmp(argv[itr], "-f") == 0 || strcmp(argv[itr], "--file") == 0) {
      if (itr >= argc)
        return -1;
      ++itr;
    } else if (strcmp(argv[itr], "-h") == 0 ||
               strcmp(argv[itr], "--height") == 0) {
      if (itr >= argc)
        return -1;
      ++itr;
    } else if (strcmp(argv[itr], "-w") == 0 ||
               strcmp(argv[itr], "--width") == 0) {
      if (itr >= argc)
        return -1;
      ++itr;
    } else
      return -1;
  }
  return 0;
}
