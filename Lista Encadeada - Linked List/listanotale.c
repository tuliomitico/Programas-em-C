#include <stdio.h>
#include <stdlib.h>
typedef struct reg {
	double nota;
	struct reg *prox;
} frame;

void input (frame** head_ref, double n); 

void imprime (frame *le);

float media(frame* lista);

int main() {
	int i = 0,j = 0, n;
	double x;
	frame* f1 = NULL;
	frame* f2;
	scanf("%d\n",&n);
	if (n == 0) {
		printf("Numero de notas invalido.");
	}
	else {
		for (i; i < n; i++) {
			scanf("%lf\n", &x);
			input(&f1, x);
		}
		for (f2 = f1; f2 != NULL; f2 = f2->prox) {
			j++;
			printf("Nota %d : %.1lf\n", j, f2->nota);
			}
		printf("Media: %.2f", media(f1));
	}
}
void input (frame** head_ref, double n) {                  //funcao utilizada pra criar a lista encadeada como se fosse um vetor,
	frame *novoframe = (frame *) malloc(sizeof(frame));//adiconando um elemento atras do outro e verifica se
    novoframe->nota = n;							   //se a primeira posicao é existente
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
		printf("%d ", le->nota);
		imprime(le->prox);
	}
}
float media (frame* lista) { 
   float soma = 0; 
   int n = 0; 
   frame* P; 
   P = lista; 
   while (P != NULL) { 
      soma += P->nota; 
      n++; 
      P = P->prox; 
   } 
   return (soma / n); 
} 
