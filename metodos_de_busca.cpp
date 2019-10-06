#include <stdio.h>
#include <stdlib.h>
#include "interio.h"

#define TF 50

#include "exaustiva.cpp"
#include "exaustiva_com_sentinela.cpp"

void inputVector(int vetor[], int &size){
	clearCanvas();
	int aux;
	do{
		gotoxy(30, 9);printf("Número: ");
		do{
			aux = readIntVariable(38, 9, 50, 9);
			if(busca_exaustiva(vetor, size, aux) != -1){
				showToast("Número já inserido!");
			}
		}while(busca_exaustiva(vetor, size, aux) != -1);
		removeToast();
		if(aux != 0){
			vetor[size] = aux;
			size++;			
		}
	}while(aux != 0);
}

void compare(int vector[], int size){
	clearCanvas();
	int busca;
	int coord;
	int index, steps;
	do{
		clearCanvas();
		gotoxy(30, 8);printf("Número: ");
		busca = readIntVariable(38, 8, 50, 8);
		char options[6][50];
		strcpy(options[0], "Mudar número");
		strcpy(options[1], "Busca Exaustiva");
		strcpy(options[2], "Busca Exaustiva Com Sentinela");
		strcpy(options[3], "Busca Sequencial Indexada");
		strcpy(options[4], "Busca Binária");
		strcpy(options[5], "Voltar");
		do{
			coord = showMenu(options, 10, 15, 30);
			clearCoordinates(10, 20, 20, 21);
			switch(coord){
				case 11:
					index = busca_exaustiva_benchmark(vector, size, busca, steps);
					
					gotoxy(10, 20); printf("Índice: %d", index);
					gotoxy(10, 21); printf("Passos: %d", steps);			
					getch();	
					break;	
				case 12:
					index = busca_exaustiva_com_sentila_benckmark(vector, busca, steps);
					
					gotoxy(10, 20); printf("Índice: %d", index);
					gotoxy(10, 21); printf("Passos: %d", steps);			
					getch();	
					break;
			}
		}while(coord != 15 && coord != 10);
		
	}while(busca != 0 && coord != 15);
}

int main(){
	setlocale(LC_ALL,"Portuguese");
	drawCanvas();
	int vector[TF+1];
	int size = 0;
	
	char opcoes[3][50];
	strcpy(opcoes[0], "Cadastrar");
	strcpy(opcoes[1], "Testar");
	strcpy(opcoes[2], "Sair");
		
	int coord;
	
	do{
		clearCanvas();
		coord = showMenu(opcoes,10, 12, 30);
		switch(coord){
			case 10:
				inputVector(vector, size);
				break;
			case 11:
				compare(vector, size);
				break;
		}
	}while(coord != 12);
	
	return 0;
}
