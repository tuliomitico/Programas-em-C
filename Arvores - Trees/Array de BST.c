#include <stdio.h>
#include <stdlib.h>

const int l = 6;
// Data structure to store a Binary Search Tree node
typedef struct reg {
    int carga,k;
    struct reg *dir, *esq;
} tree;
void quick_sort(int *a, int left, int right) {
    int i, j, x, y;
     
    i = left;
    j = right;
    x = a[(left + right) / 2];
     
    while(i <= j) {
        while(a[i] < x && i < right) {
            i++;
        }
        while(a[j] > x && j > left) {
            j--;
        }
        if(i <= j) {
            y = a[i];
            a[i] = a[j];
            a[j] = y;
            i++;
            j--;
        }
    }
     
    if(j > left) {
        quick_sort(a, left, j);
    }
    if(i < right) {
        quick_sort(a, i, right);
    }
}
// Function to create a new binary tree node having given key
tree* input(int n)
{
    tree* var = malloc(sizeof(tree));
    var->k = n;
    var->dir = var->esq = NULL;

    return var;
}

// Function to perform in-order traversal of the tree
void erd(tree* raiz)
{
    if (raiz == NULL)
        return;

    erd(raiz->esq);
    printf("%d\n",raiz->k);
    erd(raiz->dir);
}

// Recursive function to insert an key into BST
tree* insere(tree* raiz, int k)
{
    // if the root is null, create a new node an return it
    if (raiz == NULL)
        return input(k);

    // if given key is less than the root node, recurse for left subtree
    if (k < raiz->k)
        raiz->esq = insere(raiz->esq, k);

    // if given key is more than the root node, recurse for right subtree
    else
        raiz->dir = insere(raiz->dir, k);

    return raiz;
}

// Function to construct balanced BST from given sorted array
// Note - root of the tree is passed by reference here
void convert_ord(int keys[], int low, int high, tree** root)
{	
	
    // base case
    if (low > high)
        return;

    // find middle element of current range
    int mid = (low + high) / 2;
	tree* raiz = input(keys[mid]);
    // construct a new node from mid element and assign it to root
    

    // left subtree of root will be formed by keys less than mid element
    convert_ord(keys, low, mid - 1, &raiz->esq);

    // right subtree of root will be formed by keys less than mid element
    convert_ord(keys, mid + 1, high, &raiz->dir);
	*(root) = raiz;
}

// Function to construct balanced BST from given unsorted array
tree* convert(int keys[], int n)
{
    // sort the keys first
    quick_sort(keys,0,n-1);

    // construct balanced BST
    tree *raiz = NULL;
    convert_ord(keys, 0, n-1, &raiz);

    // return root node of the tree
    return raiz;
}
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

// Construct balanced BST from given keys
int main()
{
    // input keys
    int keys[] = { 21, 14, 28, 11, 18, 
				   25, 32, 5, 12, 15,
				  19, 23, 27, 30, 37};/*,
				  17, 18, 19, 20, 21, 
				  22, 23, 24, 25, 26, 
				  27, 28, 29, 30, 31,32};*/
    int n = sizeof(keys)/sizeof(keys[0]);

    // construct balanced binary search tree
    tree* raiz = convert(keys, n);

    // print the keys in in-order fashion
    erd(raiz);
    imprime(raiz);

    return 0;
}
