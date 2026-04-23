// A header file to describe the flags for the tools

#ifndef FLAGS_H
#define FLAGS_H

// This is a typedef structure for the flags
typedef struct {
  int help;             // -h
  int create;           // -c
  int mark_as_complete; // -x
  // int update;           // -u
  int list_tasks;  // -l
  int delete_task; // -d
} Flags;

// Function to initialize the values of the flag structure variables
void init_flags(Flags *flags);

// Function to check which flag is being used and mark there value with 1
void parse_flags(int argc, char *argv[], Flags *flags);

#endif
