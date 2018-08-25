#include "raytracing.h"

void main_loop(env_t *env) {
  bool loop = true;
  colorHDR_t pixel;
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
