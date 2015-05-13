#include <time.h>
#include <stdio.h>
#include <sys/stat.h>

void		yesterday_changes(const char* path, const struct stat* status_buffer){
	time_t	curr;

	curr = time(NULL);
	if (curr != -1) {
		if (status_buffer->st_mtimespec.tv_sec > (curr - 86400)) {
			printf("%s\n", path);
		}
	}
	else
		printf("Unable to check time on: %s\n", path);
	return;
}
