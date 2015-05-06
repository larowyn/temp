#include <stdio.h>
#include "command.h"

void usage(const char* pgm){
    printf("Usage : %s commande [repertoire]", pgm);
}

void help(const Command commands[], size_t nb_cmd){
    usage("./recherche");
    printf("Effectue une recherche dans les fichiers � partir du r�pertoire indiqu� ou par d�faut du r�pertoire courant, sur un des crit�res suivants au choix � passer en premier argument :");

    int i = 0;
    for (i=0; i<nb_cmd; i++)
        printf("\n-%s", commands[i].name);

}
