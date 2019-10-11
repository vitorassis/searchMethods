int busca_binaria_benchmark(int vetor[], int size, int key, int &passos, int &iteracoes){
	passos=0;
	iteracoes=0;
	
	int i = 0;
	int f = size-1;
	int meio;
	
	do{
		meio = (i+f)/2;
		if(vetor[meio] < key){
			i = meio-1;
			passos++;
		}else if(vetor[meio] > key){
			f = meio+1;
			passos++;
		}
		iteracoes++;
	}while(i <= f && vetor[meio] != key);
	
	passos++;
	iteracoes++;
	if(vetor[meio] == key)
		return meio;
	return -1;
}
