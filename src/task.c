// src file of the task header

#include <stdio.h>
#include "../include/struct.h"
#include "../include/file.h"
#include "../include/task.h"

// Function to add task with the help of file operations functions
void add_tasks() {
  struct Task t;
  int i;

  printf("Enter ID: ");
  scanf("%d", &t.id);
  getchar();

  printf("Enter Title: ");
  fgets(t.title, sizeof(t.title), stdin);

  printf("Enter description: ");
  fgets(t.description, sizeof(t.description), stdin);

  // Remove the extra \n
  for (i = 0; t.title[i] != '\0'; i++) {
    if (t.title[i] == '\n') {
      t.title[i] = '\0';
      break;
    }
  }

  for (i = 0; t.description[i] != '\0'; i++) {
    if (t.description[i] == '\n') {
      t.description[i] = '\0';
      break;
    }
  }

  t.completed = 0;

  write_task(t);
  printf("\nTask added successfully!\n");
}

// Function to list all the task in the file
void list_tasks() {
  read_all_tasks();   // File operation function
}

// Function to mark a task as complete
void mark_complete(int id) {
  update_task(id);
}

// Function to delete a task from the data file
void delete_task(int id) {
  delete_task_file(id);
}
