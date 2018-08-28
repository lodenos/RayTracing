#include "primitive.h"

float intersection(object_t *object, cl_float4 *origin, cl_float4 *direction) {
  return fnObject[object->type](object, origin, direction);
}
