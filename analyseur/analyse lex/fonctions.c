#ifndef __func__
#define __func__

#include <stdio.h>
#include <stdbool.h>
#include "datatype.h"


// Tableau de cha�nes de caract�res correspondant aux mots-cl�s

// Fonction pour v�rifier si un mot est un mot-cl�
bool isKeyword(const char *word) {
    // Liste de mots-cl�s
    //keywords (la liste) est dans "datatype.h"

    // V�rification si le mot est un mot-cl�
    int i;
	for (i = 0; i < sizeof(keywords) / sizeof(keywords[0]); ++i) {
        if (strcmp(word, keywords[i]) == 0) {
            return true;
        }
    }
    return false;
}

// Fonction principale pour l'analyse lexicale
void analyseur_lex(char input[]) {
	//lautomate vas etre ici
	printf("%s\n",input);
}



#endif
