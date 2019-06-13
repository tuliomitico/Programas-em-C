#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct reg {
	int carga;
	struct reg *prox;
} frame;
//Referenciando as funcoes previamente e o struct
void input (frame** head_ref, int n);

void imprime (frame *le);

frame *intersec (frame *s1, frame *s2);

bool existe (frame *s, int n);

void bubbleSort (frame *comeco);

void troca (frame *a, frame *b);

void removerep (frame** h);

int main () {
	int i,n = 20,x,y;
	frame* f1 = NULL; //sao lista 
	frame* f2 = NULL; 
	frame* f3 = NULL;

	for (i = 0; i < n; i++) {
		scanf("%d", &x);
		input(&f1, x);
    }
    for (i = 0; i < n; i++) {
    	scanf("%d", &y);
    	input(&f2, y);
    }
	f3 = intersec(f1, f2);
	if (f3 == 0){
		printf("VAZIO");
	}
	else {
		removerep(&f3);
		bubbleSort(f3);
		imprime(f3);
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
void removerep(frame** h){ //funcao para remover duplicatas e repeticoes da lista encadeada
    frame* frameatual = *h;// no caso enquanto a lista estiver desordenada
    frame* frameuso = (*h)->prox;
    frame* frameusoant = *h;
    int i = -1;
    while(frameatual->prox != NULL){
        i++;
        if(i){
            frameatual = frameatual->prox;  //faz se o uso de swaps ou trocas a partir desse ponto como na ordenacao
            frameusoant = frameatual;
            frameuso = frameatual->prox;
        }
        while(frameuso != NULL){
            if(frameuso->carga == frameatual->carga){
                frameusoant->prox = frameuso->prox;
                free(frameuso);                //elimina a duplicata
                frameuso = frameusoant->prox;
            }else{
                frameusoant = frameusoant->prox;
                frameuso = frameuso->prox;
            }
        }
    }
}
