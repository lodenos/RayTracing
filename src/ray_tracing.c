#include "raytracing.h"

colorHDR_t ray_tracing(scene_t *scene, uint32_t index) {
  uint32_t id = 0;
  float length = 0.0f;
  float smallest = FLT_MAX;
  for (uint32_t itr = 0; itr < scene->numObject; ++itr) {
    length = intersection(&scene->object[itr], &scene->view.origin,
                          &scene->view.projection[index]);
    if (length < smallest) {
      id = itr;
      smallest = length;
    }
  }
  if (length < 0.0f)
    return (colorHDR_t){0};
  cl_float4 position =
      intersection_position(&scene->view.origin, &scene->view.projection[index],
                            length - length / 82000.0f);
  if (shadow_mapping(scene, &position) == false)
    return (colorHDR_t){0};
  return flat_shading(scene->object, scene->light, &position);
}
