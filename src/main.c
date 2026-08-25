#include <stdlib.h>

#include "cli/buffer.h"
#include "cli/codec.h"
#include "cli/err.h"
#include "cli/io.h"
#include "cli/options.h"

int main(int argc, char *argv[]) {
  options_t opts;
  if (options_parse(argc, argv, &opts) != 0) {
    return EXIT_FAILURE;
  }

  codec_t *codec = codec_get(opts.codec);
  if (codec == NULL) {
    return EXIT_FAILURE;
  }

  buffer_t input;
  if (file_read(opts.input_file_path, &input) != 0) {
    return EXIT_FAILURE;
  }

  buffer_t output;
  if (opts.operation == OP_ENCODE) {
    if (codec->encode(&input, &output) != 0) {
      return EXIT_FAILURE;
    }
  } else {
    if (codec->decode(&input, &output) != 0) {
      return EXIT_FAILURE;
    }
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
