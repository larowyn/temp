#include <dirent.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <errno.h>
#include "command.h"

void				print_error(const char *path) {
	if (path)
		printf("path: %s - error: %s\n", path, strerror(errno));
	else
		printf("error: %s\n", strerror(errno));
}

char				*cat_path(const char *s1, const char *s2) {
	int				path_len, len, add_slash;
	char			*res;

	path_len = strlen(s1);
	add_slash = (s1[path_len - 1] != '/') ? 1 : 0;
	len = strlen(s1) + add_slash + strlen(s2) + 1;
	res = (char *)calloc(len, sizeof(char));
	if (res) {
		res[0] = '\0';
		strcat(res, s1);
		if (add_slash)
			strcat(res, "/");
		strcat(res, s2);
		res[len - 1] = '\0';
	}
	return (res);
}

int					run_cmd(const char* path, Command_function cmd){
	DIR				*dir;
	struct dirent	*file;
	struct stat		stat;
	char			*new_path;

	dir = opendir(path);
	if (dir == NULL) {
		return (errno);
	} else {
		errno = 0;
		while ((file = readdir(dir)) && errno == 0) {
			// TODO: remove first condition
			if (file->d_name[0] != '.'
				&& (strcmp(file->d_name, ".") != 0
				&& strcmp(file->d_name, "..") != 0)) {
				if ((new_path = cat_path(path, file->d_name)) != NULL) {
				// stat and run cmd
					if (lstat(new_path, &stat) == -1)
						print_error(new_path);
					else
						cmd(new_path, &stat);

					if (file->d_type == DT_DIR) {
						if (run_cmd(new_path, cmd) != 0)
							print_error(new_path);
					}
				}
				else {
					print_error(NULL);
				}
				free(new_path);
				new_path = NULL;
			}
			errno = 0;
		}
		closedir(dir);
		if (errno != 0)
			return (errno);
	}
	return (0);
}
