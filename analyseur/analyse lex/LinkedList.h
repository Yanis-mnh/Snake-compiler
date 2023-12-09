#ifndef __LinkedList__
	#define __LinkedList__





typedef struct list{
	int token;
	int nbrLine;
	struct list *next;
	struct list *queue;
}list;

struct ptr{
	list *Tete;
	list *Queue;	
};

//declaration of fonctions linked liste
void add_to_liste(list **tete,list **queue,int token,int nbrLine);
void affiche(list *tete);
void free_liste(list *tete);

#endif
