#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
typedef struct reg {
	int carga;
	struct reg *prox;
} frame;
//Referenciando as funcoes previamente e o struct
void bubbleSort (frame *comeco);

void troca (frame *a, frame *b);

void imprime (frame *le);

void input (frame** head_ref, int n);

int main () {
	int x;
	frame* f1 = NULL; //eh lista 
	while(scanf("%d", &x) != EOF) {
    input(&f1, x);
	}
	bubbleSort(f1);
	imprime(f1);

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
		printf("%d ", le->carga);
		imprime(le->prox);
	}
}
void bubbleSort(frame *comeco)
{
    int trocado, i;
    frame *ptr1;
    frame *uptr = NULL;
 
    /* Vendo se nao esta vazio */
    if (comeco == NULL)
        return;
 
    do
    {
        trocado = 0;
        ptr1 = comeco;
 
        while (ptr1->prox != uptr)
        {
            if (ptr1->carga > ptr1->prox->carga)
            { 
                troca(ptr1, ptr1->prox);
                trocado = 1;
            }
            ptr1 = ptr1->prox;
        }
        uptr = ptr1;
    }
    while (trocado);
}
 
/* funcao pra trocar os elementos da carga*/
void troca(frame *a, frame *b)
{
    int aux = a->carga;
    a->carga = b->carga;
    b->carga = aux;
}
