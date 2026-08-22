#include <stddef.h>
#include <stdio.h>
#include <string.h>

#include "args.h"
#include "err.h"

int parse_options(int argc, char *argv[], options_t *options) {
  if (argc != 5) {
    return -1;
  }

  const char *arg_list[] = {"--algorithm", "--operation", "--input",
                            "--output"};
  options_check_t checks = {false, false, false, false};

  for (int i = 1; i < argc; i++) {
    if (strcmp(argv[i], arg_list[0]) == 0) {
      if (checks.algorithm == true) {
        return -1;
      }

      algorithm_t algorithm;

      if (parse_algorithm(argv[i] + 12, &algorithm) != 0) {
        return -1;
      }

      options->algorithm = algorithm;
      checks.algorithm = true;
    }

    else if (strcmp(argv[i], arg_list[1]) == 0) {
      if (checks.operation == true) {
        return -1;
      }

      operation_t operation;

      if (parse_operation(argv[i] + 12, &operation) != 0) {
        return -1;
      }

      options->operation = operation;
      checks.operation = true;
    }

    else if (strcmp(argv[i], arg_list[2]) == 0) {
      if (checks.input == true) {
        return -1;
      }

      options->input = argv[i] + 8;
      checks.input = true;
    }

    else if (strcmp(argv[i], arg_list[3]) == 0) {
      if (checks.output == true) {
        return -1;
      }

      options->output = argv[i] + 9;
      checks.output = true;
    }
  }

  if (checks.algorithm == false || checks.input == false ||
      checks.output == false || checks.operation == false) {
    return -1;
  }

  return 0;
}

static const size_t algo_table_len = sizeof(algo_table) / sizeof(algo_table[0]);

int parse_algorithm(const char *text, algorithm_t *algorithm) {
  for (size_t i = 0; i < algo_table_len; i++) {
    if (strcmp(algo_table[i].algo_name, text) == 0) {
      *algorithm = algo_table[i].algo;
      return 0;
    }
  }
  return -1;
}

int parse_operation(const char *text, operation_t *operation) {
  if (strcmp(text, "encode") == 0) {
    *operation = ENCODE;
    return 0;
  }

  if (strcmp(text, "decode") == 0) {
    *operation = DECODE;
    return 0;
  }

  printf("%sFailed to parse operation '%s'. Values are encode or decode\n",
         ERR_PREFIX, text);
  return -1;
}
