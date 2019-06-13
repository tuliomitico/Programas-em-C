#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct reg{
	int carga;
	struct reg* prox;
} frame;

void input (frame** head_ref, int n); 

void imprime (frame *le);

void bubbleSort (frame *comeco);

void troca (frame *a, frame *b);

void remover(frame **head_ref, int y);

int main() {
	char a[30];
	int x, y, i = 0;
	frame* f1=NULL;
	while (scanf("%d", &x) != EOF) {
		input(&f1, x);
	}
	do {
		scanf("%s", a);
		if (strcmp (a, "parcial") == 0) {
			bubbleSort(f1);
			imprime(f1);
			printf("\n");
		}
		if (strcmp ( a, "inserir") == 0) {
			scanf("%d", &y);
			input(&f1, y);
		}
		if (strcmp (a, "remover") == 0) {
			scanf("%d", &y);
			remover(&f1,y);
		}
	} while (strcmp(a,"final") != 0); 
	bubbleSort(f1);
	imprime(f1);
	return 0;
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
/* Given a reference (pointer to pointer) to the head of a list
   and a key, deletes the first occurrence of key in linked list */
void remover(frame **head_ref, int y)
{
    // Store head node
    frame* temp = *head_ref, *prev;
 
 
    // If head node itself holds the key to be deleted
    if (temp != NULL && temp->carga == y)
    {
        *head_ref = temp->prox;   // Changed head
        free(temp);               // free old head
        return;
    }
 
    // Search for the key to be deleted, keep track of the
    // previous node as we need to change 'prev->prox'
    while (temp != NULL && temp->carga != y)
    {
        prev = temp;
        temp = temp->prox;
    }
 
    // If key was not present in linked list
    if (temp == NULL) return;
 
    // Unlink the node from linked list
    prev->prox = temp->prox;
 
    free(temp);  // Free memory
}
