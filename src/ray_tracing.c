#include "raytracing.h"

colorHDR_t ray_tracing(scene_t *scene, uint32_t index) {
  colorHDR_t color = {0};
  float length = 0.0f;
  float smallest = FLT_MAX;
  for (uint32_t itr = 0; itr < scene->numObject; ++itr) {
    length = intersection(&scene->object[itr], &scene->view.origin,
                          &scene->view.projection[index]);
    if (length < smallest)
      smallest = length;
  }

  if (length > 0.0f)
    return (colorHDR_t){0xFFFF, 0x00, 0x00, 0xFFFF};
  return color;
}
