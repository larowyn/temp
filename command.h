#ifndef COMMAND_H_INCLUDED
#define COMMAND_H_INCLUDED

#include <sys/stat.h>
#define CMDNAME_MAX 32
#define CMD_NUMBER 2
#define FOLLOW_LINK 0

typedef void(*Command_function)(const char*, const struct stat*);

typedef struct {
    char                name[CMDNAME_MAX];
    Command_function    fcn;
} Command;

void yesterday_changes(const char*, const struct stat*);
void dead_links(const char*, const struct stat*);
int run_cmd(const char*, Command_function);

#endif // COMMAND_H_INCLUDED


