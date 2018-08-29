#ifndef PRIMITIVE_H
#define PRIMITIVE_H

#define SPHERE 0

#include "vector.h"
#include <math.h>

typedef struct _object object_t;

#pragma pack(push, 4)

struct _object {
  float optimize;
  float distanceCamera;
  float distanceCamera2;
  cl_float4 relativePosition;
  cl_float4 position;
  float radius;
  float radius2; // this is the radius * radius for optimization
  uint32_t type;
};

#pragma pack(pop)

float intersection(object_t *object, cl_float4 *direction);
float sphere(object_t *object, cl_float4 *direction);

static float (*fnObject[])(object_t *object, cl_float4 *direction) = {sphere};
#endif
