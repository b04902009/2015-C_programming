#include <stdio.h>
#include <stdlib.h>
#include <assert.h> 
typedef struct Node {
    int label;
    struct Node *left, *right;
} Node;
int num = 0;
int get(Node *root, int label[], int k){
    if(root->label == k){
        if(root->left == NULL && root->right == NULL)  return 1;
        if(root->left != NULL)  get(root->left, label, k);
        if(root->right != NULL)  get(root->right, label, k);
        return 1;
    }
    
    if(root->left == NULL && root->right == NULL)  return 0;
    int l = 0, r = 0;
    if(root->left != NULL)  l = get(root->left, label, k);
    if(root->right != NULL)  r = get(root->right, label, k);
    if(l && r){
        label[num] = root->label;
        num++;
    }
    return (l || r);
}
int getNode(Node *root, int label[], int k){
    num = 0;
    get(root, label, k);
    return num;
}
Node* newNode(int label, Node *l, Node *r) {
    Node *u = (Node *) malloc(sizeof(Node));
    u->label = label, u->left = l, u->right = r;
    return u;
}
int main() {
    Node *root = newNode(
        10,
            newNode(
                5,
                    newNode(1, NULL, NULL),
                    newNode(1, NULL, NULL)               
            ),
            newNode(
                7,
                    newNode(1, NULL, NULL),
                    newNode(5, NULL, NULL)               
            )
    );
    int k;
    while (scanf("%d", &k) == 1) {
        int A[128];
        int n = getNode(root, A, k);
        printf("%d\n", n);
        for (int i = 0; i < n; i++)
            printf("%d%c", A[i], i == n-1 ? '\n' : ' ');
    }
    return 0;
}