#ifndef __dataType__
	#define __dataType__


/* Token definitions */
typedef enum {
    //token for mot cle start from 0 to 15
	TOKEN_SNK_BEGIN, //0
	TOKEN_DEC_INT, //1
	TOKEN_DEC_REAL, //2
	TOKEN_BEGIN, //3
	TOKEN_SET, //4
	TOKEN_IF, //5
	TOKEN_ELSE, //6
	TOKEN_GET, //7
	TOKEN_SNK_PRINT, //8
	TOKEN_SNK_END, //9
	TOKEN_WHILE, //10
	TOKEN_END, //11
	TOKEN_ADD, //12
	TOKEN_SUB, //13
	TOKEN_MUL, //14
	TOKEN_DIV, //15
	TOKEN_FROM, //16
    //symbole token start form 17 to 21
	TOKEN_FIN_LIGNE, //17
	TOKEN_OPEN_BRACKET, //18
	TOKEN_CLOSE_BRACKET, //19
	TOKEN_COMMA, //20
	TOKEN_GRREATER, //21
	TOKEN_INFERIOR, //22
	//token for other start from 21 to 23
	TOKEN_IDENTIFIER, //23
	TOKEN_INT, //24
    TOKEN_REAL, //25
    TOKEN_STRING, //26
    //////////////////////
    TOKEN_EQUEL, //27
    TOKEN_INF_EQ, //28
    TOKEN_SUP_EQ //29
    
}tokenType;




//strcuteur d'un token
typedef struct{
	tokenType type;
	char value[50];

}token;

//structeur pour un id
typedef struct {
        char name[30];
        char value[50];
        tokenType type;
}id;

#endif
