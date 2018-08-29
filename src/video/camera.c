#include "video.h"

void camera(view_t *view) {
  for (uint32_t x = 0; x < view->height; ++x)
    for (uint32_t y = 0; y < view->width; ++y)
      view->projection[x * view->width + y] = normalize(
          &(cl_float4){{(x - view->height / 2.0f) / view->height,
                        (y - view->width / 2.0f) / view->height, 1.0f, 0.0f}});
}
