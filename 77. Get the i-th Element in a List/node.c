#include "node.h"
#include <stdio.h>
int count(struct node *head){
	if(head->next == NULL)  return 1;
	return 1+count(head->next);
}
struct node *getNode(struct node *head, unsigned int i){
	int n = count(head), j;
	if(i >= n)  return NULL;
	for(j = 0; j < n-i-1; j++)
		head = head->next;
	return head;
}