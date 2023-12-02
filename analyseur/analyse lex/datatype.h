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


//strcuteur d'un id
typedef struct{
	char *value;	
}idToken;

