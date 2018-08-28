#ifndef PRIMITIVE_H
#define PRIMITIVE_H

#define SPHERE 0

#include "vector.h"

typedef struct _object object_t;

#pragma pack(push, 8)

struct _object {
  cl_float4 position;
  float radius;
  uint32_t type;
};

#pragma pack(pop)

float intersection(object_t *object, cl_float4 *origin, cl_float4 *direction);
float sphere(object_t *object, cl_float4 *origin, cl_float4 *direction);

static float (*fnObject[])(object_t *object, cl_float4 *origin,
                           cl_float4 *direction) = {sphere};
#endif
