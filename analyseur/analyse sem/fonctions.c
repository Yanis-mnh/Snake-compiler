#ifndef __potato__
	#define __potato__
	
	#include <stdio.h>
	#include <string.h>
	#include<stdlib.h>
	#include <stdbool.h>
	#include "../analyse lex/datatype.h"
	#include "../analyse lex/tokenList.h"
	

/*  ///////////  juste pour savoire les token ont cette structeur ils sont dans datatype.h dont nead de la redeclarer //////////////////////

typedef enum {
    TOKEN_SNK_BEGIN, //0
	TOKEN_DEC_INT, //1
	TOKEN_DEC_REAL, //2
	TOKEN_BEGIN, //3
	TOKEN_SET, //4
	TOKEN_IF, //5
	TOKEN_ELSE, //6
	TOKEN_GET, //7
	TOKEN_SNK_PRINT, //8
	TOKEN_SNK_END, //9
	TOKEN_WHILE, //10
	TOKEN_END, //11
	TOKEN_ADD, //12
	TOKEN_SUB, //13
	TOKEN_MUL, //14
	TOKEN_DIV, //15
	TOKEN_FROM, //16
    //symbole token start form 17 to 21
	TOKEN_FIN_LIGNE, //17
	TOKEN_OPEN_BRACKET, //18
	TOKEN_CLOSE_BRACKET, //19
	TOKEN_COMMA, //20
	TOKEN_GRREATER, //21
	TOKEN_INFERIOR, //22
	//token for other start from 21 to 23
	TOKEN_IDENTIFIER, //23
	TOKEN_INT, //24
    TOKEN_REAL //25
    
}tokenType;

*/
//function principle

void analyseur_sem(list token)
{
	//example de letulisation des token
	//pour snk begin cest TOKEN_SNK_BEGIN donc
	int i =0,j=0,k=0,cerruer=0;
	id id[30];
	for(;i<token.nbrToken;i++)
	{
		if(token._token[i].type == TOKEN_DEC_INT)
		{
			k=0;
			while(token._token[i].type!=TOKEN_FIN_LIGNE)
			{
				
				i++;
				if(token._token[i].type==TOKEN_IDENTIFIER)
				{
					strcpy(id[j].name,token._token[i].value);
							strcpy(id[j].value,"init");
							id[j].type= TOKEN_DEC_INT;
							j++;	
				}
					
			}
				
		}
		if(token._token[i].type == TOKEN_DEC_REAL)
		{
			k=0;
			while(token._token[i].type!=TOKEN_FIN_LIGNE)
			{
				i++;
				if(token._token[i].type==TOKEN_IDENTIFIER)
				{
					strcpy(id[j].name,token._token[i].value);
							strcpy(id[j].value,"init");
							id[j].type= TOKEN_DEC_REAL;
							j++;
					
				}
					
			}
				
		}	
		if(token._token[i].type==TOKEN_SET)
		{
			if(token._token[i+1].type==TOKEN_IDENTIFIER)
			{
				
				j=0;
				bool here=false;
				while(j<30){
				 	if(strcmp(token._token[i+1].value,id[j].name)==0)
					{                       
						
						here=true;
						if(token._token[i+2].type==TOKEN_REAL && id[j].type==TOKEN_DEC_INT)
						{
							cerruer++;
							printf("--------------------------------------\n");
							printf("mistake as %s is declared as int\n",token._token[i+1].value);
							printf("--------------------------------------\n");
						}
						else
						{
							if(token._token[i+2].type==TOKEN_REAL) strcpy(id[j].value,token._token[i+2].value);
							else if(token._token[i+2].type==TOKEN_INT) strcpy(id[j].value,token._token[i+2].value);
						}
					}
					j++;
				}
				if(here==false)
				{
				printf("--------------------------------------\n");
				printf("u are using a none declare variable %s\n",token._token[i+1].value);
				printf("--------------------------------------\n");
				cerruer++;
				
				}
			}
		}
		if(token._token[i].type==TOKEN_DIV)
		{
			
			if(token._token[i+5].type==TOKEN_INT||token._token[i+5].type==TOKEN_REAL)
			{
				
				if(strcmp(token._token[i+5].value,"0"))
				{
					printf("--------------------------------------\n");
					printf("DEVISION BY 0!! MATH ERROR\n");
					printf("--------------------------------------\n");
					cerruer++;
				}
			}
			else if(token._token[i+5].type==TOKEN_IDENTIFIER)
			{
				j=0;
				while(j<30)
				{
					if(strcmp(token._token[i+5].value,id[j].name)==0)
					{
						if(strcmp(id[j].value,"0")==0)
						{
							printf("--------------------------------------\n");
							printf("DEVISION BY 0 IN VARIABLE %s!! MATH ERROR\n",id[j].name);
							printf("--------------------------------------\n");
							cerruer++;
						}
					}
					j++;
				}
			}
		}
		if(token._token[i].type==TOKEN_GET)
		{
			int pos1,pos2;
			char temp[100];
			if(token._token[i+1].type==TOKEN_IDENTIFIER)
			{
				j=0;
				while(j<30)
				{
					if(strcmp(token._token[i+1].value,id[j].name)==0)
					{
						pos1=j;
					}
					j++;
				}
			}
			if(token._token[i+3].type==TOKEN_IDENTIFIER)
			{
				j=0;
				while(j<30)
				{
					if(strcmp(token._token[i+3].value,id[j].name)==0)
					{
						pos2=j;
					}
					j++;
				}
			}
			if(id[pos1].type!=id[pos2].type)
			{
				printf("--------------------------------------\n");
				printf("ERROR! U CANT GIVE VARIABLE OF DIFFERENT TYPING\n");
				printf("--------------------------------------\n");
				cerruer++;	
			}
			
			
		}
			
		
	
		//
	
		//erreur pour
		}
	//donc tas une liste de tokens
	//bone chance u will nead it :)
	if(cerruer==0)
	{
		printf("you are semanticly correct!");
	}
	else{
		printf("u have %d erreurs, please fix them",cerruer);
	}
}

#endif

