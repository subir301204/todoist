/*
 * This is the initial code for the program
 */

#include <stdio.h>
#include "../include/flags.h"
#include "../include/utility.h"

int main(int argc, char *argv[]) {
  Flags fg;

  init_file_path();

  if (argc == 1) {
    fprintf(stderr, "\nERROR: We need an argument to perform any operation.\n");
    return 1;
  }

  init_flags(&fg);
  parse_flags(argc, argv, &fg);

  implement_operations(&fg);

  return 0;
}
