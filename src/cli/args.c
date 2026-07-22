#include <stdio.h>
#include <string.h>

#include "args.h"
#include "err.h"

int parse_opts(int argc, char *argv[], Options *options)
{
  if (argc != 5)
  {
    return -1;
  }

  OptionsCheck checks = {false, false, false, false};

  for (int i = 1; i < argc; i++)
  {
    if (strncmp(argv[i], "--algorithm=", 12) == 0)
    {
      if (checks.algorithm == true)
      {
        return -1;
      }
      
      options->algorithm = argv[i] + 12;
      checks.algorithm = true;
    }

    else if (strncmp(argv[i], "--operation=", 12) == 0)
    {
      if (checks.operation == true)
      {
        return -1;
      }
      
      Operation operation;
      
      if (parse_operation(argv[i] + 12, &operation) != 0)
      {
        return -1;
      }

        options->operation = operation;
        checks.operation = true;
    }

    else if (strncmp(argv[i], "--input=", 8) == 0)
    {
        if (checks.input == true)
        {
            return -1;
        }

        options->input = argv[i] + 8;
        checks.input = true;
    }

    else if (strncmp(argv[i], "--output=", 9) == 0)
    {
        if (checks.output == true)
        {
            return -1;
        }

        options->output = argv[i] + 9;
        checks.output = true;
    }
  }

  if (checks.algorithm == false || checks.input == false || checks.output == false || checks.operation == false)
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
