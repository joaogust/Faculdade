// Computador:  C:\\Users\\CLIENTE\\Documents\\numeros.txt
// Notebook:  C:\\Users\\Anderson\\OneDrive\\Documentos\\numeros.txt
// Linux: /home/estudante2/Downloads/NumerosParaOrdenar.txt
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

#define TAM 5000

void bubbleSort(int vetor[TAM]){
	
	int i, j, x;
	
	for(i=0; i<TAM-1; i++) {
		for(j=0; j<TAM-i-1; j++) {
			if(vetor[j] > vetor[j+1]) {
				x = vetor[j];
				vetor[j] = vetor[j+1];
				vetor[j+1] = x;
			}
		}
	}
}

void leituraArq(int vetor[TAM], FILE *file, int i) {
	char linha[100000], *token;
	
	if(fgets(linha, sizeof(linha), file) != NULL) {
		token = strtok(linha, ",");
		while(token != NULL && i<TAM) {
			vetor[i] = atoi(token);
			i++;
			token = strtok(NULL, ",");
		}
	}
}

int main() {
	FILE * file;
	char nome[100];
	int *vetor = (int *)malloc(TAM * sizeof(int));
	int i=0;	
	double time_spent = 0.0;
	
	printf("Digite o endereço do arquivo: ");
	
	scanf("%99s", nome);
	
	file = fopen(nome, "r");
	
	if(file == NULL) {
		printf("Nao foi possivel abrir o arquivo.");
		return 1;
	} 
	
	for(int f=0; f<1000; f++) {
		leituraArq(vetor, file, i);
		clock_t begin = clock();
		bubbleSort(vetor);
		clock_t end = clock();
		time_spent += (double)(end - begin) / CLOCKS_PER_SEC;
	}
	
	fclose(file);
	
	printf("\n\nO tempo de espera médio foi de %f", time_spent/1000);
}
