#include "vector.h"

cl_float4 add(cl_float4 const *const restrict a,
              cl_float4 const *const restrict b) {
  return (cl_float4){{a->x + b->x, a->y + b->y, a->z + b->z, a->w + b->w}};
}
