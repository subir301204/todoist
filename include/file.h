#ifndef FILE_H
#define FILE_H

#include "../include/string.h"

void write_task(struct Task t);
void read_all_tasks();
void update_task(int id);
void delete_task_file(int id);
int is_file_empty(const char *file_path);

#endif
