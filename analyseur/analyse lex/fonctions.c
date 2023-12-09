#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

#include "datatype.h"
#include "LinkedList.h"

#define MAX_WORD 50




// Fonction pour vérifier si un mot est un mot-clé
bool isKeyword(const char *word) {
    // Liste de mots-clés
    //keywords (la liste) est dans "datatype.h"
	const char *keywords[14] ={
	    "Snk_Begin",
	    "Snk_Int",	
	    "Snk_Real",
	    "Begin",
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

    // Vérification si le mot est un mot-clé
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
    // Vérification si le mot est un mot-clé
    int i;
	for (i = 0; i <= 6; i++) {
        if (symbole == KEYSYM[i]) {
            return true;
        }
    }
    return false;
}
//est il a numero (real et entier)
bool isNum(char *s)
{
	int i;
	for(i=0;i<strlen(s);i++)
	{
		if(!isdigit(s[i]) && s[i] != '.')
			return false;
	}
	return true;
}

//work in progress
bool isValideId(char *s)
{
	int i =1;
	if( !isalpha(s[0]) && s[0] != '_' )
		return false;
	
	for(;i<strlen(s);i++)
	{
		if( !isalnum(s[0]) && s[0] != '_'  )
			return false;
	}
	return true;
}
bool isCommentaire(char c,FILE *f)
{
	if(c == '$' && fgetc(f) == '$'  )
		return true;
	return false;
		
}
bool isString()
{
	printf("String work in progress\n");
}
// Fonction principale pour l'analyse lexicale
void analyseur_lex(FILE *file) {
    char mot[MAX_WORD]; 
    int i = 0;
    char c;
	struct ptr ptr;
	ptr.Queue = NULL;
	ptr.Tete = NULL;

    while ((c = fgetc(file)) != EOF ) {

		
		if(isCommentaire(c,file) )
			while( (c = fgetc(file)) != EOF && c != '\n'  );// do nothing
        if (c == '\n' || c == ' ' || c == '\t'  || isSymboleCle(c)  ) 
		{
            if (i > 0) // Vérifier si le mot n'est pas vide
			{ 
                mot[i] = '\0'; // Ajouter le caractère de fin de chaîne
                
                if (isKeyword(mot)) 
                    printf("Mot-cle trouve : %s\n", mot);
                else if ( isNum(mot) )
                	printf("its a number %s\n",mot);
                else if(isValideId(mot))
					printf("id : %s\n",mot);
				else
					printf("erreur %s\n",mot);
			}
			if (isSymboleCle(c) )
				printf("cest un symbole: %c\n",c);
            i = 0; // Réinitialiser l'indice du mot
        }
		else 
           	mot[i++] = c; // Ajouter le caractère au mot 
    }
    add_to_liste(&ptr.Tete,&ptr.Queue,1,0);
    add_to_liste(&ptr.Tete,&ptr.Queue,2,0);
    add_to_liste(&ptr.Tete,&ptr.Queue,3,0);
    add_to_liste(&ptr.Tete,&ptr.Queue,4,0);
    add_to_liste(&ptr.Tete,&ptr.Queue,5,0);
    affiche(ptr.Tete);
    free_liste(ptr.Tete);
}
