#include "automata.h"
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <stdio.h>

#ifdef _WIN32
#include <conio.h>
#include <windows.h>
#else
#include <stdio.h>
#define clrscr() printf("\e[1;1H\e[2J")
#endif

int count = 1;
bool flagToOut = false;

int main(){
    enum STATE state = N_0;
    bool exit = false;

    char currentCharacter;
    char* userInput;
    char *palabra = "";

    userInput = malloc(15 * sizeof(char));

    while (!flagToOut) {
        count = 1;
        printf("ER dada: [01]\\.[0-9]?|[01]*B\n");
	printf("Centinela: #\n");
        printf("Ingresa la cadena a evaluar:");
        scanf("%s", userInput);
        printf("\nLas palabras del lenguaje reconocidas son: \n");

        for (int i = 0; i < (strlen(userInput)); i++) {
            currentCharacter = userInput[i];

            if (currentCharacter == CENTINELA) {
                if ((state == N_3) || (state == N_4)) {
                    printf("\t%d) %s \n ", count, palabra);
                    count++;
                    palabra = "";
                    state = N_0;
                }

                palabra = "";
                exit = false;
            }

            else {
                if (exit == false) { 
                    switch (state) {
                    case N_0:
                        state = nodo_0(currentCharacter, palabra);
                        break;
                    case N_1:
                        state = nodo_1(currentCharacter, palabra);
                        break;
                    case N_2:
                        state = nodo_2(currentCharacter, palabra);
                        break;
                    case N_3:
                        state = nodo_3(currentCharacter, palabra);
                        break;
                    case N_4:
                        state = nodo_4(currentCharacter, palabra);
                        break;
                    }
                    if (state == N_0)
                        exit = true;
                }
            }
        }
        printf("------------------------------------------------ \n");
        printf("¿Desea ingresar otra cadena (S/N)?");
        if ((getchar() == 'N') || (getchar() == 'n'))
            break;
    }
    free(userInput);
    return 0;
}