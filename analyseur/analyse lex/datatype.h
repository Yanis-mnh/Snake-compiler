#ifndef __dataType__
	#define __dataType__

/* Token definitions */
typedef enum {
    TOKEN_BEGIN,
	TOKEN_INT,
	TOKEN_REAL,
	TOKEN_SET,
	TOKEN_IF,
	TOKEN_ELSE,
	TOKEN_SNK_PRINT,
    TOKEN_COMMENT,
	TOKEN_END,
	TOKEN_IDENTIFIER,
	TOKEN_NUMBER,
    TOKEN_REAL_NUMBER
}tokenName;
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
    "Snk_End",
    "Identifier",
    "Number",
    "Real_Number"
};
// state possibles de l'automate se2 go brrrrrrrrrrrrrr
// les etat ne sont pas encore fini we nead to make an automate for the snake lang
typedef enum {
    START,
    IDENTIFIER,
    NUMBER,
    INVALID
} State;


//strcuteur d'un id
typedef struct{
	char *value;
}idToken;

#endif
