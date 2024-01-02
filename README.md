# Snake Compiler

Le compilateur Snake est un projet visant à réaliser l'analyseur lexical, syntaxique et sémantique d'un langage d'un langage fictif, ainsi qu'une interface graphique pour faciliter la compilation du langage.

## Fonctionnalités

### Analyseur
- **Analyseur lexical**: Le programme identifie les tokens (mots-clés, identificateurs, opérateurs, etc.) dans le code source Snake.
- **Analyseur syntaxique**: Il vérifie la structure du code pour s'assurer qu'il respecte la grammaire définie pour le langage.
- **Analyseur sémantique**: Effectue des vérifications supplémentaires pour garantir la cohérence et la validité du code.

### Langage Snake (exemple)
```snake
Snk_Begin
    Snk_Int i, j, x1, x2, somme $
    Snk_Real x3 $
    Set i 33 $
    If [ i<50]
        Set x1 10 $
    Else
    Begin
        Get x2 from x3 $
        Set k 43.5 $
        Snk_Print x2, x3 $
    End
    Snk_Print " Hello :)"  $
    Snk_Print i,j $
    While[i<50]
    Begin
        $$ Commentaire sur plusieurs lignes est # bla bla #
        # Commentaires multi-lignes
         comme ceci #

        Add somme,i,1$
        Snk_Print i$
    End 
$$ Ceci est un commentaire sur une ligne
Snk_End
```
## Interface Graphique

L'interface utilisateur est réalisée en utilisant Godot 4 pour fournir une expérience conviviale pour compiler le langage Snake.

## Utilisation

### Prérequis

- **Godot Engine 4**: Pour exécuter l'interface graphique.

### Compilation du code Snake

1. Cloner le dépôt GitHub.
2. Ouvrir le projet dans Godot 4.
3. Utiliser l'interface graphique pour charger et compiler les fichiers écrits en Snake.


## Licence

Ce projet est sous licence [GNU](). Consultez le fichier LICENSE pour plus de détails.

