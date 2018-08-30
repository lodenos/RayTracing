#ifndef SHADER_H
#define SHADER_H

#include "parser.h"
#include "primitive.h"
#include "stdbool.h"
#include "vector.h"
#include "video.h"
#include <CL/cl.h>

typedef struct _light light_t;
typedef struct _scene scene_t;

struct _light {
  cl_float4 position;
};

colorHDR_t flat_shading(object_t *object, light_t *light, cl_float4 *point);
bool shadow_mapping(scene_t *scene, cl_float4 const *const restrict position);

#endif
