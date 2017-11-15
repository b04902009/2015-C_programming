#include <stdio.h>
#include <stdlib.h>
int ptr = 0;
char arr[5000];
typedef struct node{
    struct node *left;
    struct node *right;
    int data;
} Node;

Node *tree(){
    Node *head = (Node *)malloc(sizeof(Node));
    if(arr[ptr] <= '9' && arr[ptr] >= '0'){
        int n = arr[ptr++]-'0';
        while(arr[ptr] <= '9' && arr[ptr] >= '0')
            n = n*10 + (arr[ptr++]-'0');

        head->data = n;
        head->left = NULL;
        head->right = NULL;
    }
    else if(arr[ptr] == '('){
        ptr++;
        Node *l = tree();
        ptr++;
        Node *r = tree();
        ptr++;
        head->left = l;
        head->right = r;
        head->data = l->data + r->data;
    }
    return head;
}
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
void HRHL(Node *root);
void HLHR(Node *root){
    printf("%d\n", root->data);
    if(root->left != NULL)  HRHL(root->left);
    printf("%d\n", root->data);
    if(root->right != NULL)  HRHL(root->right);
}
void HRHL(Node *root){
    printf("%d\n", root->data);
    if(root->right != NULL)  HLHR(root->right);
    printf("%d\n", root->data);
    if(root->left != NULL)  HLHR(root->left);
}
int main()
{
	scanf("%s", arr);
    Node *root = ((Node *)malloc(sizeof(Node)));
    root = tree();
    HLHR(root);
   // print_all_paths(root);
	return 0;
}