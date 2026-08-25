#include "buffer.h"

typedef int (*fn_encode)(const buffer_t *input, const buffer_t *output);
typedef int (*fn_decode)(const buffer_t *input, const buffer_t *output);

typedef struct {
  char *name;
  fn_encode encode;
  fn_decode decode;
} codec_t;

codec_t *codec_get(const char *name);
