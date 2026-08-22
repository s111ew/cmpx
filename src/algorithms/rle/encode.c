#include <stdbool.h>
#include <stddef.h>
#include <stdio.h>
#include <string.h>

#include "../../cli/io.h"
#include "encode.h"

void append_run(int count, char curr, char *output, size_t *output_pos) {
  *output_pos += snprintf(output + *output_pos, sizeof(output) - *output_pos,
                          "%c%d", count, curr);
}

int encode(char *input, char *output, RleStatus *status) {
  size_t output_pos = 0;

  for (size_t i = 0; i < strlen(input); i++) {
    if (status->first_char) {
      status->first_char = false;
      status->count = 1;
      status->curr = input[i];
    } else if (input[i] == status->curr) {
      status->count++;
    } else {
      append_run(status->count, status->curr, output, &output_pos);
      status->curr = input[i];
      status->count = 1;
    }
  }

  if (!status->first_char) {
    append_run(status->count, status->curr, output, &output_pos);
  }

  return 0;
}
