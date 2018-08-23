#include "raytracing.h"

void camera(cl_float4 *projection, cl_float4 direction, cl_int2 resoltion,
            float fov) {
  (void)direction;
  (void)fov;
  (void)projection;
  for (int32_t itrX = 0; itrX != resoltion.x; ++itrX)
    for (int32_t itrY = 0; itrY != resoltion.y; ++itrY)
      ;
}
