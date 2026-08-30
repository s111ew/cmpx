#pragma once

#include <stdio.h>

typedef struct {
  char *data;
  size_t size;
  size_t capacity;
} buffer_t;

int buffer_init(buffer_t *buf, size_t capacity);
void buffer_free(buffer_t *buf);
