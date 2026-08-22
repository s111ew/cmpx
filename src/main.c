#include <stdio.h>
#include <stdlib.h>

#include "cli/args.h"
#include "cli/usage.h"

int main(int argc, char *argv[]) {
  options_t options;

  if (parse_options(argc, argv, &options) != 0) {
    print_usage();
    return EXIT_FAILURE;
  }

  run_algorithm(&options);
  return 0;
}
