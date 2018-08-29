#ifndef SHADER_H
#define SHADER_H

#include "primitive.h"
#include "vector.h"
#include "video.h"
#include <CL/cl.h>

typedef struct _light light_t;

struct _light {
  cl_float4 position;
};

colorHDR_t flat_shading(object_t *object, light_t *light, cl_float4 *point);

#endif
