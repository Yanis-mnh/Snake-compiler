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
	
	
	
	FILE *temp2 = fopen("token_table.temp", "rb");
	list tokenTest;
	if (temp != NULL) {
	    // Write the entire array to the file
	    fread(&tokenTest,sizeof(list),1,temp2);
	    affiche(tokenTest);
	    fclose(temp2);
	} else {
	    printf("Error opening file!\n");
	}
	
	
	
	
	//juste for testing this line should be changed later
	argv[1] = "test001.snk";
	FILE *file = fopen(argv[1],"r");
	
	
	if(file == NULL)
	{
		printf("ERROR D'OVERTURE DU FICHIER ");
		exit(0);
	}
	
	analyseur_lex(file);
	fclose(file);
	return 0;
}






