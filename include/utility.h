#ifndef UTILITY_H
#define UTILITY_H

#include "../include/flags.h"

extern char file_path[512];

// Function to show the user manual to the user
void usage();

// Function to implement the operations according to the flags being used
void implement_operations(Flags *flags);

// Function to get the global data folder path for windows
void init_file_path();

#endif
