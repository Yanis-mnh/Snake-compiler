#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#include "fonctions.h"
/**
*
* @param argv[] is a vecteur of string that we will pass the path of the file to analyse
* brief  the main funct will open the file (.snk file)
*
*/





int main(int argc, char *argv[]) {
	
	//juste for testing this line should be changed later
	argv[1] = "test001.snk";
	char programme[300];
	char c;
	
	
	FILE *file;
	
	
	file = fopen(argv[1],"r");
	if(file == NULL)
	{
		printf("ERROR D'OVERTURE DU FICHIER ");
		exit(0);
	}
	
	//juste un test pour ouvrire le fichier 
	int i=0;
	while((c = fgetc(file) ) != EOF)
	{
		programme[i] = c;
		i++;
	}
	
	analyseur_lex(programme);
	fclose(file);
	return 0;
}






