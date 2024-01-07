#ifndef __potato__
	#define __potato__
	
	#include <stdio.h>
	#include <stdlib.h>
	#include <string.h>
	#include "../analyse lex/datatype.h"
	#include "../analyse lex/tokenList.h"
/*  ///////////  juste pour savoire les token ont cette structeur ils sont dans datatype.h dont nead de la redeclarer //////////////////////
*
typedef enum {
    //token for mot cle start from 0 to 15
	TOKEN_SNK_BEGIN,
	TOKEN_DEC_INT,
	TOKEN_DEC_REAL,
	TOKEN_BEGIN,
	TOKEN_SET,
	TOKEN_IF,
	TOKEN_ELSE,
	TOKEN_GET,
	TOKEN_SNK_PRINT,
	TOKEN_SNK_END,
	TOKEN_WHILE,
	TOKEN_END,
	TOKEN_ADD,
	TOKEN_SUB,
	TOKEN_MUL,
	TOKEN_DIV,
    //symbole token start form 16 to 21
	TOKEN_FIN_LIGNE,
	TOKEN_OPEN_BRACKET,
	TOKEN_CLOSE_BRACKET,
	TOKEN_COMMA,
	TOKEN_GRREATER,
	TOKEN_INFERIOR,
	//token for other start from 21 to 23
	TOKEN_IDENTIFIER,
	TOKEN_INT,
    TOKEN_REAL
    
}tokenType;
*
*/
//struct id

id table_id[9999];
	int errorCount=0;

