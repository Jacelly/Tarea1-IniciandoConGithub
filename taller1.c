/* tarea.c : creacion de menu sencillo

 * Autor: Jimmy Alejandro Celly Azanza

 * Fecha: 27/10/17

*/

#include <stdio.h>

#define MAXLINE 1000 /* maximum input line length */

int getline2(char line[], int maxline);

void copy(char to[], char from[]);

int cuenta(char cadena[]);

int cuenta_digitos(char cadena[]);

void menu();

int leer_Opcion();

/* print the longest input line */

int main()

{

    int len; /* current line length */

    int max; /* maximum length seen so far */

    char line[MAXLINE]; /* current input line */

    char longest[MAXLINE]; /* longest line saved here */

    max = 0;

    int opcion;

    printf("Ingresar linea(s) de texto:\n");

    while ((len = getline2(line, MAXLINE)) > 0)

        if (len > max) {

            max = len;

            copy(longest, line);

        }

    if (max > 0) /* there was a line */

        printf("\E[36m La cadena mas larga es: %s", longest);

        

   /* ******************************************************************************** */

   menu();

   opcion=leer_Opcion();

   while(opcion!=3)

   {

	   switch(opcion){

	      case 1:

		printf("\033[31m La cadena tiene %d caracteres\n", cuenta(longest)-1);

		break;

	      case 2:

		printf("\033[31m La cadena tiene %d dígitos\n", cuenta_digitos(longest));

		break;

	   }

	   menu();

   	   opcion=leer_Opcion();

   }

   /* ********************************************************************************* */

   return 0;

    

}



/* getline2: read a line into s, return length */

int getline2(char s[],int lim)

{

    int c, i;

    for (i=0; i < lim-1 && (c=getchar())!=EOF && c!='\n'; ++i)

        s[i] = c;

    if (c == '\n') {

        s[i] = c;

        ++i;

    }

    s[i] = '\0';

    return i;

}



/* copy: copy 'from' into 'to'; assume to is big enough */

void copy(char to[], char from[])

{

    int i;

    i = 0;

    while ((to[i] = from[i]) != '\0')

        ++i;

}



/* cuenta: cuenta los caracteres de la cadena seleccionada */

int cuenta(char cadena[])

{

    int i;

    i = 0;

    while (cadena[i] != '\0')

        ++i;

    return i;

}



/* cuenta_digitos: cuenta los digitos de la cadena seleccionada */

int cuenta_digitos(char cadena[])

{

    int i, digitos;

    i = 0;

    digitos = 0;

    while (cadena[i] != '\0')

    {

        if (cadena[i] >= '0' && cadena[i] <= '9')

            ++digitos;

        ++i;

    }

    return digitos;

}

/* menu sencillo del programa*/

void menu()

{

    printf("\033[32m ***************MENU*****************\n");

    printf("\033[34m[1] Numero de caracteres\n");

    printf("\033[34m[2] Numero de digitos\n");

    printf("\033[34m[3] Salir\n");

    printf("\033[33m Ingresar una opcion:\n");

   

}

/* leer opcion elegida del menu*/

int leer_Opcion()

{

	int opcion;

	scanf("%d",&opcion);

    	return opcion;

}

