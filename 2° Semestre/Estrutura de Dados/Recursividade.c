/*
Recursividade é uma técnica de programação na qual uma função (ou metodo) pode chamar a si mesma.
Em geral, uma função definida recursivamente pode ser também definida de uma forma iterativa (através de estruturas de repetição). Em geral, a definição recursiva é mais “declarativa” – explicita o que se pretende obter e não a forma como se obtém (ou seja, o algoritmo que é usado).
*/

#include <stdio.h>

int fat (int n) {
	if(n==0) {
		return 1;
	} else {
		return(n*fat(n-1)); /*chama a própria função*/
	}
}
int main() {
	int a, resposta;

	printf("Digite: ");
	scanf("%i", &a);

	resposta = fat(a);

	printf("\n%i", resposta);
}