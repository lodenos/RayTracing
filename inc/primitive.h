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
  float radius;
  float radius2;
  uint32_t type;
  cl_float4 position;
};

#pragma pack(pop)

float intersection(object_t const *const restrict object,
                   cl_float4 const *const restrict origin,
                   cl_float4 const *const restrict direction);
float sphere(object_t const *const restrict object,
             cl_float4 const *const restrict origin,
             cl_float4 const *const restrict direction);

static float (*fobject[])(object_t const *const restrict object,
                          cl_float4 const *const restrict origin,
                          cl_float4 const *const restrict direction) = {sphere};

#endif
