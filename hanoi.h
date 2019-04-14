#ifndef __HANOI_H__
#define __HANOI_H__
#include <stdbool.h>

typedef enum JOGADA{ AB, AC, BA, BC, CA, CB }JOGADA;

unsigned int N;
unsigned int nrMovimentos;
bool FINISHED;

Pilha * pinoA;
Pilha * pinoB;
Pilha * pinoC;

void setup();
void initPins(const unsigned int discos);
void play(JOGADA play, bool automatic);
bool movimentoValido(JOGADA play, bool listarMovimentos);
void listarMovimentosSolucao();
void illegalPlay();
void finishedGame(bool automatic);
void imprimirPinosHanoi();
void endGame();

#endif