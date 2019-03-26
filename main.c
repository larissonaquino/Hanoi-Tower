#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <locale.h>
#include "Pilha.h"
#include "Hanoi.h"

void menu();
void menuMovimento();

int main(void) {
	setlocale(LC_ALL, "Portuguese");
	
	setup();
	menu();
	endGame();
	
	return 0;
}

void menu(){
	const unsigned int N;
	printf("\n\t Torre de Hanoi com Pilha\n\n");
	printf("Definir quantidade de pinos: ");
	scanf("%u", &N);
	initPins(N);

	while(1){
		char op;
		system("cls");
		printf("\n\t Torre de Hanoi com Pilha\n\n");

		printf("1 - Redefinir quantidade de pinos\n");
		printf("2 - Realizar movimento\n");
		printf("3 - Resetar pinos\n");
		printf("4 - Sair do programa\n");

		op = getch();

		switch(op){
			case '1':
				system("cls");
				printf("Refinir quantidade de pinos: ");
				scanf("%u", &N);
				initPins(N);
				break;
			case '2':
				menuMovimento();
				break;
			case '3':
				initPins(N);
				printf("\nPinos resetados!\n");
				setbuf(stdin, NULL);
				getch();
				break;
			case '4':
				printf("\nSaindo...\n");
				return;
			default:
				printf("\nOpção inválida!");
		}
	}
}

void menuMovimento(){
	char op;
	
	while(1){
		system("cls");
		imprimirPinosHanoi();
		printf("\n");

		printf("1 - Pino A para Pino B\n"  );
		printf("2 - Pino A para Pino C\n"  );
		printf("3 - Pino B para Pino A\n"  );
		printf("4 - Pino B para Pino C\n"  );
		printf("5 - Pino C para Pino A\n"  );
		printf("6 - Pino C para Pino B\n\n");
		printf("7 - Movimentos validos\n"  );
		printf("8 - Voltar\n"              );

		setbuf(stdin, NULL);
		op = getch();
		switch(op){
			case '1':
				play(AB);
				break;
			case '2':
				play(AC);
				break;
			case '3':
				play(BA);
				break;
			case '4':
				play(BC);
				break;
			case '5':
				play(CA);
				break;
			case '6':
				play(CB);
				break;
			case '7':
				printf("\n");
				movimentoValido(AB, true);
				movimentoValido(AC, true);
				movimentoValido(BA, true);
				movimentoValido(BC, true);
				movimentoValido(CA, true);
				movimentoValido(CB, true);
				printf("\n");
				setbuf(stdin, NULL);
				getch();
				break;
			case '8':
				return;
			default:
				printf("Opção inválida!\n");
		}
	}
}