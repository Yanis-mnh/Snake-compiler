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
	TOKEN_IDENTIFIER,
	TOKEN_NUMBER,
    TOKEN_REAL_NUMBER,
    TOKEN_END
}tokenName;

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
