#include "vector.h"

cl_float4 intersection_point(cl_float4 *a, cl_float4 *b, float length) {
  return (cl_float4){{a->x + b->x * length, a->y + b->y * length,
                      a->z + b->z * length, a->w + b->w * length}};
}
