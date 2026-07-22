#include <stdbool.h>

typedef enum
{
    ENCODE,
    DECODE
} Operation;

typedef struct
{
    const char *algorithm;
    const char *input;
    const char *output;
    Operation operation;
} Options;

typedef struct
{
    bool algorithm;
    bool input;
    bool output;
    bool operation;
} OptionsCheck;

int parse_opts(
    int argc,
    char *argv[],
    Options *options
);

int parse_operation(
    const char *text,
    Operation *operation
);

void print_usage(void);
