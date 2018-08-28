#include "raytracing.h"

static void just_init_local(env_t *env) {
  env->numScene = 1;
  env->scene = (scene_t *)malloc(sizeof(scene_t));
  env->scene->numObject = 1;
  env->scene->object = (object_t *)malloc(sizeof(object_t));

  env->scene->object->position = (cl_float4){{0.0f, 0.0f, 500.0f, 0.0f}};
  env->scene->object->radius = 100;
  env->scene->object->type = SPHERE;

  env->scene->view.origin = (cl_float4){{0.0f, 0.0f, 0.0f, 0.0f}};
  env->scene->view.direction = (cl_float4){{0.0f, 0.0f, 1.0f, 0.0f}};

  env->scene->view.size = 540 * 960;
  env->scene->view.projection =
      (cl_float4 *)malloc(sizeof(cl_float4) * env->scene->view.size);
}

void main_loop(env_t *env) {
  bool loop = true;
  colorHDR_t pixel;

  just_init_local(env);

  while (loop) {
    // Add function for movement camera
    // Add function for calculate trajectory
    camera(&env->scene->view);
    for (uint32_t index = 0; index != env->scene->view.size; ++index) {
      pixel = ray_tracing(env->scene, index);
      env->window.pixelsData[index] = pixel_HDR_sRGB(&pixel);
    }
    SDL_UnlockTexture(env->window.buffer);
    SDL_RenderCopy(env->window.renderer, env->window.buffer, NULL, NULL);
    SDL_RenderPresent(env->window.renderer);
  }
}
