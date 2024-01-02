#ifndef __potato__
	#define __potato__
	
	#include <stdio.h>
	#include <stdlib.h>
	#include <string.h>
	#include "../analyse lex/datatype.h"
	#include "../analyse lex/tokenList.h"

// ...
typedef struct {
    tokenType type;
    // Ajouter d'autres champs pour les besoins spécifiques de l'arbre syntaxique
} SyntaxTreeNode;

SyntaxTreeNode* parse(list tokenList, int* currentTokenIndex);

// Fonction utilitaire pour afficher les erreurs
void syntaxError() {
    printf("Erreur de syntaxe!\n");
}

// Fonction pour reconnaître les mots-clés
int matchKeyword(list tokenList, int* currentTokenIndex, tokenType expectedToken) {
    if (tokenList._token[*currentTokenIndex].type == expectedToken) {
        (*currentTokenIndex)++;
        return 1;
    }
    return 0;
}

// Fonction pour reconnaître les identificateurs
int matchIdentifier(list tokenList, int* currentTokenIndex) {
    if (tokenList._token[*currentTokenIndex].type == TOKEN_IDENTIFIER) {
        (*currentTokenIndex)++;
        return 1;
    }
    return 0;
}

// Fonction pour reconnaître les valeurs numériques
int matchValue(list tokenList, int* currentTokenIndex) {
    if (tokenList._token[*currentTokenIndex].type == TOKEN_INT || 
        tokenList._token[*currentTokenIndex].type == TOKEN_REAL) {
        (*currentTokenIndex)++;
        return 1;
    }
    return 0;
}

SyntaxTreeNode* parseStatement(list tokenList, int* currentTokenIndex) {
    tokenType currentTokenType = tokenList._token[*currentTokenIndex].type;

    // Identifier le type de déclaration
    if (matchKeyword(tokenList, currentTokenIndex, TOKEN_DEC_INT) ||
        matchKeyword(tokenList, currentTokenIndex, TOKEN_DEC_REAL)) {
        
        // Vérifier les identificateurs
        while (matchIdentifier(tokenList, currentTokenIndex)) {
            if (tokenList._token[*currentTokenIndex].type == TOKEN_FIN_LIGNE) {
                (*currentTokenIndex)++;
                break;
            } else if (tokenList._token[*currentTokenIndex].type == TOKEN_COMMA) {
                (*currentTokenIndex)++;
            } else {
                syntaxError();
                return NULL;
            }
        }
        return parseStatement(tokenList, currentTokenIndex);
    } else if (matchKeyword(tokenList, currentTokenIndex, TOKEN_SET)) {
        // Logique pour la déclaration Set
        // ...
    } else if (matchKeyword(tokenList, currentTokenIndex, TOKEN_IF)) {
        // Logique pour la déclaration If
        // ...
    }
    // Ajouter d'autres conditions pour les déclarations restantes

    return NULL;
}

SyntaxTreeNode* parse(list tokenList, int* currentTokenIndex) {
    while (*currentTokenIndex < tokenList.nbrToken) {
        if (parseStatement(tokenList, currentTokenIndex) == NULL) {
            syntaxError();
            return NULL;
        }
    }
    return (SyntaxTreeNode*)malloc(sizeof(SyntaxTreeNode));
}

void analyseur_syn(list token) {
    int currentTokenIndex = 0;
    SyntaxTreeNode* syntaxTree = parse(token, &currentTokenIndex);

    if (syntaxTree != NULL) {
        // Travailler avec l'arbre syntaxique généré
    } else {
        syntaxError();
    }
}



#endif
