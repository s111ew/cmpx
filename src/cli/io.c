#include <linux/limits.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>

#include "err.h"
#include "io.h"

int file_read(const char *rel_path, buffer_t *buf) {
  char path[PATH_MAX];
  if (realpath(rel_path, path) == NULL) {
    printf("%s", ERR_INPUT_PATH);
    return -1;
  }

  FILE *file = fopen(path, "r");
  if (file == NULL) {
    printf("%s", ERR_INPUT_FILE);
    return -1;
  }

  struct stat file_info;
  // Using fstat and passing the file num here instead of stat and the path for
  // incase of changes to the file in between.
  if (fstat(fileno(file), &file_info) == -1) {
    printf("%s", ERR_INPUT_METADATA);
    return -1;
  }

  if (file_info.st_size < 0) {
    printf("%s", ERR_INPUT_METADATA);
    return -1;
  }

  // Assuming that each character in the file is 1 byte and that we only need a
  // buffer of size 'bytes in input file'.
  size_t size = (size_t)file_info.st_size;

  // Allocate on the heap instead of the stack incase we get a file with size
  // larger than 8MB.
  char *data = malloc(size + 1);
  if (data == NULL) {
    printf("%s", ERR_INPUT_METADATA);
    fclose(file);
    return -1;
  }

  size_t read = fread(data, 1, size, file);
  if (read != size && ferror(file)) {
    printf("%s", ERR_INPUT_FILE);
    free(data);
    fclose(file);
    return -1;
  }
  data[read] = '\0';

  if (fclose(file) == EOF) {
    printf("%s", ERR_INPUT_FILE_CLOSE);
    free(data);
    return -1;
  }

  buf->data = data;
  buf->len = read;

  return 0;
};
