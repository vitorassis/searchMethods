int busca_exaustiva_benchmark(int vector[], int size, int key, int &passos, int &iteracoes){
	passos = 0;
	iteracoes=0;
	int i=0;
	while(i < size && vector[i] != key){ // PERCORRE O VETOR AT� ENCONTRAR O VALOR *OU* CHEGAR AO FIM DELE
		i++;
		passos+=3;
		iteracoes++;
	}
	passos++;
	iteracoes++;
	if(i < size) //TESTA SE i < tl, CASO SEJA, FOI ENCONTRADO.
		return i;
	return -1;
}

int busca_exaustiva(int vector[], int size, int key){
	int i=0; 
	while(i < size && vector[i] != key)
		i++;
	if(i < size)
		return i;
	return -1;
}
