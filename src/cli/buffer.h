#include <stdio.h>

typedef struct {
  char *data;
  size_t len;
} buffer_t;

void buffer_free(buffer_t *buf);
