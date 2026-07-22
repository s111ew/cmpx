#include <stdio.h>
#include <stdlib.h>

#include "cli/args.h"
#include "cli/usage.h"

int main(int argc, char *argv[])
{
  Options options;
  
  if (parse_opts(argc, argv, &options) != 0)
  {
    print_usage();
    return EXIT_FAILURE;
  }
  
  printf(
    "algorithm: %s\ninput file: %s\noutput file:%s\noperation: %d\n",
    options.algorithm,
    options.input,
    options.output,
    options.operation
  );
  
  return run_cmpx(&options);
}
