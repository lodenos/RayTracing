#include "primitive.h"

float sphere(object_t const *const restrict object,
             cl_float4 const *const restrict origin,
             cl_float4 const *const restrict direction) {
  cl_float4 tmp = sub(origin, &object->position);
  register float b = dot(&tmp, direction);
  register float c = b * b - (dot(&tmp, &tmp) - object->radius2);
  if (c < 0.0f)
    return c;
  c = sqrtf(c);
  return (-b - c > 0.0f) ? -b - c : -b + c;
}
