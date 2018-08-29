#include "raytracing.h"

colorHDR_t ray_tracing(scene_t *scene, uint32_t index) {
  float length = 0.0f;
  float smallest = FLT_MAX;
  for (uint32_t itr = 0; itr < scene->numObject; ++itr) {
    length = intersection(&scene->object[itr], &scene->view.projection[index]);
    if (length < smallest)
      smallest = length;
  }
  if (length > 0.0f)
    return (colorHDR_t){0xFFFF, 0x00, 0x00, 0x0};
  return (colorHDR_t){0};
}
