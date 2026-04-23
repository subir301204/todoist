/*
 * This is the initial code for the program
 */

#include "../include/flags.h"
#include "../include/utility.h"

int main(int argc, char *argv[]) {
  Flags fg;

  init_flags(&fg);
  parse_flags(argc, argv, &fg);

  implement_operations(&fg);

  return 0;
}
