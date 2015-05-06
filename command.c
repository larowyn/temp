#include <dirent.h>
#include <stdio.h>
#include "command.h"

int					run_cmd(const char* path, Command_function cmd){
	DIR				*dir;
	struct dirent	*file;
	char			*new_path;

	dir = opendir(path);
	file = readdir(dir);
	while ((file = readdir(dir))) {
		// stat and run cmd
		// DEBUG
		printf("%s %s", path, file->d_name);

		if (file->d_type == DT_DIR) {
			int		path_len;
			int		add_slash;

			path_len = strlen(path);
			add_slash = (path[path_len - 1] != '/') ? 1 : 0;
			len = strlen(path) + add_slash + file->d_namlen + 1;
			new_path = (char *)calloc(len, sizeof(char));
			new_path[0] = '\0';
			strcat(new_path, path);
			if (add_slash)
				strcat(new_path, "/");
			strcat(new_path, file->d_name);
			new_path[len - 1] = '\0';
			run_cmd(new_path, cmd);
		}
		else if (FOLLOW_LINK && file->d_type == DT_LINK && is_valid_link(file)) {
			//run_cmd()
		}
	}
	closedir(dir);

	return (0);
}
