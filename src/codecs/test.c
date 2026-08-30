#include "../buffer.h"
#include "../codec.h"
#include <stdint.h>
#include <string.h>

int test_encode(const buffer_t *input, buffer_t *output) {
  if (buffer_init(output, input->size) != 0) {
    return -1;
  }

  memcpy(output->data, input->data, input->size);
  output->size = input->size;

  return 0;
};

int test_decode(const buffer_t *input, buffer_t *output) {
  if (buffer_init(output, input->size) != 0) {
    return -1;
  }

  memcpy(input->data, output->data, input->size);
  output->size = input->size;

  return 0;
};

const codec_t test_codec = {
    .name = "test", .encode = test_encode, .decode = test_decode};
