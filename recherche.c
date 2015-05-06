#include <string.h>
#include "command.h"

int	main(int argc, char **argv) {
    char* path = NULL;

    if (argc < 2){
        // On n'a pas ni nom de commande ni répertoire source
        // Fin de programme
        usage(argv[0]);
        return 1;
    }
    else if(argc >2){
        // On n'a pas de nom de répertoire
        // On part du répertoire courant
        path = argv[2];
    }



    Command cmds[2];

    strcpy(cmds[0].name, "yesterday_changes");
    strcpy(cmds[1].name, "dead_links");

    cmds[0].fcn = &yesterday_changes;
    cmds[1].fcn = &dead_links;

    if (strcmp(argv[1], "-h") == 0){
        help(cmds, sizeof(cmds)/sizeof(Command));
        return 0;
    }

    int i;
    for (i = 0; i<(sizeof(cmds)/sizeof(Command)); i++){
        if (strcmp(argv[1], cmds[i].name) == 0){
            run_cmd(path, cmds[i].fcn);
            return 0;
        }
    }
    // pas de nom valide pour la commande
    usage(argv[0]);

	return (1);
}
