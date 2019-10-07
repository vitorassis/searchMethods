int busca_sequencial_indexada_benchmark(int vetor[], int size, int busca, int &passos){
	int i;
	passos=0;
	for(i=0; i<size && vetor[i] < busca; i++){
		passos+=3;
	}
	passos++;
	return vetor[i] == busca ? i : -1;
}
