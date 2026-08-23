#include <stdbool.h>
#include <stdio.h>
#include <string.h>

#include "args.h"
#include "err.h"

int parse_options(int argc, char *argv[], options_t *opts) {
  if (argc != 5) {
    printf(ERR_ARG_NUM, argc - 1);
    return -1;
  }

  const char *arg_list[] = {
      "--algorithm=", "--operation=", "--input=", "--output="};
  options_check_t checks = {false, false, false, false};

  for (int i = 1; i < argc; i++) {
    if (strncmp(argv[i], arg_list[0], strlen(arg_list[0])) == 0) {
      if (checks.algorithm == true) {
        printf("%s", ERR_ARG_ALG_DUP);
        return -1;
      }

      algorithm_t algorithm;

      if (parse_algorithm(argv[i] + 12, &algorithm) != 0) {
        return -1;
      }

      opts->algorithm = algorithm;
      checks.algorithm = true;
    }

    else if (strncmp(argv[i], arg_list[1], strlen(arg_list[1])) == 0) {
      if (checks.operation == true) {
        printf("%s", ERR_ARG_OPE_DUP);
        return -1;
      }

      operation_t operation;

      if (parse_operation(argv[i] + strlen(arg_list[1]), &operation) != 0) {
        return -1;
      }

      opts->operation = operation;
      checks.operation = true;
    }

    else if (strncmp(argv[i], arg_list[2], strlen(arg_list[2])) == 0) {
      if (checks.input == true) {
        printf("%s", ERR_ARG_INP_DUP);
        return -1;
      }

      opts->input = argv[i] + strlen(arg_list[2]);
      checks.input = true;
    }

    else if (strncmp(argv[i], arg_list[3], strlen(arg_list[3])) == 0) {
      if (checks.output == true) {
        printf("%s", ERR_ARG_OUT_DUP);
        return -1;
      }

      opts->output = argv[i] + strlen(arg_list[3]);
      checks.output = true;
    }
  }

  if (checks.algorithm == false || checks.input == false ||
      checks.output == false || checks.operation == false) {
    printf("%s", ERR_ARG_NOT_FOUND);
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
  printf(ERR_ARG_ALG, text);
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

  printf(ERR_ARG_OPE, text);
  return -1;
}
