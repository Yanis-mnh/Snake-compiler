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


int nbrErreur = 1;

void isCorectLayout(list tokenList)
{
	if(tokenList._token[0].type != TOKEN_SNK_BEGIN  ){
		nbrErreur ++;
		printf("ERROR: ligne %d le programme doit tojour comencer par SNK_BEGIN\n",tokenList.line[0]);
	}
	if(tokenList._token[tokenList.nbrToken-1].type != TOKEN_SNK_END  ){
		nbrErreur ++;
		printf("ERROR: ligne %d le programme doit tojour finir par SNK_BEGIN\n",tokenList.line[tokenList.nbrToken-1]);
	}
}




void analyseur_syn(list tokenList)
{
	isCorectLayout(tokenList);
}















#endif
