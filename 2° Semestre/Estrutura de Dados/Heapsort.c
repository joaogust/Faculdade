#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define TAM 8

void heapSort(int *vetor) {
	int i = 0;
	
	sift(vetor, i)
}

void sift(int *vetor, int i){
	int esq = 2*i;
	int dir = 2*i+1;
	if (esq <= TAM && v[esq] > v[i])
		int maior = esq;
	else
		maior = i;
	if (dir <= TAM && v[dir] > v[maior])
		maior = dir;
	if (maior != i) {
		aux = v[i];
		v[i] = v[maior];
		v[maior] = aux;
		sift(maior, TAM);
	}
}

	
	int main () {
	int vetor[TAM] = {8, 7, 6, 5, 4, 3, 2, 1};
	
	heapSort(vetor);
	
	for(int i = 0; i < TAM; i++) {
		printf("%d ", vetor[i]);
	}
}
