#include <stdbool.h>

typedef struct {
  bool codec;
  bool operation;
  bool input_file_path;
  bool output_file_path;
} options_check_t;

typedef enum { OP_ENCODE, OP_DECODE } operation_t;

typedef struct {
  const char *codec;
  operation_t operation;
  const char *input_file_path;
  const char *output_file_path;
} options_t;

int prefix_match(const char *arg, const char *prefix);

int options_parse(int argc, char **argv, options_t *opts);

int operation_parse(const char *text, operation_t *operation);
