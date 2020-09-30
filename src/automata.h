#ifndef AUTOMATA_H
#define AUTOMATA_H

// Centinela
static char CENTINELA = '#';

// Estados
enum STATE {N_0, N_1, N_2, N_3, N_4}; 

// Nodos a usar
enum STATE nodo_0(char, char*);
enum STATE nodo_1(char, char*);
enum STATE nodo_2(char, char*);
enum STATE nodo_3(char, char*);
enum STATE nodo_4(char, char*);

#endif