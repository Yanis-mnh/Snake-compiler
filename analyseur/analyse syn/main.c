#include<stdio.h>
#include <stdlib.h>

/***
/*
/* @brief ce programme recevra le fichier cree par analysuer-lex puis vas le donner a 
*  la fonction analyser_syn pour analyser sa syntexe
*
***/
int main(int argc,char *argv[])
{
	
	/*FILE *file;
	
	
	file = fopen(argv[1],"r");
	if(file == NULL)
	{
		printf("ERROR D'OVERTURE DU FICHIER ");
		exit(0);
	}
	
	*/
	
	analyseur_syn("ceci est un test");
	//fclose(file);
	return 0;
	return 0;
}
