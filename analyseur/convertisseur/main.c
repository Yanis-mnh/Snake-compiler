#include<stdio.h>
#include <stdlib.h>

#include "../analyse lex/datatype.h"
#include "../analyse lex/tokenList.h"
#include "fonctions.h"

struct list tokenList;


/***
/*
/* @brief ce programme recevra le fichier cree par analysuer-lex puis vas le donner a 
*  la fonction analyser_syn pour analyser sa syntexe
*
***/
int main(int argc,char *argv[])
{
	
	FILE *token = fopen("../analyse lex/token_table.temp","rb");
	//FILE *token = fopen("../token_table.temp","rb");
	if(token== NULL)
	{
		printf("ERROR D\'OVERTURE DU FUCHIER");
		exit(EXIT_FAILURE);
	}
	
	fread(&tokenList,sizeof(list),1,token);
	
	
	//just pour tester la connexion entre lex et syn
	//affiche(tokenList);
	
	//l'analyseur syntaxique vas etre dans cette fonction qui vas recevoire les token
	convert(tokenList);
	
	
	
	
	
	//fin programme
	fclose(token);
	return 0;
	
}
