#ifndef UTILITY_H
#define UTILITY_H

#include "../include/flags.h"

// Function to show the user manual to the user
void usage();

// Function to implement the operations according to the flags being used
void implement_operations(Flags *flags);

// Function to get the global data folder path for windows
void get_file_path(char *file_path, size_t size);

#endif
