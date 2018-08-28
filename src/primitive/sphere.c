#include "primitive.h"

float sphere(object_t *object, cl_float4 *origin, cl_float4 *direction) {
  register float b;
  register float c;
  cl_float4 pos = sub(origin, &object->position);
  b = dot(&pos, direction);
  c = b * b - dot(&pos, &pos) - object->radius * object->radius;
  if (c < 0)
    return c;
  c = sqrtf(c);
  return (-b - c > 0.0f) ? -b - c : -b + c;
}
