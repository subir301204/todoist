#include <stdio.h>
#include "../include/flags.h"

void init_flags(Flags *flags) {
  flags->help = 0;
  flags->create = 0;
  flags->mark_as_complete = 0;
  flags->update = 0;
  flags->delete_task = 0;
}

int parse_flags(int argc, char **argv, Flags *flags) {
  int i, j;

  for (i = 1; i < argc; i++) {
    if (argv[i][0] != '-') {
      break;
    }

    for (j = 1; argv[i][j] != '\0'; j++) {
      switch(argv[i][j]) {
        case 'h':
          flags->help = 1;
          break;

        case 'c':
          flags->create = 1;
          break;

        case 'x':
          flags->mark_as_complete = 1;
          break;

        case 'u':
          flags->update = 1;
          break;

        case 'd':
          flags->delete_task = 1;
          break;

          default:
            printf("\nUnknown flag: -%c\n", argv[i][j]);
      }
    }
  }

  return i;
}
