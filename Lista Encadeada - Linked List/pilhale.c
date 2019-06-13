#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct reg {
	int carga;
	struct reg* prox;	
} frame;

typedef struct rag {
	int carga;
	struct rag* prox;
} pilha;

void cabeca (pilha *h);
 
void input (pilha* head_ref, int n); 

void imprime (frame *le);

void empilha(frame **p, int n);

frame* pop(frame *p,int *n);

void display(frame *p);

int main() {
	int x;
	char y[30];
	frame *f1 = NULL;
	pilha *p1 = NULL;
	cabeca(p1);
	do {
		scanf("%s", y);
		if (strcmp(y,"PUSH") == 0) {
			scanf("%d",&x);
			input(&f1,x);
			empilha(&f1,x);
		}
		if (strcmp(y,"POP") == 0) {
			display(f1);
			pop(f1,&x);
		}
	} while(f1 != NULL);
	printf("STACK EMPTY");
}

void input (pilha* head_ref, int n) {                  //funcao utilizada pra criar a lista encadeada como se fosse um vetor,
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
void cabeca (pilha *h) {
	h=NULL;
}
void empilha(pilha **p, int n) {
	pilha* tmp=(pilha*) malloc (sizeof(pilha));
	if ( tmp == NULL ) {
		return;
	}
	tmp->carga = n;
	tmp->prox = *p;
	*p = tmp;
		
}
frame* pop(frame *p,int *n)
{
    frame* tmp = p;
    *n = p->carga;
    p = p->prox;
    free(tmp);
    return p;
}
void display(frame *p)
{
    frame *current;
    current = p;
    if(current!= NULL)
    {
        printf("Stack: ");
        do
        {
            printf("%d ",current->carga);
            current = current->prox;
        }
        while (current!= NULL);
        printf("\n");
    }
    else
    {
        printf("The Stack is empty\n");
    }
 
}
