#include <stdio.h>

#define TAM 8

void sift(int *vetor, int i, int t){
	int esq = 2 * i;
	int dir = 2 * i + 1;
	int maior = i;
	
	if (esq <= t && vetor[esq] > vetor[maior]) {
		maior = esq;
	}
	
	if (dir <= t && vetor[dir] > vetor[maior]) {
		maior = dir; 
	}
	
	if (maior != i) {
		int aux = vetor[i];
		vetor[i] = vetor[maior];
		vetor[maior] = aux;
		sift(vetor, maior, t);
	}
}

void build(int *vetor, int t) {
	for (int i = t/2; i>=0; i--) {
		sift(vetor, i, t);
	}
}

void heapSort(int *vetor, int t) {
	build(vetor, t);
	for (int i = t; i>0; i--) {
		int aux = vetor[i];
		vetor[i] = vetor[0];
		vetor[0] = aux;
		sift(vetor, 0, i-1);
	}
}
	
int main () {
	int vetor[TAM] = {6,3,23,7,1,3,2,56};
	
	heapSort(vetor, TAM-1);
	
	for(int i = 0; i < TAM; i++) {
		printf("%d ", vetor[i]);
	}
}
