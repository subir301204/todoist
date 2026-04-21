// src file of the task header

#include <stdio.h>
#include "../include/struct.h"
#include "../include/file.h"
#include "../include/task.h"

// Function to add task with the help of file operations functions
void add_tasks() {
  struct Task t;

  printf("Enter ID: ");
  scanf("%d", &t.id);

  printf("Enter Title: ");
  scanf("%[^\n]", t.title);

  printf("Enter description: ");
  scanf("%[^\n]", t.description);

  t.completed = 0;

  write_task(t);
  printf("\nTask added successfully!\n");
}

// Function to list all the task in the file
void list_tasks() {
  read_all_tasks();   // File operation function
}
