void listar_em_ordem(arvorebin T) {
	if(T != NULL) {
		listar_em_ordem(T->esq);
		printf("%d ", T->dado);
		listar_em_ordem(T->dir);
	}
}