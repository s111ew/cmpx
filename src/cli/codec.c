#include "codec.h"
#include <stddef.h>
#include <string.h>

codec_t *codecs[] = {};

const size_t codec_count = sizeof(codecs) / sizeof(codecs[0]);

codec_t *codec_get(const char *name) {
  for (size_t i = 0; i < codec_count; i++) {
    if (strcmp(codecs[i]->name, name) == 0) {
      return codecs[i];
    }
  }
  return NULL;
};
