#include "primitive.h"

float sphere(object_t *object, cl_float4 *direction) {
  register float b = dot(&object->relativePosition, direction);
  register float c = b * b - object->optimize;
  if (c < 0.0f)
    return c;
  c = sqrtf(c);
  return (-b - c > 0.0f) ? -b - c : -b + c;
}
