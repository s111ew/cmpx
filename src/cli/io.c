#include <linux/limits.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>

#include "buffer.h"
#include "err.h"
#include "io.h"

int file_read(const char *rel_path, buffer_t *buf) {
  char path[PATH_MAX];
  if (realpath(rel_path, path) == NULL) {
    printf("%s", ERR_INPUT_PATH);
    return -1;
  }

  FILE *file = fopen(path, "rb");
  if (file == NULL) {
    printf("%s", ERR_INPUT_FILE);
    return -1;
  }

  struct stat file_info;
  // Using fstat and passing the file num here instead of stat and the path
  // incase of changes to the file in between.
  if (fstat(fileno(file), &file_info) != 0) {
    printf("%s", ERR_INPUT_METADATA);
    return -1;
  }

  if (file_info.st_size < 0) {
    printf("%s", ERR_INPUT_METADATA);
    return -1;
  }

  size_t size = (size_t)file_info.st_size;

  // Allocate on the heap instead of the stack incase we get a file with size
  // larger than 8MB.
  if (buffer_init(buf, size) != 0) {
    printf("%s", ERR_INPUT_METADATA);
    fclose(file);
    return -1;
  }

  size_t read = fread(buf->data, 1, size, file);

  if (read != size) {
    printf("%s", ERR_INPUT_FILE);
    buffer_free(buf);
    fclose(file);
    return -1;
  }

  buf->size = read;

  if (fclose(file) == EOF) {
    printf("%s", ERR_INPUT_FILE_CLOSE);
    buffer_free(buf);
    return -1;
  }

  return 0;
};

int file_write(const char *rel_path, buffer_t *buf) {
  char path[PATH_MAX];
  if (realpath(rel_path, path) == NULL) {
    printf("%s", ERR_INPUT_PATH);
    return -1;
  }

  FILE *file = fopen(path, "wb");
  if (file == NULL) {
    printf("%s", ERR_INPUT_FILE);
    return -1;
  }

  // TODO: check behaviour of switching the two size params
  // TODO: check return value of fwrite()
  if (fwrite(buf->data, 1, buf->size, file) != 0) {
    printf("%s", ERR_INPUT_FILE);
    return -1;
  }

  if (fclose(file) == EOF) {
    printf("%s", ERR_INPUT_FILE_CLOSE);
    buffer_free(buf);
    return -1;
  }

  return 0;
};
