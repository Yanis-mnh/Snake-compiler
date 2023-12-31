#ifndef __potato__
	#define __potato__
	
	#include <stdio.h>
	#include <string.h>
	#include "../analyse lex/tokenList.h"

/*  ///////////  juste pour savoire les token sont cette structeur est dans datatype.h dont nead de la redeclarer //////////////////////
*
*typedef enum {
    //////token for mot cle start from 0 to 9
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
    //////symbole token start form 10 to 15
	TOKEN_FIN_LIGNE,
	TOKEN_OPEN_BRACKET,
	TOKEN_CLOSE_BRACKET,
	TOKEN_COMMA,
	TOKEN_GRREATER,
	TOKEN_INFERIOR,
	//////token for other start from 9 to 13??
	TOKEN_IDENTIFIER,
	TOKEN_INT,
    TOKEN_REAL
    
}tokenType;
*
*/

void analyseur_syn(list _token)
{
	printf("potato found");
}

#endif
