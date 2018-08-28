#include "vector.h"

float dot(cl_float4 *a, cl_float4 *b) {
  return a->x * b->x + a->y * b->y + a->z * b->z + a->w * b->w;
}
