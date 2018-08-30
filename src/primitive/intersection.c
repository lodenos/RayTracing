#include "primitive.h"

float intersection(object_t const *const restrict object,
                   cl_float4 const *const restrict origin,
                   cl_float4 const *const restrict direction) {
  return fobject[object->type](object, origin, direction);
}
