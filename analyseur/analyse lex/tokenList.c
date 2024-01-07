
#include "tokenList.h"
#include <stdio.h>
#include <stdlib.h>


void init_list(list *a)
{
	
	a->nbrToken = 0;
	
}

void add_to_liste(list *a,token _token,int line)
{
	if(a->nbrToken > maxToken)
	{
		perror("error memory space too many tokens");
		free_memory(a);
		exit(EXIT_FAILURE);
	}
	a->_token[a->nbrToken] = _token;	
	a->line[a->nbrToken] = line;
	a->nbrToken++;
	
	
}

void affiche(list a)
{
	int i=0;
	for(;i<a.nbrToken;i++)
	{
		//printf("Token: %d\n",a._token[i].type);
		printf("________________\n");
		printf("token: %d\n",a._token[i].type);
		printf("line: %d\n",a.line[i]);
		
	}
}


void free_memory(list *a)
{
	//no nead to free memory cauz we dont care abouot youre RAM
	//just jocking memory is free when when we addes _tokens 
}

