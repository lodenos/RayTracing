#include "shader.h"

bool shadow_mapping(scene_t *scene, cl_float4 const *const restrict position) {
  cl_float4 direction = sub(position, &scene->light->position);
  direction = normalize(&direction);
  if (intersection(scene->object, position, &direction) < 0.0f)
    return false;
  return true;
}
