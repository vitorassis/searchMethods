int busca_exaustiva_com_sentila_benckmark(int vector[], int size, int key, int &passos){
	passos = 0;
	vector[size] = key;  //P�E O VALOR PROCURADO COMO O �LTIMO DO VETOR, GARANTINDO QUE SEMPRE SER� ENCONTRADO!
	int i=0;
	while(vector[i] != key){ //PERCORRE AT� QUE ENCONTRE
		i++;
		passos++;
	}
	passos++;
	if(i < size) //CASO SEJA ENCONTRADO ANTES DE TF, EST� NO VETOR
		return i;
	return -1; //CASO i == TF, N�O EST� NO VETOR, PORTANTO O ENCONTRADO FOI O QUE CONFIGURAMOS NA SEGUNDA LINHA.
}
