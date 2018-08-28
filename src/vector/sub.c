#include "vector.h"

cl_float4 sub(cl_float4 *a, cl_float4 *b) {
  return (cl_float4){{a->x - b->x, a->y - b->y, a->z - b->z, a->w - b->w}};
}
