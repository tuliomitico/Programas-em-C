#include <stdio.h>
#include <stdlib.h>
const int l = 6;
// Data structure to store a Binary Search Tree node
typedef struct reg {
    int carga,k;
    struct reg *esq, *dir;
} tree;
 
// Function to create a new binary tree node having given key
tree* input(int n)
{
    tree* var = malloc(sizeof(tree));
    var->k = n;
    var->dir = var->esq = NULL;

    return var;
}
 
// Function to perform inorder traversal of the tree
void erd(tree* raiz)
{
    if (raiz == NULL)
        return;

    erd(raiz->esq);
    printf("%d\n",raiz->k);
    erd(raiz->dir);
}

// Iterative function to insert an key into BST. 
// Root is passed by reference to the function
void insertIterative(tree** root, int key)
{
    // start with root node
    //tree* noh = malloc(sizeof(tree));
    //noh = *(root);
    tree* curr = *(root);
 
    // pointer to store parent node of current node
    tree *pai = NULL;
 
    // if tree is empty, create a new node and set root
    if (*root == NULL)
    {
        *root = input(key);
        return;
    }
 
    // traverse the tree and find parent node of key
    while (curr != NULL)
    {
        // update parent node as current node
        pai = curr;
 
        // if given key is less than the current node, go to left subtree
        // else go to right subtree
        if (key < curr->k)
            curr = curr->esq;
        else
            curr = curr->dir;
    }
 
    // construct a new node and assign to appropriate parent pointer
    if (key < pai->k)
        pai->esq = input(key);
    else
        pai->dir = input(key);
}

// main function
void imprimegk(tree* r,int k) {
	int i = 0;
	if (r == NULL) return;
  	k += l; //cria se uma variavel q armazena esse valor a cada chamada da recursao
  	imprimegk(r->esq,k);
  	printf("\n");	
	for (i = l; i < k; i++)
	  printf(" ");
	printf("%d\n",r->k);
  	imprimegk(r->dir,k);	
}

void imprime(tree* r) { //para utilizaÃ§ao de menos variaveis na chamda funcao crie outra que armzena so a arvore sem o int
	imprimegk(r,0); //o 0 determina o tamanho da indentacao, no exemplo parace q a distancia e de 3 " ".
}
int main()
{
    tree* root = NULL;
    int i = 0;
        int keys[] = { 21, 14, 28, 11, 18, 
				   25, 32, 5, 12, 15,
				  19, 23, 27, 30, 37};
    int n = sizeof(keys) / sizeof(int);
    for (i ; i < n ; i++) {
        insertIterative(&root, keys[i]);}
 
    erd(root);
    imprime(root);
 
    return 0;
}
