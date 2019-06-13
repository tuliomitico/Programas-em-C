#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
typedef struct reg {
	int carga;
	struct reg *prox;
} frame;

bool existe(frame *s,int n);

void input (frame** head_ref,int n);

void imprime (frame *le);

frame *uniao (frame *s1, frame *s2);

int main() {
	int i, x, y, n, o;
	frame* f1 = NULL;
	frame* f2 = NULL;
	frame* f3 = NULL;
	
	scanf("%d", &n);
	for (i = 0; i < n; i++) {
		scanf("%d", &x);
		input(&f1, x);
	}
	scanf("%d", &o);
	for (i = 0;i < o; i++) {
		scanf("%d", &y);
		input(&f2, y);
	}
	if (n < 1|| o < 1){
		printf("Erro - A lista deve ter pelo menos 1 elemento.");
	} 
	else {
		f3 = uniao(f1,f2);
		imprime (f3);
	}
}
void input (frame** head_ref,int n) {
    frame *novoframe = (frame *) malloc(sizeof(frame));
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
void imprime (frame *le) {
    if (le!=NULL) {
        printf("%d\n",le->carga);
        imprime(le->prox);
    }
}
frame *uniao (frame *s1, frame *s2)
{
    frame *r = NULL;
    frame *t1 = s1, *t2 = s2;
 
    // insere os elemetnos da 1 lista ao resultado final
    while (t1 != NULL)
    {
        input(&r, t1->carga);
        t1 = t1->prox;
    }
 
    // Insere os elementos da lista 2
    // que nao estao presentes no resultado final
    while (t2 != NULL)
    {
        if (!existe(r, t2->carga))
            input(&r, t2->carga);
        t2 = t2->prox;
    }
 
    return r;
}
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
