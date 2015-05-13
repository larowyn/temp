#include <stdio.h>
#include "command.h"

void usage(const char* pgm){
    printf("Usage : %s commande [repertoire]\n", pgm);
}

void help(const Command commands[], size_t nb_cmd){
    usage("./recherche");
    printf("Effectue une recherche dans les fichiers à partir du répertoire indiqué ou par défaut du répertoire courant, sur un des critères suivants au choix à passer en premier argument :\n");

    size_t i;
    for (i=0; i<nb_cmd; i++)
        printf("-%s\n", commands[i].name);

}
