#include <stdio.h>
#include <stdlib.h>
const int l = 6; //constante global para definir o recuo da funcao imprime
typedef struct reg {
   int         k;
   int         carga;
   struct reg *esq, *dir; 
} tree; // estrutura de uma arvore

void imprime(tree* r);
int min(tree* noh);
int max(tree* noh);
tree* insere (tree* r, tree *novo);
tree* input(int n);

int main(void){
	tree* raiz, *noh, *folha;
	raiz = input(8);
	raiz->esq = input(7);
	raiz->dir = input(9);
	noh = input(10);
	folha = input(6);
	raiz = insere(raiz,noh);
	raiz = insere(raiz,folha);
	imprime(raiz);
	printf("O valor minimo eh %d\nO valor maximo eh %d",min(raiz),max(raiz));
	
}
tree* input(int n){ //input adaptado para preencher o valor da chave( nomeie como k para fins de digitar menos msm :-) ); 
  tree* var = malloc(sizeof(tree));
  var->k = n;
  var->dir =  NULL;
  var->esq = NULL;
  return var;
}
int min(tree* noh) {
  tree* atual = noh;
 
  /* desce embaixo para achar a folha mais a esquerda*/
  while (atual->esq != NULL) {
    atual = atual->esq;
  }
  return(atual->k);
}
int max(tree* noh) {
	tree* atual = noh;
	
	
	/* desce embaixo ateh achar a folha mais a direita*/
	while(atual->dir != NULL) {
		atual = atual->dir;
	}
	return(atual->k);
}
tree* 
insere (tree* r, tree *novo) {  
    if (r == NULL) return novo;
    if (r->k > novo->k) 
       r->esq = insere (r->esq, novo);
    else 
       r->dir = insere (r->dir, novo);
    return r;
}
void imprimegk(tree* r,int k) {
	int i = 0;
	if (r == NULL) return;
  	k += l; //cria se uma variavel q armazena esse valor a cada chamada da recursao
  	imprimegk(r->esq,k);
	  
	printf("\n");	
	for (i = l; i < k; i++)
	  printf(" ");
	printf("%d\n",r->k);
	
	imprimegk(r->dir,k);
 
}

void imprime(tree* r) { //para utilizaÃ§ao de menos variaveis na chamda funcao crie outra que armzena so a arvore sem o int
	imprimegk(r,0); //o 0 determina o tamanho da indentacao, no exemplo parace q a distancia e de 3 " ".
}
