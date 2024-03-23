## Parte obligatoria
\
\
Tu programa deberá ejecutarse de la siguiente forma:\
* **./pipex archivo1 comando1 comando2 archivo2**\

Deberá utilizar 4 argumentos:\
* **archivo1** y **archivo2** son nombres de arhivos.\
* **comando1** y **comando2** son comandos de shell con sus respectivos parámetros.

### Requisitos
\
Tu proyecto debe cumplir los siguientes requisitos:\
* Debes entregar un **Makefile** que compile tus archivos fuente. No debe hacer relink.\
* Debes gestionar los errores minuciosamente. De ninguna forma tu programa debe
salir de forma inesperada (*segmentation fault, bus error, double free, y similares*).\
* Tu programa no debee tener **fugas de memoria**.\
  
\
Si teienes alguna duda, gestiona los errores como lo hace el comando de shell:
* **<file1 cmd1 | cmd2 >file2**

## Parte extra
\
\
Gestionar múltiples pipes.\
*	**$> ./pipex archivo1 comando1 comando2 comando3 ... comandon archivo2**\
  
Deberá comportarse así:\
*	**$> < archivo1 comando1 | comando2 | comando3 ... | comandon > archivo2**\
  
Aceptar << y >> cuando el primer parámetro es “here_doc”:\
*	**$> ./pipex here\_doc LIMITADOR comando comando1 archivo**\
  
Deberá comportarse así:\
*	**comando << LIMITADOR | comando1 >> archivo**
