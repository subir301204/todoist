#ifndef FILE_H
#define FILE_H

#include "../include/string.h"

void write_task(struct Task t);
void read_all_tasks();
void update_task(int id);
void delete_task_file(int id);

#endif
