#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"

#define TAM_MAX 100

struct pilha {
	int itens[TAM_MAX];
	int tp;
};

Pilha * criar() {
	Pilha * p = malloc(sizeof(Pilha));
	p->tp = 0;
	return p;
}

void destruir(Pilha * p) {
	if (p != NULL) {
		free(p);
	}	
}

int desempilhar(Pilha * p) {
	if (p->tp == 0) {
		printf("Pilha vazia!\n");
		return -1;
	}
	return p->itens[--p->tp];	
}

void empilhar(Pilha * p, int v) {
	if (p->tp == TAM_MAX) {
		printf("Pilha cheia!\n");
		return;
	}	
	p->itens[p->tp++] = v;	
}

int tamanho(Pilha * p) {
	return p->tp;
}

int topo(Pilha * p) {
	if (p->tp == 0) {
		//printf("Pilha vazia!\n");
		return -1;
	}	
	return p->itens[p->tp-1];
}

void imprimir(Pilha * p) {
	int i;
	printf("[");
	for (i=0; i<p->tp; i++) {
		printf(" %d", p->itens[i]);
	}
	printf(" ]\n");
}

void imprimirPinos(Pilha * pinoA, Pilha * pinoB, Pilha * pinoC){
	int i;
	int maior = pinoA->tp >= pinoB->tp ? pinoA->tp : pinoB->tp;

	maior = maior >= pinoC->tp ? maior : pinoC->tp;
	printf("\nA\tB\tC\n");
	for(i = maior; i >= 0; i--){
		if(i < pinoA->tp)
			printf("%d", pinoA->itens[i]);
		
		printf("\t");
		if(i < pinoB->tp)
			printf("%d", pinoB->itens[i]);
		
		printf("\t");
		if(i < pinoC->tp)
			printf("%d", pinoC->itens[i]);
		printf("\t\n");
	}
}