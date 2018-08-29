#ifndef RAYTRACING_H
#define RAYTRACING_H

#include "device.h"
#include "event.h"
#include "parser.h"
#include "primitive.h"
#include "shader.h"
#include "vector.h"
#include "video.h"

int32_t launcher_main_window(window_t *window);
void main_loop(env_t *env);
colorHDR_t ray_tracing(scene_t *scene, uint32_t index);

#endif
