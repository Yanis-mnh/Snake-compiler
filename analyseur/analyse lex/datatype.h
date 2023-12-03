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
// Tableau de chaînes de caractères correspondant aux mots-clés
const char *keywords[12] = {
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

