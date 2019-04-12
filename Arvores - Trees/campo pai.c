#include<stdio.h>
#include<stdlib.h>
 
typedef struct reg
{
    int k,carga;
    struct reg *esq, *dir, *pai;
} tree;
 
// A utility function to create a new BST Node
tree *input(int n)
{
    tree *temp =  malloc(sizeof(tree));
    temp->k = n;
    temp->esq = temp->dir = NULL;
    temp->pai = NULL;
    return temp;
}
 
// A utility function to do inorder traversal of BST
void erd(tree *raiz)
{
    if (raiz != NULL)
    {
        erd(raiz->esq);
        printf("Noh : %d, ", raiz->k);
        if (raiz->pai == NULL)
          printf("Pai : NULL \n");
        else
          printf("Pai : %d \n", raiz->pai->k);
        erd(raiz->dir);
    }
}
 
/* A utility function to insert a new Node with
   given key in BST */
tree* insere(tree* raiz, int n)
{
    /* If the tree is empty, return a new Node */
    if (raiz == NULL) return input(n);
 
    /* Otherwise, recur down the tree */
    if (n < raiz->k)
    {
        tree *aux = insere(raiz->esq, n);
        raiz->esq  = aux;
 
        // Set parent of root of left subtree
        aux->pai = raiz;
    }
    else if (n > raiz->k)
    {
        tree *aux1 = insere(raiz->dir, n);
        raiz->dir  = aux1;
 
        // Set parent of root of right subtree
        aux1->pai = raiz;
    }
 
    /* return the (unchanged) Node pointer */
    return raiz;
}
 
// Driver Program to test above functions
int main()
{
    /* Let us create following BST
              50
           /     \
          30      70
         /  \    /  \
       20   40  60   80 */
    tree *root = NULL;
    root = insere(root, 50);
    insere(root, 30);
    insere(root, 20);
    insere(root, 40);
    insere(root, 70);
    insere(root, 60);
    insere(root, 80);
 
    // print iNoder traversal of the BST
    erd(root);
 
    return 0;
}

