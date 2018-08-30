#include "vector.h"

float dot(cl_float4 const *const restrict a,
          cl_float4 const *const restrict b) {
  return a->x * b->x + a->y * b->y + a->z * b->z + a->w * b->w;
}
