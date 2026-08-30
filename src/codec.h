#pragma once

#include "buffer.h"

typedef int (*fn_encode)(const buffer_t *input, buffer_t *output);
typedef int (*fn_decode)(const buffer_t *input, buffer_t *output);

typedef struct {
  char *name;
  fn_encode encode;
  fn_decode decode;
} codec_t;

extern const codec_t *codec_get(const char *name);
