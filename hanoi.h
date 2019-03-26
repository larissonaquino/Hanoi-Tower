#ifndef __HANOI_H__
#define __HANOI_H__
#include <stdbool.h>

typedef enum JOGADA{ AB, AC, BA, BC, CA, CB }JOGADA;

int N;

Pilha * pinoA;
Pilha * pinoB;
Pilha * pinoC;

void setup();
void initPins(const unsigned int discos);
void play(JOGADA jogada);
bool movimentoValido(JOGADA play, bool listarMovimentos);
void imprimirPinosHanoi();
void endGame();

#endif