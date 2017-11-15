#include <stdio.h>
#include "node.h"
struct node *merge(struct node *A, struct node *B){
    if(A == NULL)  return B;
    if(B == NULL)  return A;
    if(A->value < B->value){
        A->next = merge(A->next,B);
        return A;
    }
    else{
        B->next = merge(A,B->next);
        return B;
    }
}