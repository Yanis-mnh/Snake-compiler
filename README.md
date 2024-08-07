# Snake Compiler

The Snake Compiler is a project aimed at creating the lexical, syntactic, and semantic analyzer for a fictional language, as well as a graphical interface to facilitate the compilation of the language.

## Features

### Analyzer
- **Lexical Analyzer:** The program identifies tokens (keywords, identifiers, operators, etc.) in the Snake source code.
- **Syntax Analyzer:** It checks the code structure to ensure it adheres to the grammar defined for the language.
- **Semantic Analyzer:** Performs additional checks to ensure the code's consistency and validity.

### Snake Language (Example)
```snake
Snk_Begin
    Snk_Int i, j, x1, x2, sum $
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
        $$ Multi-line comment is # bla bla #
        # Multi-line comments
         like this #

        Add sum,i,1$
        Snk_Print i$
    End 
$$ This is a single-line comment
Snk_End
```

## Graphical Interface

The user interface is created using Godot 4 to provide a user-friendly experience for compiling the Snake language.

## Usage

### Prerequisites

- **Godot Engine 4:** To run the graphical interface.

### Compiling Snake Code

1. Clone the GitHub repository.
2. Open the project in Godot 4.
3. Use the graphical interface to load and compile Snake code files.

## License

This project is licensed under [GNU](). See the LICENSE file for details.
