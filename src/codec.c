#include <stddef.h>
#include <string.h>

#include "codec.h"
#include "codecs/test.h"
#include "err.h"

const codec_t *codecs[] = {&test_codec};

const size_t codec_count = sizeof(codecs) / sizeof(codecs[0]);

const codec_t *codec_get(const char *name) {
  for (size_t i = 0; i < codec_count; i++) {
    if (strcmp(codecs[i]->name, name) == 0) {
      return codecs[i];
    }
  }
  printf("%s %s %s\n", ERR_PREFIX, ERR_CODEC_NOT_FOUND, name);
  return NULL;
};
