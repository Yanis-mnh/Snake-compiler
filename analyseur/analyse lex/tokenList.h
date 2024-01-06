#ifndef __LinkedList__
	#define __LinkedList__
#include "datatype.h"


#define maxToken 500
#define maxeLine 9999


typedef struct list{
	token _token[maxToken];
	int nbrToken;
	int line[maxeLine];
	
}list;



//declaration of fonctions linked liste
void init_list(list *a);
void add_to_liste(list *a,token _token,int nbrLine);
void affiche(list a);
void free_memory(list *a);

#endif
