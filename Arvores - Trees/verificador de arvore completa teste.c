#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
const int l = 6;

typedef struct reg{
	int carga;
	struct reg *dir,*esq;
}tree;

typedef tree* arvore;

typedef struct rig{
	arvore data;
	struct rig* prox;
}frame;

arvore tiradafila (frame *fi);

frame *colocanafila (tree* y, frame *fi);

void imprimegk(arvore r,int k);

void imprime(arvore r);

arvore entrada (int y); 

bool isComplete(tree* root, int i, int n)
{
    // return if tree is empty
   	if (root == NULL)
		return true;

	if ((root->esq && 2*i + 1 >= n) || !isComplete(root->esq, 2*i + 1, n))
		return false;

	if ((root->dir && 2*i + 2 >= n) || !isComplete(root->dir, 2*i + 2, n))
		return false;

	return true;
}

int main(){
	int j = 0;
	frame *fi,*fi2;
	fi = malloc (sizeof (frame));
	fi2 = malloc (sizeof (frame));
	fi->prox = fi;
	fi2->prox = fi2;
	tree *raiz,*noh;
	raiz = malloc (sizeof (tree));
	noh = malloc (sizeof (tree));
	int v[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17};
	int n = sizeof (v) / sizeof(int);
	for (j; j < n; j++) {
    	noh = entrada (v[j]);
    	fi = colocanafila(noh,fi);
	}
	
	raiz = tiradafila(fi);
	fi2 = colocanafila(raiz,fi2);
	
  	for (j = 0; j < n; j++) {
  		arvore visitado = tiradafila(fi2);
  		visitado->dir = tiradafila(fi);
  		visitado->esq = tiradafila(fi);
  		fi2 = colocanafila(visitado->esq,fi2);
  		fi2 = colocanafila(visitado->dir,fi2);
	}
	
  	imprime(raiz);
  	printf("\n %d",isComplete(raiz,0,n));
	return 0;
}

arvore tiradafila (frame *fi) {
   frame *p;
   p = fi->prox;  // o primeiro da fila
   arvore x = p->data;
   fi->prox = p->prox;
   free (p);
   return x;  
}

frame *colocanafila (tree* y, frame *fi) { 
   frame *nova;
   nova = malloc (sizeof (frame));
   nova->prox = fi->prox;
   fi->prox = nova;
   fi->data = y;
   return nova;
}
void imprimegk(arvore r,int k) {
	int i = 0;
	if (r == NULL) return;
	k += l; //cria se uma variavel q armazena esse valor a cada chamada da recursao
	imprimegk(r->dir,k);
  	printf("\n");	
	for (i = l; i < k; i++)
	  printf(" ");
	printf("%d\n", r->carga);

	imprimegk(r->esq,k);	
}

void imprime(arvore r) { //para utilizaçao de menos variaveis na chamda funcao crie outra que armzena so a arvore sem o int
	imprimegk(r,0); //o 0 determina o tamanho da indentacao, no exemplo parace q a distancia e de 3 " ".
}

arvore entrada (int y) {
  tree* var; 
  var = (tree*) malloc(sizeof(tree));
  var->carga = y;
  var->dir = NULL;
  var->esq = NULL;  
  return var;
}