void check(int i,list tokenList){
	
	if (tokenList._token[i].type==TOKEN_BEGIN && tokenList._token[i+1].type==TOKEN_FIN_LIGNE){
				
			printf("Syntax Error at line %d: '$' extra   \n", tokenList.line[i]);
		
                    errorCount++;
                    
		}
			if (tokenList._token[i].type==TOKEN_END && tokenList._token[i+1].type==TOKEN_FIN_LIGNE){
			printf("Syntax Error at line %d: '$' extra   \n", tokenList.line[i]);
		
                    errorCount++;
                    
		}
			if (tokenList._token[i].type==TOKEN_ELSE && tokenList._token[i+1].type==TOKEN_FIN_LIGNE){
			printf("Syntax Error at line %d: '$' extra   \n", tokenList.line[i]);
		
                    errorCount++;
                    
		}
		
		// chek Snk_int 
    if(tokenList._token[i].type==TOKEN_DEC_INT )
	{
	
		i++;
	if(tokenList._token[i].type==TOKEN_IDENTIFIER ){
		id id_int;
		strcpy(id_int.name,tokenList._token[i].value);
		id_int.type=TOKEN_INT;
	    strcpy(id_int.value , "0");
		
	i++;
	
		while(tokenList._token[i].type!=TOKEN_FIN_LIGNE){
					if(tokenList._token[i].type==TOKEN_COMMA){
					i++;
				}
			if(tokenList._token[i].type!=TOKEN_IDENTIFIER){
			printf("Syntax Error at line %d: error syntaxe of Snk_int   \n", tokenList.line[i]);
			errorCount++;
			i++;
			}
			if(tokenList._token[i].type==TOKEN_IDENTIFIER ){
				
					strcpy(id_int.name,tokenList._token[i].value);
		            id_int.type=TOKEN_INT;
	                strcpy(id_int.value , "0");
				
				i++;
				if(tokenList._token[i].type!=TOKEN_COMMA && tokenList._token[i].type!=TOKEN_FIN_LIGNE){
					printf("Syntax Error at line %d: strectur of Snk_int is false   \n", tokenList.line[i]);
					errorCount++;
				}
			
			
				}
			
				
				
			}
			
			
			
		}
		else{
			printf("Syntax Error at line %d: error syntaxe Snk_int   \n", tokenList.line[i]);
			errorCount++;
		}}
		
    	
	
           // chek  Snk_real
       if(tokenList._token[i].type==TOKEN_DEC_REAL )
	{
	
		i++;
	if(tokenList._token[i].type==TOKEN_IDENTIFIER ){
		id id_real;
		strcpy(id_real.name,tokenList._token[i].value);
		id_real.type=TOKEN_REAL;
	    strcpy(id_real.value , "0");
		
	i++;
	
		while(tokenList._token[i].type!=TOKEN_FIN_LIGNE){
					if(tokenList._token[i].type==TOKEN_COMMA){
					i++;
				}
			if(tokenList._token[i].type!=TOKEN_IDENTIFIER){
			printf("Syntax Error at line %d: error syntaxe of Snk_Real   \n", tokenList.line[i]);
			errorCount++;
			i++;
			}
			if(tokenList._token[i].type==TOKEN_IDENTIFIER ){
					strcpy(id_real.name,tokenList._token[i].value);
		            id_real.type=TOKEN_REAL;
	                strcpy(id_real.value , "0");
				i++;
				if(tokenList._token[i].type!=TOKEN_COMMA && tokenList._token[i].type!=TOKEN_FIN_LIGNE){
					printf("Syntax Error at line %d: strectur of Snk_Real is false   \n", tokenList.line[i]);
					errorCount++;
				}
			
			
				}
			
				
				
			}
			
			
			
		}
		else{
			printf("Syntax Error at line %d: error syntaxe Snk_Real  \n", tokenList.line[i]);
			errorCount++;
		}}
		//check syntaxe of Set
    	if(tokenList._token[i].type==TOKEN_SET){
    		i++;
    		if(tokenList._token[i].type!=TOKEN_IDENTIFIER){
    				printf("Syntax Error at line %d: error syntaxe Set  \n", tokenList.line[i]);
			         errorCount++;
    			
			}
			else{
				i++;
				if(tokenList._token[i].type!=TOKEN_INT && tokenList._token[i].type!=TOKEN_REAL){
						printf("Syntax Error at line %d: error syntaxe Set  \n", tokenList.line[i]);
			errorCount++;
				}
				else{i++;
				if(tokenList._token[i].type!=TOKEN_FIN_LIGNE){
						printf("Syntax Error at line %d: $ is missed  \n", tokenList.line[i]);
			errorCount++;
				}
				}
			}
    		
		}
		
		//check syntaxe of get
		if (tokenList._token[i].type==TOKEN_GET){
			i++;
			if (tokenList._token[i].type!=TOKEN_IDENTIFIER){
					printf("Syntax Error at line %d: syntax de Get  \n", tokenList.line[i]);
			        errorCount++;
				
			}else{
				i++;
				if(tokenList._token[i].type!=TOKEN_FROM ){
						printf("Syntax Error at line %d: syntax de Get  \n", tokenList.line[i]);
			        errorCount++;
					
				}else{
					i++;
						if (tokenList._token[i].type!=TOKEN_IDENTIFIER){
					printf("Syntax Error at line %d: syntax de Get  \n", tokenList.line[i]);
			        errorCount++;
				
			          }else{
			          	i++;
			          	if(tokenList._token[i].type!=TOKEN_FIN_LIGNE){
			          			printf("Syntax Error at line %d: '$' is missed  \n", tokenList.line[i]);
			                  errorCount++;
						  }
			          	
					  }
					
				}
			}
			
		}
		//check Snk_print 
		
		if (tokenList._token[i].type==TOKEN_SNK_PRINT){
			i++;
			if (tokenList._token[i].type!=TOKEN_IDENTIFIER && tokenList._token[i].type!=TOKEN_STRING){
					printf("Syntax Error at line %d: syntax de Snk_print  \n", tokenList.line[i]);
			        errorCount++;
			}
			if(tokenList._token[i].type==TOKEN_IDENTIFIER){
				i++;
				if(tokenList._token[i].type!=TOKEN_IDENTIFIER  && tokenList._token[i].type!=TOKEN_COMMA && tokenList._token[i].type!=TOKEN_FIN_LIGNE )	{
						printf("Syntax Error at line %d: '$' is missed  \n", tokenList.line[i]);
			        errorCount++;
			        
				}
				
				while(tokenList._token[i].type!=TOKEN_FIN_LIGNE){
					if(tokenList._token[i].type==TOKEN_COMMA){
					i++;
				}
			if(tokenList._token[i].type!=TOKEN_IDENTIFIER){
			printf("Syntax Error at line %d: error syntaxe of Snk_print   \n", tokenList.line[i]);
			errorCount++;
			
			}
			if(tokenList._token[i].type==TOKEN_IDENTIFIER ){
					
				i++;
				
				if(tokenList._token[i].type!=TOKEN_COMMA && tokenList._token[i].type!=TOKEN_FIN_LIGNE){
					printf("Syntax Error at line %d: strectur of Snk_print is false   \n", tokenList.line[i]);
					errorCount++;
				}
				
			
			
				}
				if(tokenList._token[i].type!=TOKEN_IDENTIFIER  && tokenList._token[i].type!=TOKEN_COMMA && tokenList._token[i].type!=TOKEN_FIN_LIGNE )	{
						printf("Syntax Error at line %d: '$' is missed  \n", tokenList.line[i]);
			        errorCount++;
			        break;
				}
				}
				
			}
			if (tokenList._token[i].type==TOKEN_STRING){
				i++;
				if(tokenList._token[i].type!=TOKEN_FIN_LIGNE){
						printf("Syntax Error at line %d: '$' is missed  \n", tokenList.line[i]);
			        errorCount++;
					
				}
			}
			
			
		}
		
		
		// chck add
		if(tokenList._token[i].type==TOKEN_ADD){
			i++;
			if (tokenList._token[i].type!=TOKEN_IDENTIFIER){
					printf("Syntax Error at line %d: syntax of ADD  \n", tokenList.line[i]);
			        errorCount++;
			}else{
				i++;
				if(tokenList._token[i].type!=TOKEN_COMMA){
						printf("Syntax Error at line %d: syntax of ADD  \n", tokenList.line[i]);
			        errorCount++;
				}else {
					i++;
						if (tokenList._token[i].type!=TOKEN_IDENTIFIER && tokenList._token[i].type!=TOKEN_INT && tokenList._token[i].type!=TOKEN_REAL){
					printf("Syntax Error at line %d: syntax of ADD  \n", tokenList.line[i]);
			        errorCount++;
			}else{
				i++;
					if(tokenList._token[i].type!=TOKEN_COMMA){
						printf("Syntax Error at line %d: syntax of ADD  \n", tokenList.line[i]);
			        errorCount++;
				}else{
					i++;
					if(tokenList._token[i].type!=TOKEN_IDENTIFIER && tokenList._token[i].type!=TOKEN_INT && tokenList._token[i].type!=TOKEN_REAL)
					{
							printf("Syntax Error at line %d: syntax de ADD  \n", tokenList.line[i]);
			        errorCount++;
					}else{
						i++;
						if (tokenList._token[i].type!=TOKEN_FIN_LIGNE){
								printf("Syntax Error at line %d: '$' is missed  \n", tokenList.line[i]);
			        errorCount++;
						}
						
					}
				}
				
			}
					
				}
			}
			
		}
		
		//chck Div 
		 if(tokenList._token[i].type==TOKEN_DIV){
			i++;
			if (tokenList._token[i].type!=TOKEN_IDENTIFIER){
					printf("Syntax Error at line %d: syntax of DIV  \n", tokenList.line[i]);
			        errorCount++;
			}else{
				i++;
				if(tokenList._token[i].type!=TOKEN_COMMA){
						printf("Syntax Error at line %d: syntax of DIV  \n", tokenList.line[i]);
			        errorCount++;
				}else {
					i++;
						if (tokenList._token[i].type!=TOKEN_IDENTIFIER && tokenList._token[i].type!=TOKEN_INT && tokenList._token[i].type!=TOKEN_REAL){
					printf("Syntax Error at line %d: syntax of DIV  \n", tokenList.line[i]);
			        errorCount++;
			}else{
				i++;
					if(tokenList._token[i].type!=TOKEN_COMMA){
						printf("Syntax Error at line %d: syntax of DIV  \n", tokenList.line[i]);
			        errorCount++;
				}else{
					i++;
					if(tokenList._token[i].type!=TOKEN_IDENTIFIER && tokenList._token[i].type!=TOKEN_INT && tokenList._token[i].type!=TOKEN_REAL)
					{
							printf("Syntax Error at line %d: syntax de DIV  \n", tokenList.line[i]);
			        errorCount++;
					}else{
						i++;
						if (tokenList._token[i].type!=TOKEN_FIN_LIGNE){
								printf("Syntax Error at line %d: '$' is missed  \n", tokenList.line[i]);
			        errorCount++;
						}
						
					}
				}
				
			}
					
				}
			}
			
		}
		
		
		//check Mul
		
		if(tokenList._token[i].type==TOKEN_MUL){
			i++;
			if (tokenList._token[i].type!=TOKEN_IDENTIFIER){
					printf("Syntax Error at line %d: syntax of MUL  \n", tokenList.line[i]);
			        errorCount++;
			}else{
				i++;
				if(tokenList._token[i].type!=TOKEN_COMMA){
						printf("Syntax Error at line %d: syntax of MUL  \n", tokenList.line[i]);
			        errorCount++;
				}else {
					i++;
						if (tokenList._token[i].type!=TOKEN_IDENTIFIER && tokenList._token[i].type!=TOKEN_INT && tokenList._token[i].type!=TOKEN_REAL){
					printf("Syntax Error at line %d: syntax of MUL  \n", tokenList.line[i]);
			        errorCount++;
			}else{
				i++;
					if(tokenList._token[i].type!=TOKEN_COMMA){
						printf("Syntax Error at line %d: syntax of MUL  \n", tokenList.line[i]);
			        errorCount++;
				}else{
					i++;
					if(tokenList._token[i].type!=TOKEN_IDENTIFIER && tokenList._token[i].type!=TOKEN_INT && tokenList._token[i].type!=TOKEN_REAL)
					{
							printf("Syntax Error at line %d: syntax de MUL  \n", tokenList.line[i]);
			        errorCount++;
					}else{
						i++;
						if (tokenList._token[i].type!=TOKEN_FIN_LIGNE){
								printf("Syntax Error at line %d: '$' is missed  \n", tokenList.line[i]);
			        errorCount++;
						}
						
					}
				}
				
			}
					
				}
			}
			
		}
		
		//check Sub
		
		if(tokenList._token[i].type==TOKEN_SUB){
			i++;
			if (tokenList._token[i].type!=TOKEN_IDENTIFIER){
					printf("Syntax Error at line %d: syntax of SUB  \n", tokenList.line[i]);
			        errorCount++;
			}else{
				i++;
				if(tokenList._token[i].type!=TOKEN_COMMA){
						printf("Syntax Error at line %d: syntax of SUB  \n", tokenList.line[i]);
			        errorCount++;
				}else {
					i++;
						if (tokenList._token[i].type!=TOKEN_IDENTIFIER && tokenList._token[i].type!=TOKEN_INT && tokenList._token[i].type!=TOKEN_REAL){
					printf("Syntax Error at line %d: syntax of SUB  \n", tokenList.line[i]);
			        errorCount++;
			}else{
				i++;
					if(tokenList._token[i].type!=TOKEN_COMMA){
						printf("Syntax Error at line %d: syntax of SUB  \n", tokenList.line[i]);
			        errorCount++;
				}else{
					i++;
					if(tokenList._token[i].type!=TOKEN_IDENTIFIER && tokenList._token[i].type!=TOKEN_INT && tokenList._token[i].type!=TOKEN_REAL)
					{
							printf("Syntax Error at line %d: syntax de SUB  \n", tokenList.line[i]);
			        errorCount++;
					}else{
						i++;
						if (tokenList._token[i].type!=TOKEN_FIN_LIGNE){
								printf("Syntax Error at line %d: '$' is missed  \n", tokenList.line[i]);
			        errorCount++;
						}
						
					}
				}
				
			}
					
				}
			}
			
		}
		
	
          
		
	
}

