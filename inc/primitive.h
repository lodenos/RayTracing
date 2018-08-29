#ifndef PRIMITIVE_H
#define PRIMITIVE_H

#define SPHERE 0

#include "vector.h"
#include "video.h"
#include <math.h>

typedef struct _object object_t;

#pragma pack(push, 4)

struct _object {
  colorHDR_t color;
  float distanceCamera;
  float distanceCamera2;
  float optimize;
  float radius;
  float radius2;
  uint32_t type;

  cl_float4 relativePosition;
  cl_float4 position;
};

#pragma pack(pop)

float intersection(object_t *object, cl_float4 *direction);
float sphere(object_t *object, cl_float4 *direction);

static float (*fnObject[])(object_t *object, cl_float4 *direction) = {sphere};

#endif
