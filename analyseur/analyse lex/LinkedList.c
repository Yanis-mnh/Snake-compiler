
#include "LinkedList.h"
#include <stdio.h>
#include <stdlib.h>

void add_to_liste(list **tete,list **queue,int token,int nbrLine)
{
	list *nov = (list *)malloc(sizeof(list));
	if(nov == NULL)
	{
		printf("Erreur d'alovation de memoire");
		return;
	}
	if(*tete == NULL)
	{
		nov->next = *tete;
		nov->token = token;
		nov->nbrLine = nbrLine;
		*tete = nov;
		*queue = nov;
	}else
	{
		
	}
	
	
}

void affiche(list *tete)
{
	printf("affichage de la liste: \n");
	list *ptr = tete;
	while(ptr != NULL)
	{
		printf("%d -> ",ptr->token);
		ptr = ptr->next;
	}
	printf("NULL\n");
}

void free_liste(list *tete)
{
	struct list *ptr = tete;
	while(ptr != NULL)
	{
		printf("free(%d)\t",tete->token);
		ptr = tete->next;
		free(tete);
		tete = ptr;
	}
	printf("\nmemory free : ok\n");
	
}





