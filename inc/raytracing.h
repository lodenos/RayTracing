#ifndef RAYTRACING_H
#define RAYTRACING_H

#include <CL/cl.h>
#include <stdio.h>

int command_argument(int argc, char **argv, char **envp);
int32_t detect_device_gpu(void);

#endif
