#include <stdlib.h>

#include "cli/err.h"
#include "cli/options.h"

int main(int argc, char *argv[]) {
  options_t opts;

  if (options_parse(argc, argv, &opts) != 0) {
    return EXIT_FAILURE;
  }

  codec_t codec;
  if (codec_get(opts.codec, &codec) != 0) {
    return EXIT_FAILURE;
  }

  buffer_t input;
  if (file_read(opts.input_file_path, &input) != 0) {
    return EXIT_FAILURE;
  }

  buffer_t output;
  if (opts.operation == ENCODE) {
    output = codec->encode(&input);
  } else {
    output = codec->decode(&input);
  }

  if (file_write(opts.output_file_path, &output) != 0) {
    buffer_free(&input);
    buffer_free(&output);
    return EXIT_FAILURE;
  }

  buffer_free(&input);
  buffer_free(&output);

  return EXIT_SUCCESS;
}
