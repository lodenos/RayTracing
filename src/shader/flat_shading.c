#include "shader.h"

colorHDR_t flat_shading(object_t *object, light_t *light, cl_float4 *point) {
  cl_float4 tmp = sub(point, &object->position);
  cl_float4 normal = normalize(&tmp);
  tmp = sub(point, &light->position);
  tmp = normalize(&tmp);
  float intensity = -dot(&tmp, &normal);

  return (colorHDR_t){(uint16_t)((float)object->color.red * intensity),
                      (uint16_t)((float)object->color.green * intensity),
                      (uint16_t)((float)object->color.blue * intensity), 0};
}
