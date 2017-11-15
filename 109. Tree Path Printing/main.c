#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
struct node{
    struct node *left;
    struct node *right;
    int data;
};
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
struct node *insert_bs_tree(struct node *root, int data){
    struct node *current;
    if(root == NULL){
        current = (struct node *)malloc(sizeof(struct node));
        assert(current != NULL);
        current->data = data;
        current->left = NULL;
        current->right = NULL;
        return current;
    }
 
    if(data < root->data)
        root->left = insert_bs_tree(root->left, data);
    else
        root->right = insert_bs_tree(root->right, data);
    return root;
}
 
int main(void)
{
    int n;
    struct node *root = NULL;
 
    while (scanf("%d", &n) != EOF)
        root = insert_bs_tree(root, n);
 
    print_all_paths(root);
}