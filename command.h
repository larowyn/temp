#ifndef COMMAND_H_INCLUDED
#define COMMAND_H_INCLUDED

#include <sys/stat.h>
#define CMDNAME_MAX 32

typedef void(*Command_function)(const char*, const struct stat*);

typedef struct {
    char                name[CMDNAME_MAX];
    Command_function    fcn;
} Command;

void yesterday_changes(const char* path, const struct stat* status_buffer);
void dead_links(const char* path, const struct stat* status_buffer);
int run_cmd(const char* path, Command_function cmd);
void help(const Command commands[], size_t nb_cmd);
void usage(const char* pgm);

#endif // COMMAND_H_INCLUDED


