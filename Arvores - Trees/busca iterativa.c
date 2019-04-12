#include<stdio.h>
#include <stdlib.h>
#include <stdbool.h>
typedef struct reg
{
    int k,carga;
    struct reg *esq, *dir;
} tree;
 
// Function to check the given key exist or not
tree* iterativeSearch(tree *root, int key)
{
    // Traverse untill root reaches to dead end
    while (root != NULL)
    {
        // pass right subtree as new tree
        if (key > root->k)
            root = root->dir;
 
        // pass left subtree as new tree
        else if (key < root->k)
            root = root->esq;
        else
            return true;// if the key is found return 1
    }
    return false;
}
 
// A utility function to create a new BST Node
tree *input(int item)
{
    struct reg *temp =  malloc(sizeof(tree));
    temp->k = item;
    temp->esq = temp->dir = NULL;
    return temp;
}
 
/* A utility function to insert a new Node with
   given key in BST */
tree* insert(tree* Node, int data)
{
    /* If the tree is empty, return a new Node */
    if (Node == NULL) return input(data);
 
    /* Otherwise, recur down the tree */
    if (data < Node->k)
        Node->esq  = insert(Node->esq, data);
    else if (data > Node->k)
        Node->dir = insert(Node->dir, data);
 
    /* return the (unchanged) Node pointer */
    return Node;
}
 
// Driver Program to test above functions
int main()
{
    /* Let us create following BST
              50
            /    \
          30      70
         /  \    /  \
       20   40  60   80 */
    tree *root = NULL;
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);
    if (iterativeSearch(root, 15))
        printf("Yes");
    else
        printf("No");
    return 0;
}

