#include <stdbool.h>
#include "datatype.h"
#include <ctype.h>

// Fonction pour v�rifier si un mot est un mot-cl�
bool isKeyword(const char *word) {
    // Liste de mots-cl�s
    const char *keywords[] = {"Snk_Begin", "Snk_Int", "Snk_Real", "Set", "If", "Else", "Begin", "Get","Snk_Print","$$","Snk_End",",","$"};

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
void analyseur_lex(const char *input) {
	//lautomate vas etre ici
	printf("l\'automate n\'est pas encore cree com back later :)\n");
}











