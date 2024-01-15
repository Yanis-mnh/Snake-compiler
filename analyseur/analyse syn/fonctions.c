#ifndef __potato__
	#define __potato__
	
	#include <stdio.h>
	#include <stdlib.h>
	#include <stdbool.h>
	#include <string.h>
	#include "../analyse lex/datatype.h"
	#include "../analyse lex/tokenList.h"



int nbrErreur = 0;
int i =1;

//reference for the private function 
void walk(list tokenList);
void blockDeCode(list tokenList);
void nbrError();
void checkToken(list tokenList);
void isCorectLayout(list tokenList);
bool isDeclaration(list tokenList);
bool isComparison(tokenType token);
void conditionIf(list tokenList);
void conditionWhile(list tokenList);



//walk the code
void walk(list tokenList)
{
	isDeclaration(tokenList);
	conditionIf(tokenList);
	blockDeCode(tokenList);
	conditionWhile(tokenList);
	if(tokenList._token[i].type == TOKEN_ELSE){
		printf("ligne : %d\n\tERREUR : expected \"If\" before \"Else\" token \n",tokenList.line[i]);
		nbrErreur++;
	}
}


//la fonction pour analyser le ficheir token (la fonctionne que main vas lancer)
void analyseur_syn(list tokenList)
{
	
	isCorectLayout(tokenList);
	
	while( i < tokenList.nbrToken)
	{
		walk(tokenList);
		i++;
	}
	nbrError();
}


/*
*
* all private fonctionne strat here the fonction that will not get out from fonction.c
*	those fonctionne are for analyse syntaxique 
*	they are like abstract way to represent automate
*
*/



//est-il un nbr (real or int)
bool isNum(tokenType token)
{
	switch(token){
		case TOKEN_INT:
		case TOKEN_REAL:
			return true;
		default :
			return false;
	}
}

//is symbole de comparison
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

//get nbr erreur du code
void nbrError()
{
	if(nbrErreur == 0)
	{
		printf("aucune erreur a signaler");
	}else{
		printf("compilation failed with %d error",nbrErreur);
	}
}


//block de code
void blockDeCode(list tokenList)
{
	if(tokenList._token[i].type == TOKEN_BEGIN  )
		if( tokenList._token[i-1].type != TOKEN_CLOSE_BRACKET && tokenList._token[i-1].type != TOKEN_ELSE)
		{
			printf("ligne : %d\n\tERREUR : expected ']' before \"Begin\" token \n", tokenList.line[i]);
			nbrErreur++;
		}
	
}

//pour savoir si le i depace le nombre totale des token dans le fichier source :)
void checkToken(list tokenList)
{
	if(i >= tokenList.nbrToken)
	{	
		nbrError();
		exit(EXIT_FAILURE);
	}
}


//check if it start with Snk_begin and end with Snk_End
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

    // Verification de la declaration
    if (tokenList._token[i].type == TOKEN_DEC_INT || tokenList._token[i].type == TOKEN_DEC_REAL) {
        i++;
        checkToken(tokenList);

        // Verification des identifiants
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


//is it a valide condition
//[ _i<50] or [1] 
bool condition(list tokenList)
{
	if(tokenList._token[i].type == TOKEN_OPEN_BRACKET)
	{
		i++;
		checkToken(tokenList);
		do
		{
			
			if(tokenList._token[i].type == TOKEN_IDENTIFIER || isNum(tokenList._token[i].type) )
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
				
			}else{
				return false;
			}
		}while(tokenList._token[i].type != TOKEN_CLOSE_BRACKET);
		
		if(tokenList._token[i].type == TOKEN_CLOSE_BRACKET)
		{
			return true;
		}
	}
	return false;
		
}


void conditionElseIf(list tokenList)
{
	i++;
	checkToken(tokenList);
	if(tokenList._token[i].type == TOKEN_BEGIN)
	{
		int beginPos =i;
		while( i < tokenList.nbrToken && tokenList._token[i].type != TOKEN_END)
		{
			walk(tokenList);
			i++;
		}
		if(tokenList._token[i].type != TOKEN_END)
		{
			printf("ligne : %d\n\tERREUR : un Begin non fermer\n", tokenList.line[beginPos]);
			nbrErreur++;
		}
		i++;
		checkToken(tokenList);
		if(tokenList._token[i].type == TOKEN_ELSE)
		{
			conditionElseIf(tokenList);
			return;
		}
		i--;
	}
	else if(tokenList._token[i].type != TOKEN_IF && tokenList._token[i].type != TOKEN_WHILE )
	{
		while( i < tokenList.nbrToken && tokenList._token[i].type != TOKEN_FIN_LIGNE)
		{
			walk(tokenList);
			i++;
		}
		i++;
		checkToken(tokenList);
		if(tokenList._token[i].type == TOKEN_ELSE)
		{
			conditionElseIf(tokenList);
			return;
		}
		i--;
		
	}else i--;
	
	return;
}

//condition If[coparison] (1) Else | no (2) Else If | no
void conditionIf(list tokenList)
{
	if(tokenList._token[i].type == TOKEN_IF )
	{
		i++;
		checkToken(tokenList);
		if(condition(tokenList))
		{
			conditionElseIf(tokenList);
			
		}else{
			printf("ligne : %d\n\tERREUR : expected a valide condition after If token \n", tokenList.line[i]);
			nbrErreur++;
		}
		
	}
	return;
}


//condition While[coparison] and While[conparison]
void conditionWhile(list tokenList)
{
	if(tokenList._token[i].type == TOKEN_WHILE )
	{
		i++;
		checkToken(tokenList);
		if(condition(tokenList))
		{
			i++;
			checkToken(tokenList);
			if(tokenList._token[i].type == TOKEN_BEGIN)
			{
				int beginPos =i;
				while( i < tokenList.nbrToken && tokenList._token[i].type != TOKEN_END)
				{
					
					walk(tokenList);
					i++;
				}
				if(tokenList._token[i].type != TOKEN_END)
				{
					printf("ligne : %d\n\tERREUR : un Begin non fermer\n", tokenList.line[beginPos]);
					nbrErreur++;
				}
			}else
				i--;
		}else{
			printf("ligne : %d\n\tERREUR : expected a valide condition after While token \n", tokenList.line[i]);
			nbrErreur++;
		}
		
	}
	return;
}

//condition Else doit avoir un if avant


#endif
