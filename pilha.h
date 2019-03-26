#ifndef __PILHA__H__
#define __PILHA__H__
typedef struct pilha Pilha;

Pilha * criar();
void destruir(Pilha * p);
int desempilhar(Pilha * p); // ou pop
void empilhar(Pilha * p, int x); // ou push
int tamanho(Pilha * p);
int topo(Pilha * p);

void imprimir(Pilha * p);
void imprimirPinos(Pilha * pinoA, Pilha * pinoB, Pilha * pinoC);

#endif