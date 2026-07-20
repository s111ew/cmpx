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
