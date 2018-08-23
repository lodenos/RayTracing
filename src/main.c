#include "raytracing.h"

int main(int argc, char **argv, char **envp) {
  if (command_argument(argc, argv, envp) == -1)
    return -1;
  if (detect_device_gpu() == -1)
    ;
  return 0;
}
