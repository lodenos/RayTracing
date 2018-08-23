#include "raytracing.h"

int main(int argc, char **argv, char **envp) {
  if (command_argument(argc, argv, envp) == -1)
    return -1;
  return 0;
}
