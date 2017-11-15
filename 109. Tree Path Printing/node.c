#include "node.h"
#include <stdio.h>
int ans[1000], n = 0;
void print_all_paths(struct node *root){
   if(root->left == NULL && root->right == NULL){
        for(int i = 0; i < n; i++)  printf("%d ", ans[i]);
        printf("%d\n", root->data);
        return;
    }
    
    ans[n] = root->data;
    n++;
    if(root->left != NULL)  print_all_paths(root->left);
    if(root->right != NULL)  print_all_paths(root->right);
    n--; 
}