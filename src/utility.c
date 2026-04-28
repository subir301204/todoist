#include "../include/utility.h"
#include "../include/flags.h"
#include "../include/task.h"
#include <stdio.h>
#include <stdlib.h>
#include <direct.h>

char file_path[512];

void usage() {
  printf("\nUSAGE: todo <necessary flags>\n");
  printf("\n----------------Available Flags----------------\n");
  printf("c\t-\tCreate new task\n");
  printf("x\t-\tMark task as complete\n");
  // printf("u\t-\tUpdate any task details\n");
  printf("d\t-\tDelete a  task\n");
  printf("h\t-\tTo get the usage message\n");
}

void implement_operations(Flags *flags) {
  if (flags->create) {
    // Adding new tasks
    add_tasks();
  } else if (flags->mark_as_complete) {
    int tempID;
    printf("\nEnter the task ID which to be completed: ");
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

void init_file_path() {
  char *home = getenv("USERPROFILE");

  if (!home) {
    fprintf(stderr, "ERROR: Cannot get USERPROFILE\n");
    return;
  }

  char dir[512];
  snprintf(dir, sizeof(dir), "%s\\AppData\\Local\\todo", home);

  mkdir(dir);

  snprintf(file_path, sizeof(file_path), "%s\\tasks.dat", dir);
}
