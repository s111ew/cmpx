#include <stdio.h>
#include <string.h>

#include "err.h"
#include "options.h"

int parse_options(int argc, char *argv[], options_t *opts) {
  const char *expected_args[] = {
      "--codec=", "--operation=", "--input=", "--output="};

  int expected_count = sizeof expected_args / sizeof expected_args[0];
  int provided_count = argc - 1;
  if (provided_count != expected_count) {
    printf(ERR_ARG_COUNT, provided_count);
    return -1;
  }

  options_check_t checks = {.codec = false,
                            .operation = false,
                            .input_file_path = false,
                            .output_file_path = false};

  for (int i = 1; i < argc; i++) {
    if (prefix_match(argv[i], expected_args[0]) == 0) {
      if (checks.codec) {
        printf(ERR_ARG_DUPLICATE, "codec");
        return -1;
      }

      opts->codec = argv[i] + strlen(expected_args[0]);
      checks.codec = true;
    }

    else if (prefix_match(argv[i], expected_args[1]) == 0) {
      if (checks.operation) {
        printf(ERR_ARG_DUPLICATE, "operation");
        return -1;
      }

      operation_t operation;

      if (parse_operation(argv[i] + strlen(expected_args[1]), &operation) !=
          0) {
        return -1;
      }

      opts->operation = operation;
      checks.operation = true;
    }

    else if (prefix_match(argv[i], expected_args[2]) == 0) {
      if (checks.input_file_path) {
        printf(ERR_ARG_DUPLICATE, "input");
        return -1;
      }

      opts->input_file_path = argv[i] + strlen(expected_args[2]);
      checks.input_file_path = true;
    }

    else if (prefix_match(argv[i], expected_args[3]) == 0) {
      if (checks.output_file_path) {
        printf(ERR_ARG_DUPLICATE, "output");
        return -1;
      }

      opts->output_file_path = argv[i] + strlen(expected_args[3]);
      checks.output_file_path = true;
    }

    else {
      // Create Error macro
      printf("arg %s not recognised", argv[i]);
      return -1;
    }
  }

  if (!checks.codec || !checks.input_file_path || !checks.output_file_path ||
      !checks.operation) {
    printf("%s", ERR_ARG_NOT_FOUND);
    return -1;
  }

  return 0;
}

int prefix_match(const char *arg, const char *prefix) {
  return strncmp(arg, prefix, strlen(prefix));
}

int parse_operation(const char *text, operation_t *operation) {
  if (strcmp(text, "encode") == 0) {
    *operation = OP_ENCODE;
    return 0;
  }

  if (strcmp(text, "decode") == 0) {
    *operation = OP_DECODE;
    return 0;
  }

  printf(ERR_ARG_VALUE, "operation", text);
  return -1;
}
