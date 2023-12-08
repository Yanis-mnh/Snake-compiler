#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#include "datatype.h"
#include "LinkedList.h"

#define MAX_WORD 50



// Tableau de cha�nes de caract�res correspondant aux mots-cl�s

// Fonction pour v�rifier si un mot est un mot-cl�
bool isKeyword(const char *word) {
    // Liste de mots-cl�s
    //keywords (la liste) est dans "datatype.h"
	const char *keywords[13] ={
	    "Snk_Begin",
	    "Snk_Int",	
	    "Snk_Real",
	    "Set",
	    "If",
	    "Else",
	    "Get",
	    "Snk_Print",
	    "$$",
	    "Identifier",
	    "Number",
	    "Real_Number",
	    "Snk_End"
	};

    // V�rification si le mot est un mot-cl�
    int i;
	for (i = 0; i < sizeof(keywords) / sizeof(keywords[0]); ++i) {
        if (strcmp(word, keywords[i]) == 0) {
            return true;
        }
    }
    return false;
}
bool isSymboleCle(char symbole) {
	const char KEYSYM[7] ={
	    '$',	
	    '\"',
	    '[',
	    ']',
	    ',',
	    '>',
	    '<'
	};
    // V�rification si le mot est un mot-cl�
    int i;
	for (i = 0; i <= 6; i++) {
        if (symbole == KEYSYM[i]) {
            return true;
        }
    }
    return false;
}

// Fonction principale pour l'analyse lexicale
void analyseur_lex(FILE *file) {
    char mot[MAX_WORD]; 
    int i = 0;
    char c;

    while ((c = fgetc(file)) != EOF ) {
    	//verifier si cest un symbole cle
    	
    	if ( isSymboleCle(c))
            printf("symbole trouve : %c\n", c);
        if (c == '\n' || c == ' ' || c == '\t'  || isSymboleCle(c)) {
            if (i > 0) { // V�rifier si le mot n'est pas vide
                mot[i] = '\0'; // Ajouter le caract�re de fin de cha�ne
                if (isKeyword(mot)) 
                    printf("Mot-cle trouve : %s\n", mot);
                else
                	printf("id or error for the moment\n");
			}
            i = 0; // R�initialiser l'indice du mot
        }else 
           	mot[i++] = c; // Ajouter le caract�re au mot 
    }
}



