#include "../include/utility.h"
#include <stdio.h>

void usage() {
  printf("\nUSAGE: todo <necessary flags>\n");
  printf("\n----------------Available Flags----------------\n");
  printf("\nc\t-\tCreate new task\n");
  printf("x\t-\tMark task as complete\n");
  printf("u\t-\tUpdate any task details\n");
  printf("d\t-\tDelete a  task\n");
  printf("todo\n-\nTo get the usage message\n");
}
