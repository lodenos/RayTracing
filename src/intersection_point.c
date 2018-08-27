#include "raytracing.h"

static float (*fnObject[])(object_t *object, cl_float4 *origin,
                           cl_float4 *direction) = {sphere};

float intersection_point(object_t *object, cl_float4 *origin,
                         cl_float4 *direction) {
  return fnObject[object->type](object, origin, direction);
}
