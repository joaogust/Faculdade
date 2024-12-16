// Computador:  C:\\Users\\CLIENTE\\Documents\\numeros.txt
// Notebook:  C:\\Users\\Anderson\\OneDrive\\Documentos\\NumerosParaOrdenar.txt
// Linux: /home/estudante2/Downloads/NumerosParaOrdenar.txt
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define TAM 500

void bubbleSort(int *vetor, int t){
	int i, j, x;
	
	for(i=0; i<t-1; i++) {
		for(j=0; j<t-i-1; j++) {
			if(vetor[j] > vetor[j+1]) {
				x = vetor[j];
				vetor[j] = vetor[j+1];
				vetor[j+1] = x;
			}
		}
	}
}

void selectionSort(int *vetor, int t){
	int i, j, min, x;
	
	for (i=0; i<t; i++) {
		min = i;
		for (j=i+1; j<=t; j++)
			if (vetor[j] < vetor[min])
				min = j;
		x = vetor[min];
		vetor[min] = vetor[i];
		vetor[i] = x;
	}
}

void leituraArq(int *vetor, FILE *file, int t) {
	int i=0;
	char linha[100000], *token;
	
	rewind(file);
	
	if(fgets(linha, sizeof(linha), file) != NULL) {
		token = strtok(linha, ",");
		while(token != NULL && i<t) {
			vetor[i] = atoi(token);
			i++;
			token = strtok(NULL, ",");
		}
	}
}

int main() {
	FILE * file;
	char nome[100];
	int *vetor = NULL;
	int t;	
	double time_spent = 0.0;
	
	printf("Digite o endereço do arquivo: ");
	scanf("%99s", nome);
	
	file = fopen(nome, "r");
	
	if(file == NULL) {
		printf("Nao foi possivel abrir o arquivo.");
		return 1;
	} 
	
	
	printf("\n\n--------------- Bubblesort ---------------\n\n");
	
	for(t = TAM; t <= 5000; t += TAM) {
		vetor = (int *) malloc (t * sizeof(int)); 
		if(vetor == NULL) {
			printf("Nao foi possível alocar memória para o vetor...");
			fclose(file);
			return 1;
		}
			for(int f=0; f<1000; f++) {
				leituraArq(vetor, file, t);
				
				clock_t begin = clock();
				bubbleSort(vetor, t);
				clock_t end = clock();
				
				time_spent += (double)(end - begin) / CLOCKS_PER_SEC;
				
			}
		printf("%d: %f\n", t, time_spent/1000);
		time_spent = 0;
		
		free(vetor);
	}
	
	printf("\n\n--------------- Selectionsort ---------------\n\n");
	
	for(t = TAM; t <= 5000; t += TAM) {
		vetor = (int *) malloc (t * sizeof(int)); 
		if(vetor == NULL) {
			printf("Nao foi possível alocar memória para o vetor...");
			fclose(file);
			return 1;
		}
			for(int f=0; f<1000; f++) {
				leituraArq(vetor, file, t);
				
				clock_t begin = clock();
				selectionSort(vetor, t);
				clock_t end = clock();
				
				time_spent += (double)(end - begin) / CLOCKS_PER_SEC;
				
			}
		printf("%d: %f\n", t, time_spent/1000);
		time_spent = 0;
		
		free(vetor);
	}
		
	fclose(file);
}
