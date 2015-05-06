#include <stdio.h>
#include "command.h"

void usage(const char* pgm){
    printf("Usage : %s commande [repertoire]", pgm);
}

void help(const Command commands[], size_t nb_cmd){
    usage("./recherche");
    printf("Effectue une recherche dans les fichiers à partir du répertoire indiqué ou par défaut du répertoire courant, sur un des critères suivants au choix à passer en premier argument :");

    int i = 0;
    for (i=0; i<nb_cmd; i++)
        printf("\n-%s", commands[i].name);

}
