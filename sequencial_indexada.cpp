int busca_sequencial_indexada_benchmark(int vetor[], int size, int busca, int &passos, int &iteracoes){
	int i;
	passos=0;
	iteracoes=0;
	for(i=0; i<size && vetor[i] < busca; i++){
		iteracoes++;
		passos+=3;
	}
	passos++;
	iteracoes++;
	return vetor[i] == busca ? i : -1;
}
