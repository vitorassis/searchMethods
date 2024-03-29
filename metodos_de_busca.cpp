#include <stdio.h>
#include <stdlib.h>
#include "interio.h"

#define TF 50

#include "exaustiva.cpp"
#include "exaustiva_com_sentinela.cpp"
#include "sequencial_indexada.cpp"
#include "binaria.cpp"

void ordenate(int vetor[], int new_vetor[], int size){
	for (int i=0; i<size; i++)
		new_vetor[i] = vetor[i];
	
	for(int i=1; i<size; i++)
		for(int j=0; j<size-1; j++)
			if(new_vetor[i]<new_vetor[j]){
				new_vetor[i] ^= new_vetor[j];
				new_vetor[j] ^= new_vetor[i];
				new_vetor[i] ^= new_vetor[j];
			}		
}

void inputVector(int vetor[], int &size){
	clearCanvas();
	int aux;
	do{
		gotoxy(30, 9);printf("N�mero: ");
		do{
			aux = readIntVariable(38, 9, 50, 9);
			if(busca_exaustiva(vetor, size, aux) != -1){
				showToast("N�mero j� inserido!");
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
	int index, steps, iteracoes, ord_vetor[TF];
	do{
		clearCanvas();
		gotoxy(30, 8);printf("N�mero: ");
		busca = readIntVariable(38, 8, 50, 8);
		
		menu searchMenu = setMenu(10, 15);
	
		addMenuOption(searchMenu, "Mudar N�mero", 1);
		addMenuOption(searchMenu, "Busca Exaustiva", 1);
		addMenuOption(searchMenu, "Busca Exaustiva Com Sentinela", 1);
		addMenuOption(searchMenu, "Busca Sequencial Indexada", 1);
		addMenuOption(searchMenu, "Busca Bin�ria", 1);
		addMenuOption(searchMenu, "Voltar", 1);
		
		searchMenu.cursor = 185;
		do{
			coord = showMenu(searchMenu);
			clearCoordinates(10, 20, 20, 21);
			switch(coord){
				case 11:
					index = busca_exaustiva_benchmark(vector, size, busca, steps, iteracoes);
						
					break;	
				case 12:
					index = busca_exaustiva_com_sentila_benckmark(vector, size, busca, steps, iteracoes);
					
					break;
				case 13:
					ordenate(vector, ord_vetor, size);
					
					index = busca_sequencial_indexada_benchmark(ord_vetor, size, busca, steps, iteracoes);
					
					break;
				case 14:
					ordenate(vector, ord_vetor, size);
					
					index = busca_binaria_benchmark(ord_vetor, size, busca, steps, iteracoes);
			}
			
			clearCoordinates(10, 19, 78, 21);
			gotoxy(10, 19); printf("�ndice: %d", index);
			gotoxy(10, 20); printf("Passos: %d", steps);
			gotoxy(10, 21); printf("Itera��es: %d", iteracoes);	
			
			if(coord != 15)
				getch();
		}while(coord != 15 && coord != 10);
		
	}while(busca != 0 && coord != 15);
}

int main(){
	setlocale(LC_ALL,"Portuguese");
	drawCanvas();
	int vector[TF+1];
	int size = 0;
	
	menu mainMenu = setMenu(10, 13);
	
	addMenuOption(mainMenu, "Cadastrar", 1);
	addMenuOption(mainMenu, "Testar", 1);
	addMenuOption(mainMenu, "Ver vetor", 1);
	addMenuOption(mainMenu, "Sair", 1);
	mainMenu.cursor=185;
		
	int coord;
	
	do{
		clearCanvas();
		coord = showMenu(mainMenu);
		switch(coord){
			case 10:
				inputVector(vector, size);
				break;
			case 11:
				compare(vector, size);
				break;
			case 12:
				dumpIntVector(vector, size);
				getch();
				int ord_vet [TF];
				ordenate(vector, ord_vet, size);
				dumpIntVector(ord_vet, size);
		}
	}while(coord != 13);
	
	return 0;
}
