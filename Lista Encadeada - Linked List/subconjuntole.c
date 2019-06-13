#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct reg {
	int carga;
	struct reg *prox;
} frame;  //chamando as funcoes antes e o struct

void input (frame** head_ref, int n);

void imprime (frame *le);

bool existe (frame *s, int n);

frame *intersec (frame *s1, frame *s2);

int contavai(frame *le);

int main(){
	int i, x, y, m, n;
	frame *f1=NULL, *f2=NULL, *f3=NULL;
	scanf("%d",&m);
	for (i = 0; i < m; i++){
		scanf("%d", &x);
		input(&f1, x);
	}
	scanf("%d", &n);
	for (i = 0;i < n; i++){
		scanf("%d", &y);
		input(&f2, y);
	}
	f3 = intersec(f1,f2);
	if (contavai(f3) == n) { // condicional se verifica se todos os numeros de "B"
		printf("1");	     // estao em "A"
		
	}
	else {
		printf("0");
	}
	
	
}
void input (frame** head_ref, int n) {                  //funcao utilizada pra criar a lista encadeada como se fosse um vetor,
	frame *novoframe = (frame *) malloc(sizeof(frame));//adiconando um elemento atras do outro e verifica se
    novoframe->carga = n;							   //se a primeira posicao é existente
    novoframe->prox = NULL;

    if ((*head_ref) == NULL) {
        // Adiciona no começo da lista
        (*head_ref) = novoframe;
    } else {
        frame *atual = (*head_ref);

        while (atual->prox != NULL) {
            atual = atual->prox;
        };

        // Adiciona uma atrás do outro
    atual->prox = novoframe;
    }
}

void imprime (frame *le) { //funcao imprime utilizado no site do ime.usp.br
	if (le != NULL) {
		printf("%d\n", le->carga);
		imprime(le->prox);
	}
}

frame *intersec (frame *s1, frame *s2)
{
    frame *r = NULL;
    frame *t1 = s1;
 
    // Atravessa a 1 lista e procurar cada elemento da
    // 2 lista. Se o elemento estiver na 2 lista, então
    // insere o elemento em r
    while (t1 != NULL)
    {
        if (existe(s2, t1->carga))
            input (&r, t1->carga);
        t1 = t1->prox;
    }
 
    return r; }

bool existe (frame *s, int n) {//Essa funcao booleana verifica se a carga
							  //existe e devolve 1 se sim, e 0 se não
    frame *t = s;
    while (t != NULL)
    {
        if (t->carga == n)
            return 1;
        t = t->prox;
    }
    return 0; }
int contavai(frame *le) { //contando a quantidade de elementos de uma lista encadeada					
						  // adaptado da funcao imprime
   frame *p;
   int i;
   for (p = le; p != NULL; p = p->prox) 
      i++;
      return i;
}
    