void analyseur_syn(list tokenList)
{

	//example de letulisation des token
	//pour snk begin cest TOKEN_SNK_BEGIN donc
	int i =0;
	int j=1;
	int line=1;

	
	
	while(i<tokenList.nbrToken)
	{
		if(i==0 && tokenList._token[i].type!=TOKEN_SNK_BEGIN)
		{
		printf("Syntax Error at line %d: Program must start with 'Snk_Begin' \n", tokenList.line[i]);
		
                    errorCount++;
                    
		}
		if (i==(tokenList.nbrToken-1 ) && tokenList._token[i].type!=TOKEN_SNK_END){
			
		printf("Syntax Error at line %d: Program must End with 'Snk_End' \n", tokenList.line[i]);
		
                    errorCount++;
                  
		}
		if (tokenList._token[i].type==TOKEN_SNK_BEGIN ){
			if(tokenList._token[i+1].type==TOKEN_FIN_LIGNE){
				printf("Syntax Error at line %d: '$' extra   \n", tokenList.line[i]);
		
                    errorCount++;
				
			}
		
                  
		}
			if (tokenList._token[i].type==TOKEN_SNK_END && tokenList._token[i+1].type==TOKEN_FIN_LIGNE){
			printf("Syntax Error at line %d: '$' extra   \n", tokenList.line[i]);
		
                    errorCount++;
                 
		}
		check(i,tokenList);
		/*	if (tokenList._token[i].type==TOKEN_BEGIN && tokenList._token[i+1].type==TOKEN_FIN_LIGNE){
				
			printf("Syntax Error at line %d: '$' extra   \n", tokenList.line[i]);
		
                    errorCount++;
                    break;
		}
			if (tokenList._token[i].type==TOKEN_END && tokenList._token[i+1].type==TOKEN_FIN_LIGNE){
			printf("Syntax Error at line %d: '$' extra   \n", tokenList.line[i]);
		
                    errorCount++;
                    break;
		}
			if (tokenList._token[i].type==TOKEN_ELSE && tokenList._token[i+1].type==TOKEN_FIN_LIGNE){
			printf("Syntax Error at line %d: '$' extra   \n", tokenList.line[i]);
		
                    errorCount++;
                    break;
		}*/
		
		
		
		
		
		
		
	
		     if (tokenList._token[i].type == TOKEN_IF) {
           		 // Vérifier la syntaxe de la structure "if"
           		 
            	 i++;
            	
           		 if (tokenList._token[i].type == TOKEN_OPEN_BRACKET) 
					{
               				 i++;

               				 // Vérifier l'expression conditionnelle
               				 // Vous devrez implémenter une logique pour évaluer l'expression conditionnelle ici
               				 // Vous pouvez utiliser une pile (stack) ou un arbre d'expression pour évaluer l'expression

                			while (tokenList._token[i].type != TOKEN_CLOSE_BRACKET) 
							{
                   				 i++;
                   				 if((tokenList._token[i].type == TOKEN_ELSE || tokenList._token[i].type == TOKEN_BEGIN) && tokenList._token[i].type != TOKEN_CLOSE_BRACKET){
                    	    	printf("Syntax Error at line %d: ']' missed \n", tokenList.line[i]);
                    			errorCount++;
												}
                			}
                			i++;
                			if (tokenList._token[i].type == TOKEN_BEGIN)
							{
                    			// Bloc "if" correct, continuer avec le bloc "else" si présent
                   				 i++;
                   				 while (tokenList._token[i].type != TOKEN_END) {
                        			i++;
                        			check(i,tokenList);
                        			if(tokenList._token[i].type==TOKEN_ELSE){
                        					printf("Syntax Error at line %d: syntax END missed \n", tokenList.line[i]);
			        errorCount++;
									}
                   					 }
                    			i++;
                    			if (tokenList._token[i].type == TOKEN_ELSE) 
								{
                        				i++;
                       	 				if (tokenList._token[i].type == TOKEN_BEGIN) {
                            			// Bloc "else" correct
                           				 i++;
                           				 while (tokenList._token[i].type != TOKEN_END) {
                               			 i++;
                            				}
                            			i++;
                        				} else {
                           				 // Erreur, bloc "else" attendu
                           				 printf("Syntax Error at line %d: 'begin' expected after 'else'\n", tokenList.line[i]);
                            				errorCount++;
                        					}
                   					 }
              		  } else {
                    	// Erreur, bloc "begin" attendu après la condition de l'if
                   		 printf("Syntax Error at line %d: 'begin' expected after 'if' condition\n", tokenList.line[i]);
                    	errorCount++;}
                
             } else {
                // Erreur, parenthèses ouvrantes attendues après le "if"
                printf("Syntax Error at line %d: '[' expected after 'if'\n", tokenList.line[i]);
                errorCount++;
                
               }
    }
    
    // check while
    
     if (tokenList._token[i].type == TOKEN_WHILE) {
           		 // Vérifier la syntaxe de la structure "if"
           		 
            	 i++;
            	
           		 if (tokenList._token[i].type == TOKEN_OPEN_BRACKET) 
					{
               				 i++;

               				 // Vérifier l'expression conditionnelle
               				 // Vous devrez implémenter une logique pour évaluer l'expression conditionnelle ici
               				 // Vous pouvez utiliser une pile (stack) ou un arbre d'expression pour évaluer l'expression

                			while (tokenList._token[i].type != TOKEN_CLOSE_BRACKET) 
							{
                   				 i++;
                   				 if( tokenList._token[i].type == TOKEN_BEGIN && tokenList._token[i].type != TOKEN_CLOSE_BRACKET){
                    	    	printf("Syntax Error at line %d: ']' missed \n", tokenList.line[i]);
                    			errorCount++;
												}
                			}
                			i++;
                			if (tokenList._token[i].type == TOKEN_BEGIN)
							{
                    			// Bloc "while" correct, continuer avec le bloc "else" si présent
                   				 i++;
                   				 while (tokenList._token[i].type != TOKEN_END) {
                        			i++;
                        			check(i,tokenList);
                   					 }
                    			
                            		
                        				
                   					 
              		  } else {
                    	// Erreur, bloc "begin" attendu après la condition de l'if
                   		 printf("Syntax Error at line %d: 'begin' expected after 'if' condition\n", tokenList.line[i]);
                    	errorCount++;
                
             } }else {
                // Erreur, parenthèses ouvrantes attendues après le "if"
                printf("Syntax Error at line %d: '[' expected after 'if'\n", tokenList.line[i]);
                errorCount++;
                
               }
    }
    /*
    // chek Snk_int 
    if(tokenList._token[i].type==TOKEN_DEC_INT )
	{
	
		i++;
	if(tokenList._token[i].type==TOKEN_IDENTIFIER ){
		id id_int;
		strcpy(id_int.name,tokenList._token[i].value);
		id_int.type=TOKEN_INT;
	    strcpy(id_int.value , "0");
		
	i++;
	
		while(tokenList._token[i].type!=TOKEN_FIN_LIGNE){
					if(tokenList._token[i].type==TOKEN_COMMA){
					i++;
				}
			if(tokenList._token[i].type!=TOKEN_IDENTIFIER){
			printf("Syntax Error at line %d: error syntaxe of Snk_int   \n", tokenList.line[i]);
			errorCount++;
			i++;
			}
			if(tokenList._token[i].type==TOKEN_IDENTIFIER ){
				
					strcpy(id_int.name,tokenList._token[i].value);
		            id_int.type=TOKEN_INT;
	                strcpy(id_int.value , "0");
				
				i++;
				if(tokenList._token[i].type!=TOKEN_COMMA && tokenList._token[i].type!=TOKEN_FIN_LIGNE){
					printf("Syntax Error at line %d: strectur of Snk_int is false   \n", tokenList.line[i]);
					errorCount++;
				}
			
			
				}
			
				
				
			}
			
			
			
		}
		else{
			printf("Syntax Error at line %d: error syntaxe Snk_int   \n", tokenList.line[i]);
			errorCount++;
		}}
		
    	
	
           // chek  Snk_real
       if(tokenList._token[i].type==TOKEN_DEC_REAL )
	{
	
		i++;
	if(tokenList._token[i].type==TOKEN_IDENTIFIER ){
		id id_real;
		strcpy(id_real.name,tokenList._token[i].value);
		id_real.type=TOKEN_REAL;
	    strcpy(id_real.value , "0");
		
	i++;
	
		while(tokenList._token[i].type!=TOKEN_FIN_LIGNE){
					if(tokenList._token[i].type==TOKEN_COMMA){
					i++;
				}
			if(tokenList._token[i].type!=TOKEN_IDENTIFIER){
			printf("Syntax Error at line %d: error syntaxe of Snk_Real   \n", tokenList.line[i]);
			errorCount++;
			i++;
			}
			if(tokenList._token[i].type==TOKEN_IDENTIFIER ){
					strcpy(id_real.name,tokenList._token[i].value);
		            id_real.type=TOKEN_REAL;
	                strcpy(id_real.value , "0");
				i++;
				if(tokenList._token[i].type!=TOKEN_COMMA && tokenList._token[i].type!=TOKEN_FIN_LIGNE){
					printf("Syntax Error at line %d: strectur of Snk_Real is false   \n", tokenList.line[i]);
					errorCount++;
				}
			
			
				}
			
				
				
			}
			
			
			
		}
		else{
			printf("Syntax Error at line %d: error syntaxe Snk_Real  \n", tokenList.line[i]);
			errorCount++;
		}}
		//check syntaxe of Set
    	if(tokenList._token[i].type==TOKEN_SET){
    		i++;
    		if(tokenList._token[i].type!=TOKEN_IDENTIFIER){
    				printf("Syntax Error at line %d: error syntaxe Set  \n", tokenList.line[i]);
			         errorCount++;
    			
			}
			else{
				i++;
				if(tokenList._token[i].type!=TOKEN_INT && tokenList._token[i].type!=TOKEN_REAL){
						printf("Syntax Error at line %d: error syntaxe Set  \n", tokenList.line[i]);
			errorCount++;
				}
				else{i++;
				if(tokenList._token[i].type!=TOKEN_FIN_LIGNE){
						printf("Syntax Error at line %d: $ is missed  \n", tokenList.line[i]);
			errorCount++;
				}
				}
			}
    		
		}
		
		//check syntaxe of get
		if (tokenList._token[i].type==TOKEN_GET){
			i++;
			if (tokenList._token[i].type!=TOKEN_IDENTIFIER){
					printf("Syntax Error at line %d: syntax de Get  \n", tokenList.line[i]);
			        errorCount++;
				
			}else{
				i++;
				if(tokenList._token[i].type!=TOKEN_FROM ){
						printf("Syntax Error at line %d: syntax de Get  \n", tokenList.line[i]);
			        errorCount++;
					
				}else{
					i++;
						if (tokenList._token[i].type!=TOKEN_IDENTIFIER){
					printf("Syntax Error at line %d: syntax de Get  \n", tokenList.line[i]);
			        errorCount++;
				
			          }else{
			          	i++;
			          	if(tokenList._token[i].type!=TOKEN_FIN_LIGNE){
			          			printf("Syntax Error at line %d: '$' is missed  \n", tokenList.line[i]);
			                  errorCount++;
						  }
			          	
					  }
					
				}
			}
			
		}
		//check Snk_print 
		
		if (tokenList._token[i].type==TOKEN_SNK_PRINT){
			i++;
			if (tokenList._token[i].type!=TOKEN_IDENTIFIER && tokenList._token[i].type!=TOKEN_STRING){
					printf("Syntax Error at line %d: syntax de Snk_print  \n", tokenList.line[i]);
			        errorCount++;
			}
			if(tokenList._token[i].type==TOKEN_IDENTIFIER){
				i++;
				while(tokenList._token[i].type!=TOKEN_FIN_LIGNE){
					if(tokenList._token[i].type==TOKEN_COMMA){
					i++;
				}
			if(tokenList._token[i].type!=TOKEN_IDENTIFIER){
			printf("Syntax Error at line %d: error syntaxe of Snk_print   \n", tokenList.line[i]);
			errorCount++;
			i++;
			}
			if(tokenList._token[i].type==TOKEN_IDENTIFIER ){
					
				i++;
				if(tokenList._token[i].type!=TOKEN_COMMA && tokenList._token[i].type!=TOKEN_FIN_LIGNE){
					printf("Syntax Error at line %d: strectur of Snk_print is false   \n", tokenList.line[i]);
					errorCount++;
				}
			
			
				}
					
				}
				
			}
			if (tokenList._token[i].type==TOKEN_STRING){
				i++;
				if(tokenList._token[i].type!=TOKEN_FIN_LIGNE){
						printf("Syntax Error at line %d: '$' is missed  \n", tokenList.line[i]);
			        errorCount++;
					
				}
			}
			
			
		}
		
		
		// chck add
		if(tokenList._token[i].type==TOKEN_ADD){
			i++;
			if (tokenList._token[i].type!=TOKEN_IDENTIFIER){
					printf("Syntax Error at line %d: syntax of ADD  \n", tokenList.line[i]);
			        errorCount++;
			}else{
				i++;
				if(tokenList._token[i].type!=TOKEN_COMMA){
						printf("Syntax Error at line %d: syntax of ADD  \n", tokenList.line[i]);
			        errorCount++;
				}else {
					i++;
						if (tokenList._token[i].type!=TOKEN_IDENTIFIER && tokenList._token[i].type!=TOKEN_INT && tokenList._token[i].type!=TOKEN_REAL){
					printf("Syntax Error at line %d: syntax of ADD  \n", tokenList.line[i]);
			        errorCount++;
			}else{
				i++;
					if(tokenList._token[i].type!=TOKEN_COMMA){
						printf("Syntax Error at line %d: syntax of ADD  \n", tokenList.line[i]);
			        errorCount++;
				}else{
					i++;
					if(tokenList._token[i].type!=TOKEN_IDENTIFIER && tokenList._token[i].type!=TOKEN_INT && tokenList._token[i].type!=TOKEN_REAL)
					{
							printf("Syntax Error at line %d: syntax de ADD  \n", tokenList.line[i]);
			        errorCount++;
					}else{
						i++;
						if (tokenList._token[i].type!=TOKEN_FIN_LIGNE){
								printf("Syntax Error at line %d: '$' is missed  \n", tokenList.line[i]);
			        errorCount++;
						}
						
					}
				}
				
			}
					
				}
			}
			
		}
		
		//chck Div 
		 if(tokenList._token[i].type==TOKEN_DIV){
			i++;
			if (tokenList._token[i].type!=TOKEN_IDENTIFIER){
					printf("Syntax Error at line %d: syntax of DIV  \n", tokenList.line[i]);
			        errorCount++;
			}else{
				i++;
				if(tokenList._token[i].type!=TOKEN_COMMA){
						printf("Syntax Error at line %d: syntax of DIV  \n", tokenList.line[i]);
			        errorCount++;
				}else {
					i++;
						if (tokenList._token[i].type!=TOKEN_IDENTIFIER && tokenList._token[i].type!=TOKEN_INT && tokenList._token[i].type!=TOKEN_REAL){
					printf("Syntax Error at line %d: syntax of DIV  \n", tokenList.line[i]);
			        errorCount++;
			}else{
				i++;
					if(tokenList._token[i].type!=TOKEN_COMMA){
						printf("Syntax Error at line %d: syntax of DIV  \n", tokenList.line[i]);
			        errorCount++;
				}else{
					i++;
					if(tokenList._token[i].type!=TOKEN_IDENTIFIER && tokenList._token[i].type!=TOKEN_INT && tokenList._token[i].type!=TOKEN_REAL)
					{
							printf("Syntax Error at line %d: syntax de DIV  \n", tokenList.line[i]);
			        errorCount++;
					}else{
						i++;
						if (tokenList._token[i].type!=TOKEN_FIN_LIGNE){
								printf("Syntax Error at line %d: '$' is missed  \n", tokenList.line[i]);
			        errorCount++;
						}
						
					}
				}
				
			}
					
				}
			}
			
		}
		
		
		//check Mul
		
		if(tokenList._token[i].type==TOKEN_MUL){
			i++;
			if (tokenList._token[i].type!=TOKEN_IDENTIFIER){
					printf("Syntax Error at line %d: syntax of MUL  \n", tokenList.line[i]);
			        errorCount++;
			}else{
				i++;
				if(tokenList._token[i].type!=TOKEN_COMMA){
						printf("Syntax Error at line %d: syntax of MUL  \n", tokenList.line[i]);
			        errorCount++;
				}else {
					i++;
						if (tokenList._token[i].type!=TOKEN_IDENTIFIER && tokenList._token[i].type!=TOKEN_INT && tokenList._token[i].type!=TOKEN_REAL){
					printf("Syntax Error at line %d: syntax of MUL  \n", tokenList.line[i]);
			        errorCount++;
			}else{
				i++;
					if(tokenList._token[i].type!=TOKEN_COMMA){
						printf("Syntax Error at line %d: syntax of MUL  \n", tokenList.line[i]);
			        errorCount++;
				}else{
					i++;
					if(tokenList._token[i].type!=TOKEN_IDENTIFIER && tokenList._token[i].type!=TOKEN_INT && tokenList._token[i].type!=TOKEN_REAL)
					{
							printf("Syntax Error at line %d: syntax de MUL  \n", tokenList.line[i]);
			        errorCount++;
					}else{
						i++;
						if (tokenList._token[i].type!=TOKEN_FIN_LIGNE){
								printf("Syntax Error at line %d: '$' is missed  \n", tokenList.line[i]);
			        errorCount++;
						}
						
					}
				}
				
			}
					
				}
			}
			
		}
		
		//check Sub
		
		if(tokenList._token[i].type==TOKEN_SUB){
			i++;
			if (tokenList._token[i].type!=TOKEN_IDENTIFIER){
					printf("Syntax Error at line %d: syntax of SUB  \n", tokenList.line[i]);
			        errorCount++;
			}else{
				i++;
				if(tokenList._token[i].type!=TOKEN_COMMA){
						printf("Syntax Error at line %d: syntax of SUB  \n", tokenList.line[i]);
			        errorCount++;
				}else {
					i++;
						if (tokenList._token[i].type!=TOKEN_IDENTIFIER && tokenList._token[i].type!=TOKEN_INT && tokenList._token[i].type!=TOKEN_REAL){
					printf("Syntax Error at line %d: syntax of SUB  \n", tokenList.line[i]);
			        errorCount++;
			}else{
				i++;
					if(tokenList._token[i].type!=TOKEN_COMMA){
						printf("Syntax Error at line %d: syntax of SUB  \n", tokenList.line[i]);
			        errorCount++;
				}else{
					i++;
					if(tokenList._token[i].type!=TOKEN_IDENTIFIER && tokenList._token[i].type!=TOKEN_INT && tokenList._token[i].type!=TOKEN_REAL)
					{
							printf("Syntax Error at line %d: syntax de SUB  \n", tokenList.line[i]);
			        errorCount++;
					}else{
						i++;
						if (tokenList._token[i].type!=TOKEN_FIN_LIGNE){
								printf("Syntax Error at line %d: '$' is missed  \n", tokenList.line[i]);
			        errorCount++;
						}
						
					}
				}
				
			}
					
				}
			}
			
		}
		
	
          */
          
        i++;
	
	}

	   if (errorCount == 0) {
        printf("Syntax analysis completed successfully.\n");
    } else {
        printf("Syntax analysis completed with %d error(s).\n", errorCount);
    }
	//donc tas une liste de tokens
	//bone chance u will nead it :)
}


#endif
