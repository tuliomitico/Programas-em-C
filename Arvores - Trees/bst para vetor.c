#include <stdio.h>
#include <stdlib.h>

typedef struct reg
{
    int carga,k;
    struct reg *esq;
    struct reg *dir;
} tree;

int AddToArray(tree *raiz, int arr[], int i);
tree *CreateNode(int n);
tree *Insert(tree *raiz, int n);
void erd(tree *r);
int count(tree *raiz);
int compara(const void * a, const void * b);
void quicksort(int *a,int left,int right);
//---------------------------------------------------------------------------
int main()
{
    int i;
    int size;
    int *arr = NULL;
    tree *raiz = NULL;

    printf("***TEST PROGRAM***\n");
    raiz = Insert(raiz, 4);
    raiz = Insert(raiz, 3);
    raiz = Insert(raiz, 5);
    raiz = Insert(raiz, 10);
    raiz = Insert (raiz, 8);
    raiz = Insert (raiz, 7);
    size = count(raiz);

    printf("\n***BINARY TREE (PREORDER)***\n");
    erd(raiz);
    printf("\nThe binary tree countain %d nodes", size);

    printf("\n\n***ARRAY***\n");
    arr = calloc(size, sizeof(int));
    AddToArray(raiz, arr, 0);
    quicksort(arr,0,size);

    for (i=0; i<size; i++)
    {
        printf("arr[%d]: %d\n", i, arr[i]);
    }
}
//---------------------------------------------------------------------------

int compara(const void * a, const void * b)
{
   return ( *(int*)a - *(int*)b );
}

int AddToArray(tree *raiz, int arr[], int i)
{
    if(raiz == NULL)
        return i;
     arr[i] = raiz->k;
     i++;
     if(raiz->esq != NULL)
          i=AddToArray(raiz->esq, arr, i);
     if(raiz->dir != NULL)
          i=AddToArray(raiz->dir, arr, i);

     return i;
}

tree *CreateNode(int n)
{
    tree *raiz = (tree *)malloc(sizeof(tree));
    raiz -> k = n;
    raiz -> esq = raiz -> dir = NULL;
    return raiz;
}

tree *Insert(tree *raiz, int n)
{
    if(raiz==NULL)
    {
        tree *temp;
        temp = CreateNode(n);
        return temp;
    }

    if(n >(raiz->k))
    {
        raiz->dir = Insert(raiz->dir,n);
    }
    else if(n < (raiz->k))
    {
        raiz->esq = Insert(raiz->esq,n);
    }

    /* Else there is nothing to do as the data is already in the tree. */
    return raiz;
}

void erd(tree *r)
{
    if(r==NULL)
    {
        return;
    }
    printf("%d ",r->k);
    erd(r->esq);
    erd(r->dir);
}

int count(tree *raiz)
{
    int c = 1;

    if (raiz == NULL)
        return 0;
    else
    {
        c += count(raiz->esq);
        c += count(raiz->dir);
        return c;
     }
}
void quicksort(int *a, int left, int right) {
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
        quicksort(a, left, j);
    }
    if(i < right) {
        quicksort(a, i, right);
    }
}
