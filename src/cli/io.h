#include <stdio.h>

#include "args.h"

typedef struct {
  char *data;
  size_t len;
} buffer_t;

// Reads the contents of the input file into a buffer on the HEAP. Caller is
// responsible for freeing the buffer data.
int read_to_buffer(options_t *opts, buffer_t *buf);
