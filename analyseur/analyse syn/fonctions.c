#ifndef __potato__
	#define __potato__
	
	#include <stdio.h>
	#include <stdlib.h>
	#include <stdbool.h>
	#include <string.h>
	#include "../analyse lex/datatype.h"
	#include "../analyse lex/tokenList.h"
/*  ///////////  juste pour savoire les token ont cette structeur ils sont dans datatype.h dont nead de la redeclarer //////////////////////
*
typedef enum {
    //token for mot cle start from 0 to 15
	TOKEN_SNK_BEGIN,
	TOKEN_DEC_INT,
	TOKEN_DEC_REAL,
	TOKEN_BEGIN,
	TOKEN_SET,
	TOKEN_IF,
	TOKEN_ELSE,
	TOKEN_GET,
	TOKEN_SNK_PRINT,
	TOKEN_SNK_END,
	TOKEN_WHILE,
	TOKEN_END,
	TOKEN_ADD,
	TOKEN_SUB,
	TOKEN_MUL,
	TOKEN_DIV,
    //symbole token start form 16 to 21
	TOKEN_FIN_LIGNE,
	TOKEN_OPEN_BRACKET,
	TOKEN_CLOSE_BRACKET,
	TOKEN_COMMA,
	TOKEN_GRREATER,
	TOKEN_INFERIOR,
	//token for other start from 21 to 23
	TOKEN_IDENTIFIER,
	TOKEN_INT,
    TOKEN_REAL
    
}tokenType;
*
*/
//struct id


int nbrErreur = 0;
int i =1;

//pour savoir si le i depace le nombre totale des token dans le fichier source :)
void checkToken(list tokenList)
{
	if(i >= tokenList.nbrToken)
	{	
		printf("erreur");
		exit(EXIT_FAILURE);
	}
}

//
void isCorectLayout(list tokenList)
{
	if(tokenList._token[0].type != TOKEN_SNK_BEGIN  ){
		nbrErreur ++;
		printf("ERROR: ligne %d le programme doit tojour comencer par SNK_BEGIN\n",tokenList.line[0]);
	}
	if(tokenList._token[tokenList.nbrToken-1].type != TOKEN_SNK_END  ){
		nbrErreur ++;
		printf("ERROR: ligne %d le programme doit tojour finir par SNK_END\n",tokenList.line[tokenList.nbrToken-1]);
	}
}











//proceduer pour identifier les declaration
/*
Snk_Int i ,r $
Snk_Real x3,f $
*/
bool isDeclaration(list tokenList) {

    // Vérification de la déclaration
    if (tokenList._token[i].type == TOKEN_DEC_INT || tokenList._token[i].type == TOKEN_DEC_REAL) {
        i++;
        checkToken(tokenList);

        // Vérification des identifiants
        while (tokenList._token[i].type != TOKEN_FIN_LIGNE) {
            
			if (tokenList._token[i].type == TOKEN_IDENTIFIER) {
                i++;
                checkToken(tokenList);
				
                if (tokenList._token[i].type == TOKEN_COMMA) {
                    i++;
                    checkToken(tokenList);
                    if(tokenList._token[i].type != TOKEN_IDENTIFIER)
                    {
                    	printf("line %d: \n\tERROR: aprere vigule doit avoire un identifien\n",tokenList.line[i]);
                    	nbrErreur++;
                    	break;
					}
                }else if (tokenList._token[i].type == TOKEN_FIN_LIGNE ) {
                    break;
                } else {
                    printf("Line %d: \n\tERROR : Virgule ou Fin de ligne attendue apres un identifiant\n", tokenList.line[i]);
                    nbrErreur++;
                    break; // Sortir de la boucle pour éviter des erreurs multiples
                }
            } else {
                printf("Line %d: \n\tERREUR : Identifiant manquant \n", tokenList.line[i]);
                nbrErreur++;
                break; // Sortir de la boucle pour éviter des erreurs multiples
            }
        }
    }
}

//combarison
bool isComparison(tokenType token){
	
	switch(token)
	{
		case TOKEN_EQUEL: 
		case TOKEN_INF_EQ:
		case TOKEN_SUP_EQ:
		case TOKEN_GRREATER:
		case TOKEN_INFERIOR:
			return true;
		default :
			return false;
	}
}

//condition
//[ _i<50]
void condition(list tokenList)
{
	if(tokenList._token[i].type == TOKEN_OPEN_BRACKET)
	{
		i++;
		checkToken(tokenList);
		while(tokenList._token[i].type != TOKEN_CLOSE_BRACKET)
		{
			
			if(tokenList._token[i].type == TOKEN_IDENTIFIER || tokenList._token[i].type == TOKEN_INT || tokenList._token[i].type == TOKEN_REAL)
			{
				i++;
				checkToken(tokenList);
				if( tokenList._token[i].type != TOKEN_CLOSE_BRACKET && isComparison(tokenList._token[i].type)  )
				{
					i++;
					checkToken(tokenList);
				}else if(tokenList._token[i].type == TOKEN_CLOSE_BRACKET){
					
					break;
				}else{
					printf("ligne : %d\n\tERREUR : signe de comparaison manquant\n", tokenList.line[i]);
					nbrErreur++;
					break;
				}
				
			}
		}
		
	}
		
}






void analyseur_syn(list tokenList)
{
	
	isCorectLayout(tokenList);
	
	while( i < tokenList.nbrToken)
	{
		isDeclaration(tokenList);
		condition(tokenList);
		i++;
	}
	if(nbrErreur == 0)
	{
		printf("aucune erreur a signaler");
	}else{
		printf("compilation failed with %d error",nbrErreur);
	}
}















#endif
