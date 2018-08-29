#include "raytracing.h"

colorHDR_t ray_tracing(scene_t *scene, uint32_t index) {
  float length = 0.0f;
  float smallest = FLT_MAX;
  for (uint32_t itr = 0; itr < scene->numObject; ++itr) {
    length = intersection(&scene->object[itr], &scene->view.projection[index]);
    if (length < smallest)
      smallest = length;
  }
  cl_float4 point = intersection_point(&scene->view.origin,
                                       &scene->view.projection[index], length);

  cl_float4 tmp;

  tmp = sub(&point, &scene->light->position);
  tmp = normalize(&tmp);

  if (intersection(&scene->object[0], &tmp) > 0.0f)
    return (colorHDR_t){0, 0xFF, 0, 0};

  if (length > 0.0f)
    return flat_shading(scene->object, scene->light, &point);
  return (colorHDR_t){0};
}
