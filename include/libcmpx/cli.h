#ifndef CMPX_CLI_H
#define CMPX_CLI_H

typedef enum
{
    CMPX_ENCODE,
    CMPX_DECODE

} CmpxOperation;

typedef struct
{
    const char *algorithm;

    const char *input;

    const char *output;

    CmpxOperation operation;

} CmpxCliOptions;

int cmpx_cli_parse_opts(
    int argc,
    char *argv[],
    CmpxCliOptions *options
);

int cmpx_cli_parse_operation(
    const char *text,
    CmpxOperation *operation
);

void cmpx_cli_print_usage(void);

#endif
