#include <stdio.h>
#include <stdlib.h>

#include "libcmpx/cli.h"

int main(int argc, char *argv[])
{
  CmpxCliOptions options;
  
  if (cmpx_cli_parse_opts(argc, argv, &options) != 0)
  {
    cmpx_cli_print_usage();
    return EXIT_FAILURE;
  }

  printf(
      "algorithm: %s\ninput file: %s\noutput file:%s\noperation: %d\n",
      options.algorithm,
      options.input,
      options.output,
      options.operation
  );

  return 0;
}
