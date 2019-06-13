#include <stdio.h>
#include <stdlib.h>

typedef struct reg { //o struct nomeado com frame
	int carga;
	struct reg *prox;
} frame;
//Referenciando as funcoes para aplicar no main
void input (frame** head_ref,int n);

void imprime (frame *le);

static void reverso(frame** h);

int main() {
	int x,i = 0;
	char s;
	frame *f1=NULL; //iniciando um frame
	do {
    	scanf("%d%c", &x, &s);
    	input(&f1, x);
    	i++;
  	} while(s != '\n');		
	reverso(&f1);
	imprime(f1);
}

void input (frame** head_ref,int n) {
    frame *novoframe = (frame *) malloc(sizeof(frame)); //alocando espaco na memoria RAM do computador
    novoframe->carga = n;
    novoframe->prox = NULL;

    if ((*head_ref) == NULL) {
        // Adicona no começo
        (*head_ref) = novoframe;
    } else {
        frame *atual = (*head_ref);

        while (atual->prox != NULL) {
            atual = atual->prox;
        };
        // adiciona apos o primeiro ter sido inserido
        atual->prox = novoframe;
    }
}
void imprime (frame *le) { //funcao imprime utilizado no site do ime.usp.br
    if (le!=NULL) {
        printf("%d ",le->carga);
        imprime(le->prox);
    }
}
static void reverso(frame** h)
{
    frame* prev   = NULL;
    frame* atual = *h;
    frame* next = NULL;
    while (atual != NULL)
    {
        next  = atual->prox;  
        atual->prox = prev;   
        prev = atual;
        atual = next;
    }
    *h = prev;
}
