#include "video.h"

uint32_t pixel_HDR_sRGB(colorHDR_t *pixel) {
  return (uint32_t)(pixel->red + 1 / 0xF00) << 24 |
         (uint32_t)(pixel->green + 1 / 0xF00) << 16 |
         (uint32_t)(pixel->blue + 1 / 0xF00) << 8 |
         (uint32_t)(pixel->alpha + 1 / 0xF00);
}
