#include <stdio.h>
#include <stdlib.h>
const int l = 6;
typedef struct reg {
   int         k;
   int         carga;
   struct reg *esq, *dir; 
} tree; // noh

void imprime(tree* r);

tree* input(int n);

tree* buildTree(tree* root);

int AddToArray(tree *raiz, tree** arr, int i);

tree* Insert(tree *raiz, int n);

tree* 
removeraiz (tree* r) {  
    tree *p, *q;
    if (r->esq == NULL) {
       q = r->dir;
       free (r);
       return q;
    }
    p = r; q = r->esq;
    while (q->dir != NULL) {
       p = q; q = q->dir;
    }
    // q é nó anterior a r na ordem e-r-d
    // p é pai de q
    if (p != r) {
       p->dir = q->esq;
       q->esq = r->esq;
    }
    q->dir = r->dir;
    free (r);
    return q;
}
int altura_id(tree *raiz) { //funcao iterativa pra descobrir a altura de uma arvore binaria
	int hd = 0; //criar um contador para cada salto somar 1 ao valor
	if (raiz == NULL) return 0;
	else {
	
		while (raiz->dir != NULL || raiz->esq != NULL ){
			hd++; //contador
			if (raiz->esq == NULL) raiz = raiz->dir;
			
			else raiz = raiz->esq;
		
		}
		return hd;
	}
}

int altura_ie(tree *raiz) { //funcao iterativa pra descobrir a altura de uma arvore binaria para meio de comparacao da varredura anterior
	int he = 0;
	if (raiz == NULL) return 0;
	else {
	
		while (raiz->dir != NULL || raiz->esq != NULL ){
			he++;
			if (raiz->dir == NULL) raiz = raiz->esq;
			
			else raiz = raiz->dir;
		
		}
		return he;
	}
}

void altura_i(tree* raiz) { //reunindo as duas funcaos para comparacao
	int x = altura_id(raiz);
	int n = altura_ie(raiz);
	if ( x > n ){
	 printf("%d",x);
	} else printf("%d",n );
}

int main(void) {
	tree *raiz   = NULL;
	raiz = Insert(raiz,10);
	
	raiz   = Insert(raiz,9);
	raiz   = Insert(raiz,8);
	
	raiz   = Insert(raiz,7);
	raiz   = Insert(raiz,6);
	raiz   = Insert(raiz,5);
	raiz   = Insert(raiz,4);
	
	raiz   = Insert(raiz,3);
	raiz   = Insert(raiz,2);
	raiz   = Insert(raiz,1);
	raiz   = Insert(raiz,11);
	raiz   = Insert(raiz,12);
	raiz   = Insert(raiz,13);
	raiz   = Insert(raiz,14);
	raiz   = Insert(raiz,15);
	//raiz->esq = removeraiz(raiz->esq);
	imprime(raiz);
	altura_i(raiz);
	printf("Depois do balanceamento\n");
    /*raiz->esq   = input(2);
    raiz->dir  = input(11);
 
    raiz->esq->esq  = input(4);
    raiz->esq->dir = input(5);
    raiz->dir->esq  = input(6);
    raiz->dir->dir = input(12);
 
    raiz->esq->esq->esq  = input(8);
    raiz->esq->esq->dir  = input(9);
    raiz->esq->dir->esq  = input(10);
    raiz->esq->dir->dir  = input(11);
    raiz->dir->esq->esq  = input(12);
    raiz->dir->esq->dir  = input(13);
    raiz->dir->dir->esq  = input(14);
    raiz->dir->dir->dir  = input(13);*/
    raiz = buildTree(raiz);
    imprime(raiz);
}
tree* input(int n) {
	tree* var;
	var = (tree*) malloc (sizeof(tree));
	var->k = n;
	var->dir = NULL;
	var->esq = NULL;
	return var;
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
int AddToArray(tree *raiz, tree** arr, int i)
{
    if(raiz == NULL)
        return i;
     
     if(raiz->esq != NULL)
          i=AddToArray(raiz->esq, arr, i);
     *(arr+i) = raiz;
     i++;     
          
     if(raiz->dir != NULL)
          i=AddToArray(raiz->dir, arr, i);

     return i;
}
tree* Insert(tree *raiz, int n)
{
    if(raiz==NULL)
    {
        tree *temp;
        temp = input(n);
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
/*void armazenaBST(tree* root, tree* nodes[])
{
    // Base case
    if (root == NULL)
        return;
 
    // Store nodes in Inorder (which is sorted
    // order for BST)
    armazenaBST(root->esq, nodes);
    nodes[m] = root;
    m++;
    armazenaBST(root->dir, nodes);
}*/
/* Recursive function to construct binary tree */
tree* buildTreeUtil(tree* nodes[], int start,
                   int end)
{
    // base case
    if (start > end)
        return NULL;
 
    /* Get the middle element and make it root */
    int mid = (start + end)/2;
    tree *root = nodes[mid];
 
    /* Using index in Inorder traversal, construct
       left and right subtress */
    root->esq  = buildTreeUtil(nodes, start, mid-1);
    root->dir = buildTreeUtil(nodes, mid+1, end);
 
    return root;
}
 
// This functions converts an unbalanced BST to
// a balanced BST
tree* buildTree(tree* root)
{
    // Store nodes of given BST in sorted order
    tree** nodes;
    int n = count(root);
    nodes = malloc(n * sizeof(tree*));
    AddToArray(root,nodes,0);
 
    // Constucts BST from nodes[]
    
    return buildTreeUtil(nodes, 0, n-1);
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

void imprime(tree* r) { //para utilizaÃƒÂ§ao de menos variaveis na chamda funcao crie outra que armzena so a arvore sem o int
	imprimegk(r,0); //o 0 determina o tamanho da indentacao, no exemplo parace q a distancia e de 3 " ".
}

