#include "subtree.h"
#include <stdio.h>
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