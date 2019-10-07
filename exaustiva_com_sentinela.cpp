int busca_exaustiva_com_sentila_benckmark(int vector[], int size, int key, int &passos){
	passos = 0;
	vector[size] = key;  //PÕE O VALOR PROCURADO COMO O ÚLTIMO DO VETOR, GARANTINDO QUE SEMPRE SERÁ ENCONTRADO!
	int i=0;
	while(vector[i] != key){ //PERCORRE ATÉ QUE ENCONTRE
		i++;
		passos++;
	}
	passos++;
	if(i < size) //CASO SEJA ENCONTRADO ANTES DE TF, ESTÁ NO VETOR
		return i;
	return -1; //CASO i == TF, NÃO ESTÁ NO VETOR, PORTANTO O ENCONTRADO FOI O QUE CONFIGURAMOS NA SEGUNDA LINHA.
}
