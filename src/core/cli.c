#include <stdio.h>
#include <string.h>

#include "libcmpx/cli.h"

int cmpx_cli_parse_opts(int argc, char *argv[], CmpxCliOptions *options)
{
  if (argc != 4)
  {
    return -1;
  }

  int opt_count = 4;

  for (int i = 1; i < argc; i++)
  {
    if (strncmp(argv[i], "--algorithm=", 12) == 0)
    {
        options->algorithm = argv[i] + 12;
        opt_count--;
    }

    else if (strncmp(argv[i], "--operation=", 7) == 0)
    {
        CmpxOperation *operation;
        if (cmpx_cli_parse_operation(argv[i] + 7, operation) != 0)
        {
          return -1;
        }

        options->operation = *operation;
        opt_count--;
    }

    else if (strncmp(argv[i], "--input=", 8) == 0)
    {
        options->input = argv[i] + 8;
        opt_count--;
    }

    else if (strncmp(argv[i], "--output=", 9) == 0)
    {
        options->output = argv[i] + 9;
        opt_count--;
    }
  }

  if (opt_count != 0)
  {
    return -1;
  }

  return 0;
}

int cmpx_cli_parse_operation(const char *text, CmpxOperation *operation)
{
  if (strcmp(text, "encode") == 0)
  {
    *operation = CMPX_ENCODE;
    return 0;
  }

  if (strcmp(text, "decode") == 0)
  {
    *operation = CMPX_DECODE;
    return 0;
  }

  return -1;
}

void cmpx_cli_print_usage(void)
{
  printf("usage");
}
