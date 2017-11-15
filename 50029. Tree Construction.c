#include <stdio.h>
#include "tree.h"
 
void link(Node *ptr,int p, int array[], int n){
    Node *l = (Node*)malloc(sizeof(Node)), *r = (Node*)malloc(sizeof(Node));
    ptr->label = array[p];
    if(p*2+1 < n){
        ptr->left = l;
        link(l, p*2+1, array, n);
    }
    else  ptr->left = NULL;
    if(p*2+2 < n){
        ptr->right = r;;
        link(r, p*2+2, array, n);
    }
    else  ptr->right = NULL;
}
 
Node* construct(int array[], int n){
    Node *root = (Node*)malloc(sizeof(Node));
    link(root, 0, array, n);
    return root;
}