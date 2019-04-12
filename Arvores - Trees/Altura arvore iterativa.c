#include <stdio.h>
#include <stdlib.h>

typedef struct rig {
	int data;
	struct rig* prox;
}frame;

typedef struct reg{
	int carga;
	struct reg *dir,*esq;
}tree;
typedef tree *arvore;

frame *colocanafila(int y,frame *fi);

int contavai(frame *le);

int altura_i(tree *raiz){
	int h = 0;
	if (raiz == NULL) return 0;
	else {
	
		while (raiz->dir != NULL || raiz->esq != NULL ){
			h++;
			if (raiz->esq == NULL) raiz = raiz->dir;
			
			else raiz = raiz->esq;
		
		}
		return h+1;
	}
}

int main() {
	/*frame *fi;
	frame *f2 = NULL;
	fi = malloc (sizeof (frame));
	fi->prox = fi;
	f2 = colocanafila(5,fi);
	for (int i = 0; i < 6; i++){
		f2 = colocanafila(i,fi);
	}*/
		tree a1, a3, a4, a5, a8, a9;
	a1.carga = 111;
	a3.carga = 333;
	a4.carga = 444;
	a5.carga = 555;
	a8.carga = 888;
	a9.carga = 999;
	
	a5.dir = &a8; 
	a5.esq = &a3;
	
	a3.dir = &a4;
	a3.esq = &a1;
	
	a8.dir = &a9;
	a8.esq = NULL;
	
	a1.dir = NULL;
	a1.esq = NULL;
	
	a4.dir = NULL;
	a4.esq = NULL;
	
	a9.dir = NULL;
	a9.esq = NULL;
	
	printf("%d",altura_i(&a5));
}

/*frame *colocanafila (int y, frame *fi) { 
   frame *nova;
   nova = malloc (sizeof (frame));
   nova->prox = fi->prox;
   fi->prox = nova;
   fi->data = y;
   return nova;
}
frame *empurrefila (tree *fi) {
	frame* novo;
	novo = malloc(sizeof(frame));
	novo->prox = fi->esq;
	fi->prox =novo;
	return novo;
}
int contavai(frame *le) { //contando a quantidade de elementos de uma lista encadeada					
						  // adaptado da funcao imprime
   frame *p;
   int i;
   for (p = le; p != NULL; p = p->prox) 
      i++;
      return i;
}
int tiradafila (frame *fi) {
   frame *p;
   p = fi->prox;  // o primeiro da fila
   int x = p->data;
   fi->prox = p->prox;
   free (p);
   return x;  
}

int treeHeight(tree *root)
{
    // Base Case
    if (root == NULL)
        return 0;
 
    // Create an empty queue for level order tarversal
    frame *q;
 
    // Enqueue Root and initialize height
    q = empurrefila(root);
    int height = 0;
 
    while (1)
    {
        // nodeCount (queue size) indicates number of nodes
        // at current lelvel.
        int nodeCount = contavai(q);
        if (nodeCount == 0)
            return height;
 
        height++;
 
        // Dequeue all nodes of current level and Enqueue all
        // nodes of next level
        while (nodeCount > 0)
        {
            tree *node = q;
  			tiradafila(q);
            if (node->esq != NULL)
                q=empurrefila(node->esq);
            if (node->dir != NULL)
                q=empurrefila(node->dir);
            nodeCount--;
        }
    }
}*/

