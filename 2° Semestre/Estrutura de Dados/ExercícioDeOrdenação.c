// João Gustavo dos Santos - SP3154211

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#define TAM 6

void preencherVetor(int a[TAM]) {
	system("cls");
	printf("Digite %d numeros para o vetor: \n", TAM);
	for(int j=0; j<TAM; j++) {
		printf("Casa %i: ", j+1);
		scanf("%i", &a[j]);
	}
}
void imprimir(int vetor[TAM]) {
	for(int j=0; j<TAM; j++) {
		printf(" %i |", vetor[j]);
	}
	printf("\n");
}

void menu(int a[TAM]) {
	printf("\nVetor: ");
	imprimir(a);
	printf("----------------------------------------\n\n");

	printf(" 1 - BubbleSort\n");
	printf(" 2 - SelectionSort\n");
	printf(" 3 - InsertionSort\n");
	printf(" 4 - MergeSort *\n");
	printf(" 5 - QuickSort *\n");
	printf(" 6 - RadixSort *\n");
	printf(" 7 - HeapSort *\n");
	printf(" 8 - Alterar Vetor\n");
	printf(" 9 - Sair\n\n");

	printf("Digite o metodo de ordenacao desejada: ");
}

void bubbleSort(int a[TAM]) {
	system("cls");
	int b[TAM], i, j, k, x, h=0;
	for(i=0; i<TAM; i++) { // Passando os valores para outro vetor para não alterar o original
		b[i] = a[i];
	}
	printf("------------- BubbleSort -------------\n\n");
	printf("01 - ");
	imprimir(b);
	sleep(1);

	for(i=0, k=2; i<TAM-1; i++) {
		for(j=0; j<TAM-i; j++) {
			if(b[j] > b[j+1]) {
				x = b[j];
				b[j] = b[j+1];
				b[j+1] = x;
				h = 1;
				if(k<10)
					printf("0");
				printf("%d - ", k);
				imprimir(b);
				sleep(1);
				k++;
			}
		}
	}

	char c[2];
	printf("\npress Enter...");
	fflush(stdin);
	gets(c);
}

void selectionSort(int a[TAM]) {
	system("cls");
	int b[TAM], i, j, min, x, k;

	for(i=0; i<TAM; i++) { // Passando os valores para outro vetor para não alterar o original
		b[i] = a[i];
	}
	printf("------------- SelectionSort -------------\n\n");

	for (i=0, k=1; i<TAM; i++, k++) {
		printf("%d - ", k);
		imprimir(b);
		sleep(1);
		min = i;
		for (j=i+1; j<=TAM; j++)
			if (b[j] < b[min])
				min = j;
		x = b[min];
		b[min] = b[i];
		b[i] = x;
	}

	char c[2];
	printf("\npress Enter...");
	fflush(stdin);
	gets(c);
}

void insertionSort(int a[TAM]) { // Terminar

	int i=0, j, x, b[TAM], h=0, k=2;

	system("cls");

	for(i=0; i<TAM; i++) { // Passando os valores para outro vetor para não alterar o original
		b[i] = a[i];
	}
	printf("------------- InsertionSort -------------\n\n");
	printf("01 - ");
	imprimir(b);
	sleep(1);

	for (i=1; i<=TAM; i++) {
		x = b[i];
		for (j=i; j>0 && x<b[j-1]; j--) {
			b[j] = b[j-1];
			h=1;
		}
		b[j] = x;

		if(h==1) { // Verificação se o vetor foi alterado para a impressão
			if(k<10) {
				printf("0");
			}
			printf("%d - ", k);
			k++;
			imprimir(b);
			sleep(1);
			h=0;
		}
	}
	char c[2];
	fflush(stdin);
	printf("\npress Enter...");
	gets(c);
}

void mergeSort() {
}

void quickSort() {
}

void radixSort(){
}

void heapSort() {
}

int main() {
	int a[TAM], g=0;

	preencherVetor(a);

	while(g!=9) {
		system("cls");
		menu(a);
		g = 0;

		scanf("%i", &g);

		switch(g) {
			case 1:
				bubbleSort(a);
				break;
			case 2:
				selectionSort(a);
				break;
			case 3:
				insertionSort(a);
				break;
			case 4:
				mergeSort();
				break;
			case 5:
				quickSort();
				break;
			case 6:
				radixSort();
				break;
			case 7:
				heapSort();
				break;
			case 8:
				preencherVetor(a);
				break;
		}
	}
}