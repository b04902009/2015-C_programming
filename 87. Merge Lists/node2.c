#include <stdio.h>
#include "node.h"
struct node *merge(struct node *A, struct node *B){
    struct node *head, *ptr;
    if(A->value < B->value){
        head = A;
        A = A->next;
    }
    else{
        head = B;
        B = B->next;
    }
    ptr = head;
    while(A != NULL || B != NULL){
        if(A == NULL){
            ptr->next = B;
            B = B->next;
        }
        else if(B == NULL){
            ptr->next = A;
            A = A->next;
        }
        else if(A->value > B->value){
            ptr->next = B;
            B = B->next;
        }
        else if(A->value < B->value){
            ptr->next = A;
            A = A->next;
        }
        ptr = ptr->next;
    }

    return head;
}