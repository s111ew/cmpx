#include <stdio.h>
#include <stdlib.h>

#include "cli/args.h"
#include "cli/err.h"

int main(int argc, char *argv[]) {
  options_t opts;

  if (parse_options(argc, argv, &opts) != 0) {
    printf("%s", ERR_USAGE);
    return EXIT_FAILURE;
  }

  printf("algorithm: %d, operation: %d, input: %s, output: %s\n",
         opts.algorithm, opts.operation, opts.input, opts.output);

  return 0;
}
