
#include "tokenList.h"
#include <stdio.h>
#include <stdlib.h>


void init_list(list *a)
{
	a->nbrLine=0;
	a->nbrToken = 0;
	
}

void add_to_liste(list *a,token _token,int nbrLine)
{
	if(a->nbrToken > maxToken)
	{
		perror("error memory space too many tokens");
		free_memory(a);
		exit(EXIT_FAILURE);
	}
	
	a->_token[a->nbrToken] = _token;	
	a->nbrToken++;
	
}

void affiche(list a)
{
	int i=0;
	for(;i<a.nbrToken;i++)
	{
		printf("Token: %d\n",a._token[i].type);
		printf("value: %s\n",a._token[i].value);
	}
}


void free_memory(list *a)
{
	int i;
	for(i=0;i<a->nbrToken;i++)
	{
		//free(a[i]);
	}
}





