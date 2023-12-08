
#include "LinkedList.h"
#include <stdio.h>
#include <stdlib.h>

void add_to_liste(list *tete,int token,int nbrLine)
{
	list *nov = malloc(sizeof(tete));
}

void affiche(list *tete)
{
	list *ptr = tete;
	while(ptr != NULL)
	{
		printf("%d -> ",tete->token);
		ptr = ptr->next;
	}
}

void free_liste(list *tete)
{
	struct list *ptr = tete;
	while(ptr != NULL)
	{
		ptr = tete->next;
		free(tete);
		tete = ptr;
	}
	
}





