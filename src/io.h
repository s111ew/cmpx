#include <stdio.h>

#include "buffer.h"

// Reads the contents of the input file into a buffer on the HEAP. Caller is
// responsible for freeing the buffer data.
int file_read(const char *rel_path, buffer_t *buf);

// Writes the contents of a buffer to the file specified by the output file
// path.
int file_write(const char *rel_path, buffer_t *buf);
