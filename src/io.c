#include <linux/limits.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>

#include "buffer.h"
#include "err.h"
#include "io.h"

int file_read(const char *rel_path, buffer_t *buf) {
  FILE *file = open_file(rel_path, "rb");
  if (file == NULL) {
    printf("%s %s %s\n", ERR_PREFIX, ERR_IO_OPEN, rel_path);
    return -1;
  }

  struct stat file_info;
  // Using fstat and passing the file num here instead of stat and the path
  // incase of changes to the file in between.
  if (fstat(fileno(file), &file_info) != 0) {
    printf("%s %s %s\n", ERR_PREFIX, ERR_IO_METADATA, rel_path);
    return -1;
  }

  size_t size = (size_t)file_info.st_size;

  // Allocate on the heap instead of the stack incase we get a file with size
  // too large for the stack.
  if (buffer_init(buf, size) != 0) {
    printf("%s, %s %lu\n", ERR_PREFIX, ERR_IO_ALLOC, size);
    fclose(file);
    return -1;
  }

  size_t read = fread(buf->data, 1, size, file);

  if (read != size) {
    printf("%s %s %lu\n", ERR_PREFIX, ERR_IO_READ, size);
    fclose(file);
    return -1;
  }

  buf->size = read;

  if (fclose(file) == EOF) {
    printf("%s %s %s\n", ERR_PREFIX, ERR_IO_CLOSE, rel_path);
    return -1;
  }

  return 0;
};

int file_write(const char *rel_path, buffer_t *buf) {
  FILE *file = open_file(rel_path, "wb");
  if (file == NULL) {
    printf("%s %s %s\n", ERR_PREFIX, ERR_IO_OPEN, rel_path);
    return -1;
  }

  size_t bytes_written = fwrite(buf->data, 1, buf->size, file);

  if (bytes_written != buf->size) {
    printf("%s %s (%lu/%lu)\n", ERR_PREFIX, ERR_IO_WRITE, bytes_written,
           buf->size);
    fclose(file);
    return -1;
  }

  if (fclose(file) == EOF) {
    printf("%s %s %s\n", ERR_PREFIX, ERR_IO_CLOSE, rel_path);
    return -1;
  }

  return 0;
};

FILE *open_file(const char *rel_path, const char *modes) {
  char path[PATH_MAX];
  if (realpath(rel_path, path) == NULL) {
    printf("%s %s %s\n", ERR_PREFIX, ERR_IO_PATH, rel_path);
    return NULL;
  }

  FILE *file = fopen(path, modes);
  return file;
}
