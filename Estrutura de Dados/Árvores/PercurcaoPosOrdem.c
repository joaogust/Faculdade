void listar_pos_ordem(arvorebin T) {
 	if(T != NULL) {
 		listar_pos_ordem(T->esq);
 		listar_pos_ordem(T->dir);
 		printf("%d ", T->dado);
 	}
}