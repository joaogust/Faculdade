#include <stdio.h>

#define TAM 8

void sift(int *vetor, int i, int t){
	int esq = 2 * i;	
	int dir = 2 * i + 1;
	int maior;
	if (esq <= t && vetor[esq] > vetor[i]) {
		maior = esq;
	} else {
		maior = i;
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

void build(int *vetor, int i, int t) {
	for (i = t/2; i>0; i--) {
		sift(vetor, i, t);
	}
}

void heapSort(int *vetor, int t) {
	int i = 0;
	build(vetor, i, t);
	for (i = t; i>0; i--) {
		int aux = vetor[i];
		vetor[i] = vetor[0];
		vetor[0] = aux;
		sift(vetor, 0, i-1);
	}
}
	
int main () {
	int vetor[TAM] = {8, 7, 6, 5, 4, 3, 2, 1};
	int t = TAM;
	heapSort(vetor, t);
	
	for(int i = 0; i < TAM; i++) {
		printf("%d ", vetor[i]);
	}
}
