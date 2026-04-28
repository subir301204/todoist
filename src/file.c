#include <stdio.h>
#include "../include/struct.h"
#include "../include/file.h"
#include "../include/utility.h"

// Function to write task to the data file
void write_task(struct Task t) {
  FILE *fp = fopen(file_path, "ab");

  if (!fp) {
    fprintf(stderr, "\nERROR: Cannot open the file...\n");
    return;
  }

  if (fwrite(&t, sizeof(struct Task), 1, fp) != 1) {
    fprintf(stderr, "\nERROR: Write operation failed!\n");
    fclose(fp);
    return;
  }

  if (fclose(fp) != 0) {
    fprintf(stderr, "\nERROR: Failed to close file properly!\n");
    return;
  }

  printf("\nNew task added!\n");
}

// Function to read all task from the data file
void read_all_tasks() {
  FILE *fp = fopen(file_path, "rb");

  if (!fp) {
    fprintf(stderr, "\nERROR: Cannot open the file...\n");
    return;
  }

  struct Task t;

  printf("\n------------------------------------\n");

  while (fread(&t, sizeof(struct Task), 1, fp)) {
    printf("ID: %d\nTitle: %s\nDescription: %s\nStatus: %s\n", t.id, t.title, t.description, t.completed ? "DONE" : "PENDING");
    printf("------------------------------------\n");
  }

  fclose(fp);
}

// Function to update task in the data file
void update_task(int id) {
  FILE *fp = fopen(file_path, "rb+");

  if (!fp) {
    fprintf(stderr, "\nERROR: Cannot open the file...\n");
    return;
  }

  struct Task t;

  while (fread(&t, sizeof(struct Task), 1, fp)) {
    if (t.id == id) {
      t.completed = 1;

      fseek(fp, -(long)sizeof(struct Task), SEEK_CUR);
      fwrite(&t, sizeof(struct Task), 1, fp);

      printf("\nTask marked as completed.\n");
      fclose(fp);
      return;
    }
  }

  printf("\nTask not found...\n");
  fclose(fp);
}

// Function to delete a specific task
// By deleting the old file and replacing it with new one
void delete_task_file(int id) {
  FILE *fp = fopen(file_path, "rb");

  char temp_path[512];
  snprintf(temp_path, sizeof(temp_path), "%s.tmp", file_path);

  FILE *temp = fopen(temp_path, "wb");

  if (!fp || !temp) {
    fprintf(stderr, "ERROR: Cannot open the file...\n");
    return;
  }

  struct Task t;
  int found = 0;

  while (fread(&t, sizeof(struct Task), 1, fp)) {
    if (t.id != id) {
      fwrite(&t, sizeof(struct Task), 1, temp);
    } else {
      found = 1;
    }
  }

  fclose(fp);
  fclose(temp);

  remove(file_path);
  rename(temp_path, file_path);

  if (found) {
    printf("\nTask deleted successfully.\n");
  } else {
    printf("\nTask not found!\n");
  }
}

// Function to check is a file empty or not
int is_file_empty(const char *file_path) {
  long size;
  FILE *fp = fopen(file_path, "rb");
  if (fp == NULL) {
    fprintf(stderr, "\nERROR: Cannot open the file...\n");
    return -1;
  }

  fseek(fp, 0, SEEK_END);
  size = ftell(fp);

  fclose(fp);

  return (size == 0);
}
