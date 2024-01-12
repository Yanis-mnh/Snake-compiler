#ifndef __potato__
	#define __potato__
	
	#include <stdio.h>
	#include <stdlib.h>
	#include <stdbool.h>
	#include <string.h>
	#include "../analyse lex/datatype.h"
	#include "../analyse lex/tokenList.h"







void convert(list tokenList)
{
	
	int i=0;
	FILE *g =fopen("out.c","w");
	while( i < tokenList.nbrToken)
	{
		switch(tokenList._token[i].type)
		{
			case TOKEN_SNK_BEGIN:{
				fprintf(g,"%s","#include <stdio.h>\nint main(){\n");
				break;
			}
			case TOKEN_INT:
			case TOKEN_REAL:{
				fprintf(g," %s ",tokenList._token[i].value);
				break;
			}
			case TOKEN_WHILE:{
				fprintf(g," %s ","while");
				break;
			}
			case TOKEN_INFERIOR:{
				fprintf(g," %c ",'<');
				break;
			}
			case TOKEN_GRREATER:{
				fprintf(g," %c ",'>');
				break;
			}
			case TOKEN_EQUEL:{
				fprintf(g," %s ","==");
				break;
			}
			case TOKEN_INF_EQ:{
				fprintf(g," %s ","<=");
				break;
			}
			case TOKEN_SUP_EQ:{
				fprintf(g," %s ",">=");
				break;
			}
			case TOKEN_SNK_END:{
				fprintf(g,"%s","\n return 0; \n}");
				break;
			}
			
			case TOKEN_DEC_INT: {
				fprintf(g,"%s","int");
				break;
			}
			case TOKEN_DEC_REAL: {
				fprintf(g,"%s","float");
				break;
			}
			case TOKEN_ADD: {
				i++;
				fprintf(g," %s = ",tokenList._token[i].value);
				i+=2;
				fprintf(g," %s + ",tokenList._token[i].value);
				i+=2;
				fprintf(g," %s ",tokenList._token[i].value);
				break;
			}
			case TOKEN_MUL: {
				i++;
				fprintf(g," %s = ",tokenList._token[i].value);
				i+=2;
				fprintf(g," %s * ",tokenList._token[i].value);
				i+=2;
				fprintf(g," %s ",tokenList._token[i].value);
				break;
			}
			case TOKEN_DIV: {
				i++;
				fprintf(g," %s = ",tokenList._token[i].value);
				i+=2;
				fprintf(g," %s / ",tokenList._token[i].value);
				i+=2;
				fprintf(g," %s ",tokenList._token[i].value);
				break;
			}
			case TOKEN_SUB: {
				i++;
				fprintf(g," %s = ",tokenList._token[i].value);
				i+=2;
				fprintf(g," %s - ",tokenList._token[i].value);
				i+=2;
				fprintf(g," %s ",tokenList._token[i].value);
				break;
			}
			case TOKEN_FIN_LIGNE:{
				fprintf(g,"%c",';');
				break;
			}
			case TOKEN_COMMA:{
				fprintf(g,"%c",',');
				break;
			}
			case TOKEN_BEGIN:{
				fprintf(g,"%c",'{');
				break;
			}
			case TOKEN_END:{
				fprintf(g,"%c",'}');
				break;
			}
			case TOKEN_IF:{
				fprintf(g,"%s","if");
				break;
			}
			case TOKEN_OPEN_BRACKET:{
				fprintf(g,"%c",'(');
				break;
			}
			case TOKEN_CLOSE_BRACKET:{
				fprintf(g,"%c",')');
				break;
			}
			case TOKEN_SET:{
				i++;
				fprintf(g,"%s = ",tokenList._token[i].value);
				i++;
				fprintf(g,"%s",tokenList._token[i].value);
				break;
			}
			case TOKEN_GET:{
				i++;
				fprintf(g,"%s = ",tokenList._token[i].value);
				i++;
				fprintf(g," %s ",tokenList._token[i].value);
				break;
			}
			case TOKEN_IDENTIFIER:{
				fprintf(g," %s ",tokenList._token[i].value);
				break;
			}
			case TOKEN_SNK_PRINT:{
				
				while(tokenList._token[i].type != TOKEN_FIN_LIGNE)
				{
					
					i++;
					if(tokenList._token[i].type == TOKEN_IDENTIFIER)
					{
						fprintf(g,"printf(\" %%d \" , %s);", tokenList._token[i].value);	
					}
					else if(tokenList._token[i].type == TOKEN_STRING)
					{
						fprintf(g,"printf(\" %s \");", tokenList._token[i].value);	
					}
				}
				
				
				break;
			}
			
		}
		i++;
	}
	fclose(g);
	
}




#endif
