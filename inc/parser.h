#ifndef PARSER_H
#define PARSER_H

#include "primitive.h"
#include "shader.h"
#include "video.h"

typedef struct _env env_t;
typedef struct _scene scene_t;

#pragma pack(push, 4)

struct _env {
  window_t window;
  scene_t *scene;
  uint32_t numScene;
};

struct _scene {
  light_t *light;
  object_t *object;
  uint32_t numLight;
  uint32_t numObject;
  view_t view;
};

#pragma pack(pop)

int command_argument(env_t *env, int argc, char **argv, char **envp);
int32_t load_file_ort(env_t *env, char const *pathname);

#endif
