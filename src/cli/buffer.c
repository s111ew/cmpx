#include <stdlib.h>

#include "buffer.h"

int buffer_init(buffer_t *buf, size_t capacity) {
  buf->data = NULL;
  buf->size = 0;
  buf->capacity = 0;

  if (capacity == 0) {
    return 0;
  }

  buf->data = malloc(capacity);

  if (buf->data == NULL) {
    return -1;
  }

  buf->capacity = capacity;

  return 0;
};

void buffer_free(buffer_t *buf) {
  if (buf == NULL) {
    return;
  }

  free(buf->data);

  buf->data = NULL;
  buf->size = 0;
  buf->capacity = 0;
};
