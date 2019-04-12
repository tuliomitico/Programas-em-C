#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

const int l = 6; //constante global para definir o recuo da funcao imprime

typedef struct reg {
   int         k;
   int         carga;
   struct reg *esq, *dir; 
} tree; // estrutura de uma arvore

void imprime(tree* r);
tree* insere (tree* r, tree *novo);
tree* input(int n);
bool ehABBfunc(tree* raiz, tree** prev);
bool ehABB(tree *raiz);

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
	if (ehABB(raiz) == 1){
		printf("Eh Arvore de Busca\n");
	}
	else printf("Nao eh\n");
	
}
bool ehABBfunc(tree* raiz, tree** prev) //funcao booleana que defina se eh ABB( Arvore binaria de busca) ou nao
{
    // Atravessa a arvore binaria na ordem erd e 
    // e o ponteiro duplo mantem o endere�o do ponteiro anterior
    tree* aux = *(prev); //usando a estrutura de arvore auxiliar para a recursao
    if (raiz)
    {
        if (!ehABBfunc(raiz->esq, &aux))
          return false;
  
        // Permite apenas o uso de valores distintos na arvore,caso contraria eh negado
        if (aux != NULL && raiz->k <= aux->k)
          return false;
  		
        aux = raiz;
  
        return ehABBfunc(raiz->dir, &aux);
    }
    return true;
}
 
bool ehABB(tree *raiz) //funcao apenas para sintetizar o uso dela
{
   tree *prev = NULL;
   return ehABBfunc(raiz, &prev);
}
 
tree* input(int n){ //input adaptado para preencher o valor da chave( nomeie como k para fins de digitar menos msm :-) ); 
  tree* var = malloc(sizeof(tree));
  var->k = n;
  var->dir =  NULL;
  var->esq = NULL;
  return var;
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
