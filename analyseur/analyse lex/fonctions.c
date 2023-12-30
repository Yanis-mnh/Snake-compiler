#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#include "datatype.h"
#include "tokenList.h"

#define MAX_WORD 50


struct list tokenList;

// Fonction pour vérifier si un mot est un mot-clé
bool isKeyword(const char *word ) {
    // Liste de mots-clés
    //keywords (la liste) est dans "datatype.h"
	const char *keywords[10] ={
	    "Snk_Begin",
	    "Snk_Int",	
	    "Snk_Real",
	    "Begin",
	    "Set",
	    "If",
	    "Else",
	    "Get",
	    "Snk_Print",
	    "Snk_End"
	};

    // Vérification si le mot est un mot-clé
    int i;
	for (i = 0; i < sizeof(keywords) / sizeof(keywords[0]); ++i) {
        if (strcmp(word, keywords[i]) == 0) {
        	token *_token = malloc(sizeof(token));
        	// i est nbr toekn type
			_token->type = i;
        	strcpy(_token->value , "");
			add_to_liste(&tokenList,*_token,2);
            return true;
        }
    }
    return false;
}
bool isSymboleCle(char symbole) {
	const char KEYSYM[7] ={
	    '$',
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
			token *_token = malloc(sizeof(token));
        	_token->type = i+9;
        	strcpy(_token->value , "");
			add_to_liste(&tokenList,*_token,2);
            return true;
        }
    }
    return false;
}
//is an integer 
bool isInt(char *s)
{
	int i;
	for(i=0;i<strlen(s);i++)
	{
		if(!isdigit(s[i]))
			return false;
	}
	token *_token = malloc(sizeof(token));
    _token->type = TOKEN_INT;
    strcpy(_token->value , s);
	add_to_liste(&tokenList,*_token,2);
	return true;
}
//is real
bool isReal(char *s)
{
	int i;
	bool vir = false;
	for(i=0;i<strlen(s);i++)
	{
		if(s[i] == '.' && vir == true)
			return false;
		if(!isdigit(s[i]) && s[i] != '.')
			return false;
		if(s[i] == '.')
			vir = true;
	}
	token *_token = malloc(sizeof(token));
    _token->type = TOKEN_REAL;
    strcpy(_token->value , s);
	add_to_liste(&tokenList,*_token,2);
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
	FILE *temp = f;
	if(c == '$' && fgetc(temp) == '$'  )
	{
		fclose(temp);
		return true;
	}
	fclose(temp); 
	return false;
		
}

// Fonction principale pour l'analyse lexicale
void analyseur_lex(FILE *file) {
	
	// creation dune liste de token
	init_list(&tokenList);
	
	
    char mot[MAX_WORD]; 
    
    char c;
	
	
	
	int i = 0;
    while ((c = fgetc(file)) != EOF ) {
		
		if(isCommentaire(c,file) )
			while( (c = fgetc(file)) != EOF && c != '\n'  );// do nothing
        if (isspace(c)  || isSymboleCle(c) ) 
		{
            if (i > 0) // Vérifier si le mot n'est pas vide
			{ 
                mot[i] = '\0'; // Ajouter le caractère de fin de chaîne
                
                if (isKeyword(mot)) 
                {
                	printf("Mot-cle trouve: %s\n", mot);
                	
				}
				else if (isInt(mot))
                	printf("cest un nombre entier:  %s\n",mot);
                else if (isReal(mot))
                	printf("cest un nombre real:  %s\n",mot);
                else if(isValideId(mot))
					printf("id : %s\n",mot);
				//fix this shit later
				else if(c == '\"'  )
				{
					char *s; //contien le string
					int j = 0;
					while( (c = fgetc(file))  != EOF && c != '\"'  )
					{
						if (c == '\"')
							break;
						s[j] = c;
						j++;
					}
					if(c == '\"')
						printf("string trouver : %s\n",s);
					else
						printf("erreur \" monquante\n");
				}
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
    
    
    free_memory(&tokenList);
    
    
    
    
}
