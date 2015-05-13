#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include "command.h"

void		dead_links(const char* path, const struct stat* status_buffer){
	char	*resolved_path = NULL;

	if ((status_buffer->st_mode & S_IFMT) == S_IFLNK) {
		errno = 0;
		resolved_path = realpath(path, NULL);
		if (!resolved_path) {
			if (errno == ENOENT)
				printf("Dead link at ");
			else
				print_error(path);
		}
		printf("%s\n", path);
		if (resolved_path) {
			if (run_cmd(resolved_path, &dead_links) != 0)
				print_error(path);
		}
		errno = 0;
		free(resolved_path);
	}
}
