#include <stdio.h>
#include <string.h>

#include "args.h"
#include "err.h"

int parse_opts(int argc, char *argv[], Options *options)
{
  int opt_count = 4;

  for (int i = 1; i < argc; i++)
  {
    if (strncmp(argv[i], "--algorithm=", 12) == 0)
    {
        options->algorithm = argv[i] + 12;
        opt_count--;
    }

    else if (strncmp(argv[i], "--operation=", 12) == 0)
    {
        Operation operation;
        
        if (parse_operation(argv[i] + 12, &operation) != 0)
        {
          return -1;
        }

        options->operation = operation;
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

int parse_operation(const char *text, Operation *operation)
{
  if (strcmp(text, "encode") == 0)
  {
    *operation = ENCODE;
    return 0;
  }

  if (strcmp(text, "decode") == 0)
  {
    *operation = DECODE;
    return 0;
  }

  printf("%sFailed to parse operation '%s'. Values are encode or decode\n", ERR_PREFIX, text);
  return -1;
}

void print_usage(void)
{
  printf("usage\n");
}
