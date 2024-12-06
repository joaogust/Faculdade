inserção(arvore *a, int x) {
	if(arvoreVazia(a)) { // cria a arvore e armazena o dado na raiz
		criarArvore(a);
		a-> = x;
	} else { // se a arvore já existir
		if(x > a->info) { // se for maior que a raiz insere na direita
			inserção(a ->dir, x);
		} else { // senão insere na esquerda
			inserção(a ->esq, x);
		}
	}
}