#include "raytracing.h"

colorHDR_t ray_tracing(scene_t *scene, uint32_t index) {
  colorHDR_t color = {0x00FF, 0x0FFF, 0xFFFF, 0xFFFF};
  float length;
  float smallest = FLT_MAX;
  for (uint32_t itr = 0; itr < scene->numObject; ++itr) {
    length = intersection_point(&scene->object[itr], &scene->view.origin,
                                &scene->view.projection[index]);
    if (length < smallest)
      smallest = length;
  }
  return color;
}
