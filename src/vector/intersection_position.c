#include "vector.h"

cl_float4 intersection_position(cl_float4 const *const restrict a,
                                cl_float4 const *const restrict b,
                                float const length) {
  return (cl_float4){{a->x + b->x * length, a->y + b->y * length,
                      a->z + b->z * length, a->w + b->w * length}};
}
