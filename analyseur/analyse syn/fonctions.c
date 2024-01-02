#ifndef __potato__
	#define __potato__
	
	#include <stdio.h>
	#include <stdlib.h>
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


void analyseur_syn(list token)
{
	//example de letulisation des token
	//pour snk begin cest TOKEN_SNK_BEGIN donc
	int i =0;
	for(;i<token.nbrToken;i++)
	{
		if(token._token[i].type == TOKEN_SNK_BEGIN)
		{
			printf("SNK_BEGIN");
		}
	}
	//donc tas une liste de tokens
	//bone chance u will nead it :)
}


#endif
