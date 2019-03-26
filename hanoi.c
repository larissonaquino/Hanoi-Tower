#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "Pilha.h"
#include "Hanoi.h"

void setup(){
    pinoA = criar();
    pinoB = criar();
    pinoC = criar();
}

void initPins(const unsigned int discos){    
    int i;
    
    N = discos;
    
    while(tamanho(pinoA) > 0){
        desempilhar(pinoA);
    }
    
    while(tamanho(pinoB) > 0){
        desempilhar(pinoB);
    }

    while(tamanho(pinoC) > 0){
        desempilhar(pinoC);
    }
    
    for(i = discos; i > 0; i--){
        empilhar(pinoA, i);
    }
}

void play(JOGADA play){
    if(play == AB){
        if(movimentoValido(play, false))
            empilhar(pinoB, desempilhar(pinoA));
    }
    else if(play == AC){
        if(movimentoValido(play, false))
            empilhar(pinoC, desempilhar(pinoA));
    }
    else if(play == BA){
        if(movimentoValido(play, false))
            empilhar(pinoA, desempilhar(pinoB));
    }
    else if(play == BC){
        if(movimentoValido(play, false))
            empilhar(pinoC, desempilhar(pinoB));
    }
    else if(play == CA){
        if(movimentoValido(play, false))
            empilhar(pinoA, desempilhar(pinoC));
    }
    else{
        if(movimentoValido(play, false))
            empilhar(pinoB, desempilhar(pinoC));
    }

    if(tamanho(pinoC) == N){
        system("cls");
        imprimirPinosHanoi();
        printf("\nParabéns! Você concluiu o jogo com sucesso!\nPressione qualquer tecla para continuar...\n");
        initPins(N);
        setbuf(stdin, NULL);
		getch();
    }
}

bool movimentoValido(JOGADA play, bool listarMovimentos){
    bool jogadaLegal = false;

    if(play == AB){
        if(topo(pinoA) != -1){
            if(topo(pinoB) != -1){
                if(topo(pinoA) < topo(pinoB)){
                    jogadaLegal = true;
                    if(listarMovimentos)
                        printf(" AB ");
                }
            }
            else{
                jogadaLegal = true;
                if(listarMovimentos)
                    printf(" AB ");
            }
        }
    }
    else if(play == AC){
        if(topo(pinoA) != -1){
            if(topo(pinoC) != -1){
                if(topo(pinoA) < topo(pinoC)){
                    jogadaLegal = true;
                    if(listarMovimentos)
                        printf(" AC ");
                }
            }
            else{
                jogadaLegal = true;
                if(listarMovimentos)
                    printf(" AC ");
            }
        }
    }
    else if(play == BA){
        if(topo(pinoB) != -1){
            if(topo(pinoA) != -1){
                if(topo(pinoB) < topo(pinoA)){
                    jogadaLegal = true;
                    if(listarMovimentos)
                        printf(" BA ");
                }
            }
            else{
                jogadaLegal = true;
                if(listarMovimentos)
                    printf(" BA ");
            }
        }
    }
    else if(play == BC){
        if(topo(pinoB) != -1){
            if(topo(pinoC) != -1){
                if(topo(pinoB) < topo(pinoC)){
                    jogadaLegal = true;
                    if(listarMovimentos)
                        printf(" BC ");
                }
            }
            else{
                jogadaLegal = true;
                if(listarMovimentos)
                    printf(" BC ");
            }
        }
    }
    else if(play == CA){
        if(topo(pinoC) != -1){
            if(topo(pinoA) != -1){
                if(topo(pinoC) < topo(pinoA)){
                    jogadaLegal = true;
                    if(listarMovimentos)
                        printf(" CA ");
                }
            }
            else{
                jogadaLegal = true;
                if(listarMovimentos)
                    printf(" CA ");
            }
        }
    }
    else{
        if(topo(pinoC) != -1){
            if(topo(pinoB) != -1){
                if(topo(pinoC) < topo(pinoB)){
                    jogadaLegal = true;
                    if(listarMovimentos)
                        printf(" CB ");
                }
            }
            else{
                jogadaLegal = true;
                if(listarMovimentos)
                    printf(" CB ");
            }
        }
    }

    if(!jogadaLegal && !listarMovimentos){
        printf("\nJogada ilegal\n");
        setbuf(stdin, NULL);
		getch();
    }

    return jogadaLegal;
}

void imprimirPinosHanoi(){
    imprimirPinos(pinoA, pinoB, pinoC);
}

void endGame(){
    destruir(pinoA);
    destruir(pinoB);
    destruir(pinoC);
}