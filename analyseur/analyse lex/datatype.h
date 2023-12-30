#ifndef __dataType__
	#define __dataType__

/* Token definitions */
typedef enum {
    //token for mot cle start from 0 to 9
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
    //symbole token start form 10 to 15
	TOKEN_FIN_LIGNE,
	TOKEN_OPEN_BRACKET,
	TOKEN_CLOSE_BRACKET,
	TOKEN_COMMA,
	TOKEN_GRREATER,
	TOKEN_INFERIOR,
	//token for other start from 9 to 13??
	TOKEN_IDENTIFIER,
	TOKEN_INT_NUMBER,
    TOKEN_REAL_NUMBER
    
}tokenType;





//strcuteur d'un id
typedef struct{
	tokenType type;
	char value[50];
}token;

#endif
