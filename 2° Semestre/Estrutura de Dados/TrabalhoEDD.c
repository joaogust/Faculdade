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

void insertionSort(int *vetor, int t) {
	int i=0, j, x;
	
	for (i=1; i<=t; i++) {
		x = vetor[i];
		for (j=i; j>0 && x<vetor[j-1]; j--) {
			vetor[j] = vetor[j-1];
		}
		vetor[j] = x;
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
	
void conquista(int *vetor, int esq, int dir, int meio) {
	int tamEsq = meio - esq + 1;					
	int tamDir = dir - meio;						
	int auxEsq[tamEsq], auxDir[tamDir];
	
	for (int i = 0; i < tamEsq; i++) {
        auxEsq[i] = vetor[i + esq];
	}
    for (int j = 0; j < tamDir; j++) {
        auxDir[j] = vetor[j + meio + 1];
	}
	
	int i = 0, j = 0, k = esq;
	
	while(i < tamEsq && j < tamDir) {
		if(auxEsq[i] < auxDir[j]) {	
			vetor[k] = auxEsq[i];
			i++;
		}
		else {
			vetor[k] = auxDir[j];
			j++;
		}
		k++;
	}
	
    while (i < tamEsq) {
        vetor[k] = auxEsq[i];
        i++;
        k++;
    }

    while (j < tamDir) {
        vetor[k] = auxDir[j];
        j++;
        k++;
    }
}

void mergeSort(int *vetor, int esq, int dir) {  
	if (esq < dir) {			                    
		int meio = (esq + dir) / 2;
	
	mergeSort(vetor, esq, meio);
	mergeSort(vetor, meio + 1, dir);
	conquista(vetor, esq, dir, meio);				
	}
}

void troca(int vetor[], int i, int j) {
	int aux = vetor[i];
	vetor[i] = vetor[j];
	vetor[j] = aux;
}

int divisao(int vetor[], int inicio, int fim) {
	int pivo = vetor[fim];
	int indicePivo = inicio;		         	    

	for(int i = inicio; i < fim; i++) {
		if(vetor[i] <= pivo) {
			troca(vetor, i, indicePivo);
			indicePivo++;
		}
	}
	
	troca(vetor, indicePivo, fim);
	return indicePivo;
}

void quickSort(int vetor[], int inicio, int fim) {
	if (inicio < fim) {
		int indicePivo = divisao(vetor, inicio, fim);
		quickSort(vetor, inicio, indicePivo - 1);
		quickSort(vetor, indicePivo + 1, fim);
	}	
}

void radixSort(int *vetor, int t) {
	int maior = 0, base = 1, i;
	int	baldes[10], aux[t] = {0};
	
	for(i = 0; i < t; i++) {
		if(vetor[i] > maior) {
			maior = vetor[i];
		}
	}
	
	while(maior / base > 0) {
		
		for(i = 0; i < 10; i++) {
			baldes[i] = 0;
		}
		
		for(i = 0; i < t; i++) {
			baldes[(vetor[i] / base) % 10] += 1;
		}
						
		for(i = 1; i < 10; i++) {						
			baldes[i] += baldes[i-1];
		}		
		for(i = t - 1; i >= 0; i--) {							
			aux[baldes[(vetor[i] / base) % 10] - 1] = vetor[i];
			baldes[(vetor[i] / base) % 10]--;
		}
		
		for(i = 0; i < t; i++) {
			vetor[i] = aux[i];
		}
		
		base *= 10;
	}
}

void sift(int *vetor, int i, int t){
	int esq = 2 * i;
	int dir = 2 * i + 1;
	int maior = i;
	
	if(i==0) {
		esq = 1;
		dir = 2;
	}
	
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
	for (int i = t/2; i>0; i--) {
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
	
	printf("\n\n--------------- Insertionsort ---------------\n\n");
	
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
				insertionSort(vetor, t);
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
		
	printf("\n\n--------------- Mergesort ---------------\n\n");
	
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
				mergeSort(vetor, 0 , t-1);
				clock_t end = clock();
				
				time_spent += (double)(end - begin) / CLOCKS_PER_SEC;
				
			}
		printf("%d: %f\n", t, time_spent/1000);
		time_spent = 0;
		
		free(vetor);
	} 
	
	printf("\n\n--------------- Quicksort ---------------\n\n");
	
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
				mergeSort(vetor, 0 , t-1);
				clock_t end = clock();
				
				time_spent += (double)(end - begin) / CLOCKS_PER_SEC;
				
			}
		printf("%d: %f\n", t, time_spent/1000);
		time_spent = 0;
		
		free(vetor);
	}
	
	printf("\n\n--------------- Radixsort ---------------\n\n");
	
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
				radixSort(vetor, t);
				clock_t end = clock();
				
				time_spent += (double)(end - begin) / CLOCKS_PER_SEC;
				
			}
		printf("%d: %f\n", t, time_spent/1000);
		time_spent = 0;
		
		free(vetor);
	} 
	
	printf("\n\n--------------- Heapsort ---------------\n\n");
	
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
				heapSort(vetor, t);
				clock_t end = clock();
				
				time_spent += (double)(end - begin) / CLOCKS_PER_SEC;
				
			}
		printf("%d: %f\n", t, time_spent/1000);
		time_spent = 0;
		
		for(int i = 0; i < t && t==5000; i++) {
		printf("%d ", vetor[i]);
		}
		free(vetor);
	} 
		
	fclose(file);
	
}
