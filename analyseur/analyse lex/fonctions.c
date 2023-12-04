#ifndef __func__
#define __func__

#include <stdbool.h>
#include "datatype.h"

// Fonction pour vérifier si un mot est un mot-clé
bool isKeyword(const char *word) {
    // Liste de mots-clés
    //keywords (la liste) est dans "datatype.h"

    // Vérification si le mot est un mot-clé
    int i;
	for (i = 0; i < sizeof(keywords) / sizeof(keywords[0]); ++i) {
        if (strcmp(word, keywords[i]) == 0) {
            return true;
        }
    }
    return false;
}

// Fonction principale pour l'analyse lexicale
void analyseur_lex(const char *input) {
	//lautomate vas etre ici
	printf("l\'automate n\'est pas encore cree com back later :)\n");
}



#endif
