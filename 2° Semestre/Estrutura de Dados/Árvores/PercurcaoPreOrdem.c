void listar_pre_ordem(arvorebin T) {
 	if(T != NULL) {
 		printf("%d ", T->dado);
 		listar_pre_ordem(T->esq);
 		listar_pre_ordem(T->dir);
	}
}