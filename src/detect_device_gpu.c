#include "raytracing.h"

int32_t detect_device_gpu(void) {
  cl_uint num_platforms = 0;
  cl_platform_id *platforms = NULL;
  if (clGetPlatformIDs(0, NULL, &num_platforms) != CL_SUCCESS)
    return -1;
  if (num_platforms == 0)
    return -1;
  platforms = (cl_platform_id *)malloc(sizeof(cl_platform_id) * num_platforms);
  if (platforms == NULL)
    return -1;
  for (uint32_t itr = 1; itr <= num_platforms; ++itr)
    if (clGetPlatformIDs(itr, &platforms[itr - 1], NULL) != CL_SUCCESS)
      return -1;
  return 0;
}
