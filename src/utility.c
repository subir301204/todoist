#include "../include/utility.h"
#include "../include/flags.h"
#include "../include/task.h"
#include <stdio.h>

void usage() {
  printf("\nUSAGE: todo <necessary flags>\n");
  printf("\n----------------Available Flags----------------\n");
  printf("\nc\t-\tCreate new task\n");
  printf("x\t-\tMark task as complete\n");
  // printf("u\t-\tUpdate any task details\n");
  printf("d\t-\tDelete a  task\n");
  printf("todo\n-\nTo get the usage message\n");
}

void implement_operations(Flags *flags) {
  if (flags->create) {
    // Adding new tasks
    add_tasks();
  } else if (flags->mark_as_complete) {
    int tempID;
    printf("\nEnter the task ID which to be deleted: ");
    scanf("%d", &tempID);

    mark_complete(tempID);
  } else if (flags->list_tasks) {
    list_tasks();
  } else if (flags->delete_task) {
    int tempID;
    printf("\nEnter the task ID which have to be deleted: ");
    scanf("%d", &tempID);
    delete_task(tempID);
  } else if (flags->help) {
    usage();
  }
}
