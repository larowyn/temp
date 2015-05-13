#include <string.h>
#include <errno.h>
#include <stdio.h>
#include "command.h"

int	main(int argc, char **argv) {
	char *path = NULL;
	char *curr = ".";

	path = curr;
	if (argc < 2){
		usage(argv[0]);
		return (-1);
	}
	else if (argc >2){
		path = argv[2];
	}



	Command cmds[CMD_NUMBER];

	strcpy(cmds[0].name, "yesterday_changes");
	strcpy(cmds[1].name, "dead_links");

	cmds[0].fcn = &yesterday_changes;
	cmds[1].fcn = &dead_links;

	if (strcmp(argv[1], "-h") == 0){
		help(cmds, CMD_NUMBER);
		return (0);
	}

	int i;
	for (i = 0; i<CMD_NUMBER; i++){
		if (strcmp(argv[1], cmds[i].name) == 0){
			printf("%s on %s:\n", cmds[i].name, path);
			if (run_cmd(path, cmds[i].fcn) != 0) {
				print_error(path);
				return (errno);
			}
			return (0);
		}
	}
	// pas de nom valide pour la commande
	usage(argv[0]);

	return (1);
}
