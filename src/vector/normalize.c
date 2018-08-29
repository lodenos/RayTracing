#include "vector.h"

cl_float4 normalize(cl_float4 *vector) {
  register float value = 1.0f / sqrtf(dot(vector, vector));
  return (cl_float4){{vector->x * value, vector->y * value, vector->z * value,
                      vector->w * value}};
}
