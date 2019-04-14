#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "pilha.h"
#include "hanoi.h"

// -------------------- Configuração inicial. --------------------
void setup(){
    pinoA = criar();
    pinoB = criar();
    pinoC = criar();
    FINISHED = false;
}

// -------------------- Define variáveis, zera pino B e pino C e preenche pino A com os discos crescentemente. --------------------
void initPins(const unsigned int discos){
    int i;

    N = discos;
    nrMovimentos = 0;

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

/* -------------------- Realiza uma jogada, caso válida. -------------------- */
void play(JOGADA play, bool automatic){
    if(play == AB){
        if(movimentoValido(play, false)){
            empilhar(pinoB, desempilhar(pinoA));
            nrMovimentos++;
        }
        else
            illegalPlay();
    }
    else if(play == AC){
        if(movimentoValido(play, false)){
            empilhar(pinoC, desempilhar(pinoA));
            nrMovimentos++;
        }
        else
            illegalPlay();
    }
    else if(play == BA){
        if(movimentoValido(play, false)){
            empilhar(pinoA, desempilhar(pinoB));
            nrMovimentos++;
        }
        else
            illegalPlay();
    }
    else if(play == BC){
        if(movimentoValido(play, false)){
            empilhar(pinoC, desempilhar(pinoB));
            nrMovimentos++;
        }
        else
            illegalPlay();
    }
    else if(play == CA){
        if(movimentoValido(play, false)){
            empilhar(pinoA, desempilhar(pinoC));
            nrMovimentos++;
        }
        else
            illegalPlay();
    }
    else{
        if(movimentoValido(play, false)){
            empilhar(pinoB, desempilhar(pinoC));
            nrMovimentos++;
        }
        else
            illegalPlay();
    }

    if(tamanho(pinoC) == N){
        finishedGame(automatic);
        FINISHED = true;
    }
}

/* -------------------- Retorna true se um movimento é válido. -------------------- */
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

    return jogadaLegal;
}

/* -------------------- Realiza as jogadas necessárias para resolver o problema. -------------------- */
void listarMovimentosSolucao(){
    FINISHED = false;
    int indice = tamanho(pinoA) == N ? 0 : nrMovimentos%3;
    // bool exceptionB = false;
    // bool exceptionC = false;
    
    system("cls");
    imprimirPinosHanoi();

    if(N%2 == 0){
    // Se a quantidade de discos for par...
        if((topo(pinoC)) == (N/2))
            indice = 0;
        // if(tamanho(pinoA) == N && tamanho(pinoB) == 0 && tamanho(pinoC) == 0){
        //     indice = 0;
        // }
        // else if(tamanho(pinoB) == 0){
        //     indice = 1;
        //     exceptionB = true;
        // }
        // else if(tamanho(pinoC) == 0){
        //     indice = 2;
        //     exceptionC = true;
        // }

        while(tamanho(pinoC) != N){
            if(movimentoValido(AB, false) && indice == 0){
                printf("\n\t\b---AB---\n");
                play(AB, true);
                if(FINISHED) break;
                imprimirPinosHanoi();
            }
            else if(movimentoValido(BA, false) && indice == 0){
                printf("\n\t\b---BA---\n");
                play(BA, true);
                if(FINISHED) break;
                imprimirPinosHanoi();
            }
            
            indice = indice == 0 ? 1 : nrMovimentos%3;

            if(movimentoValido(AC, false) && indice == 1){
                printf("\n\t\b---AC---\n");
                play(AC, true);
                if(FINISHED) break;
                imprimirPinosHanoi();
            }
            else if(movimentoValido(CA, false) && indice == 1){
                printf("\n\t\b---CA---\n");
                play(CA, true);
                if(FINISHED) break;
                imprimirPinosHanoi();
            }

            indice = indice == 1 ? 2 : nrMovimentos%3;

            if(movimentoValido(BC, false) && indice == 2){
                printf("\n\t\b---BC---\n");
                play(BC, true);
                if(FINISHED) break;
                imprimirPinosHanoi();
            }
            else if(movimentoValido(CB, false) && indice == 2){
                printf("\n\t\b---CB---\n");
                play(CB, true);
                if(FINISHED) break;
                imprimirPinosHanoi();
            }

            indice = indice == 2 ? 0 : nrMovimentos%3;
        }
    }
    else{
    // Se a quantidade de discos for ímpar...
        if(((int)topo(pinoC)/2) == ((int)N/2))
            indice = 0;

        while(tamanho(pinoC) != N){
            if(movimentoValido(AC, false) && indice == 0){
                printf("\n\t\b---AC---\n");
                play(AC, true);
                if(FINISHED) break;
                imprimirPinosHanoi();
            }
            else if(movimentoValido(CA, false) && indice == 0){
                printf("\n\t\b---CA---\n");
                play(CA, true);
                if(FINISHED) break;
                imprimirPinosHanoi();
            }

            indice = indice == 0 ? 1 : nrMovimentos%3;

            if(movimentoValido(AB, false) && indice == 1){
                printf("\n\t\b---AB---\n");
                play(AB, true);
                if(FINISHED) break;
                imprimirPinosHanoi();
            }
            else if(movimentoValido(BA, false) && indice == 1){
                printf("\n\t\b---BA---\n");
                play(BA, true);
                if(FINISHED) break;
                imprimirPinosHanoi();
            }

            indice = indice == 1 ? 2 : nrMovimentos%3;

            if(movimentoValido(BC, false) && indice == 2){
                printf("\n\t\b---BC---\n");
                play(BC, true);
                if(FINISHED) break;
                imprimirPinosHanoi();
            }
            else if(movimentoValido(CB, false) && indice == 2){
                printf("\n\t\b---CB---\n");
                play(CB, true);
                if(FINISHED) break;
                imprimirPinosHanoi();
            }
            
            indice = indice == 2 ? 0 : nrMovimentos%3;
        }
    }
    FINISHED = false;
    printf("\n");
}

void illegalPlay(){
    printf("\nJogada ilegal\n");
    setbuf(stdin, NULL);
	getch();
}

/* -------------------- Mensagem de problema resolvido e reconfiguração das variáveis. -------------------- */
void finishedGame(bool automatic){
    if(!automatic) system("cls");
    imprimirPinosHanoi();
    printf("\nParabens! Voce concluiu o jogo com sucesso!\nNr. de movimentos: %d\n", nrMovimentos);
    printf("\nPressione qualquer tecla para resetar...");
    initPins(N);
    setbuf(stdin, NULL);
    getch();
}

void imprimirPinosHanoi(){
    imprimirPinos(pinoA, pinoB, pinoC);
}

void endGame(){
    destruir(pinoA);
    destruir(pinoB);
    destruir(pinoC);
}