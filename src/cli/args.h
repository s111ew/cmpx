#include <stdbool.h>

typedef enum { ENCODE, DECODE } operation_t;

typedef enum { RLE } algorithm_t;

typedef struct {
  const char *algo_name;
  algorithm_t algo;
} algo_entry_t;

static const algo_entry_t algo_table[] = {{"rle", RLE}};

typedef struct {
  algorithm_t algorithm;
  operation_t operation;
  const char *input;
  const char *output;
} options_t;

typedef struct {
  bool algorithm;
  bool input;
  bool output;
  bool operation;
} options_check_t;

int parse_options(int argc, char *argv[], options_t *options);

int parse_algorithm(const char *text, algorithm_t *algorithm);

int parse_operation(const char *text, operation_t *operation);
