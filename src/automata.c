#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include "automata.h"

static char languageA[] = {'0', '1'};
static int languageASize = 2;

static char languageB[] = {'.'};
static int languageBSize = 1;

static char languageC[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
static int languageCSize = 10;

static char languageD[] = {'B'};
static int languageDSize = 1;

bool charBelongs(char, char*, int);
char* str_concat(char*, char);
void word_to_file(char);

enum STATE nodo_0(char c, char* palabra) {
    enum STATE state;
    char* aux;

    if (charBelongs(c, languageD, languageDSize))
        state = N_4;

    else if (charBelongs(c, languageA, languageASize))
        state = N_1;

    else
        state = N_0;
    
    return state;
}

enum STATE nodo_1(char c, char* palabra) {
    enum STATE state;
    char* aux;

    if (charBelongs(c, languageD, languageDSize))
        state = N_4;

    else if (charBelongs(c, languageB, languageBSize))
        state = N_3;

    else if (charBelongs(c, languageA, languageASize))
        state = N_2;

    else
        state = N_0;
    
    return state;
}

enum STATE nodo_2(char c, char* palabra) {
    enum STATE state;
    char* aux;

    if (charBelongs(c, languageD, languageDSize))
        state = N_4;

    else if (charBelongs(c, languageA, languageASize))
        state = N_2;

    else
        state = N_0;
    
    return state;
}

enum STATE nodo_3(char c, char* palabra) {
    enum STATE state;
    char* aux;

    if (charBelongs(c, languageC, languageCSize))
        state = N_4;

    else
        state = N_0;
    
    return state;
}

enum STATE nodo_4(char c, char* palabra) {
    enum STATE state;
    state = N_0;

    return state;
}

bool charBelongs(char c, char *lang_x, int size_lang_x) {
    
    for (int i=0; i<size_lang_x; i++){
        if (c == lang_x[i]){
            word_to_file(c);
            return true;
        }
    }
    return false;
}

void word_to_file(char c) {
    FILE *fptr;
    fptr = fopen("words_found.txt", "a");

    fprintf(fptr, "%c", c);
    fclose(fptr);
}