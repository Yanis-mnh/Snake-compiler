#ifndef __potato__
	#define __potato__
	
	#include <stdio.h>
	#include <string.h>
	#include<stdlib.h>
	#include "../analyse lex/datatype.h"
	#include "../analyse lex/tokenList.h"
	

/*  ///////////  juste pour savoire les token ont cette structeur ils sont dans datatype.h dont nead de la redeclarer //////////////////////

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

*/
//function principle
void analyseur_sem(list token)
{
	//example de letulisation des token
	//pour snk begin cest TOKEN_SNK_BEGIN donc
	int i =0,j,cerruer=0;
	int syn_erreur=0;
	id id[30];
	for(;i<token.nbrToken;i++)
	{
		if(token._token[i].type == TOKEN_DEC_INT)
		{
			
			while(token._token[i].type!=TOKEN_FIN_LIGNE)
			{
				i++;
				if(token._token[i].type!=TOKEN_IDENTIFIER)
				{
					printf("type: %d\n",token._token[i].type);
					
					syn_erreur++;
				}
				else{
					printf("i did get in\n",i);
					strcpy(id[j].name,token._token[i+1].value);
					strcpy(id[j].value,"0");
					id[j].type= TOKEN_DEC_INT;
					j++;
					
					
				}
			}
				
		}
			

			
		
		if(token._token[i].type == TOKEN_SET)
		{
			if(token._token[i+1].type== TOKEN_IDENTIFIER){
				printf("int with value of identifier: ");
			printf("%s \n", token._token[i+1].value);
			}
		}
		if(token._token[i].type == TOKEN_REAL)
		{
			printf("int with value of Real: ");
			printf("%.2f \n", (double)atoi(token._token[i].value));
			
		}
		if(token._token[i].type == TOKEN_SET && token._token[i+1].type == TOKEN_INT)
		{
			printf("int with value of REAL: ");
			printf("%f \n", (float)atoi(token._token[i].value));
		}
		//
	
		//erreur pour
	}
	//donc tas une liste de tokens
	//bone chance u will nead it :)
}

#endif
