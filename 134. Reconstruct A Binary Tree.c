#include <stdio.h>
#include <stdlib.h>
typedef struct{
	int d, l;
} Data;
typedef struct node{
    struct node *left;
    struct node *right;
    int data;
} Node;
int cmp(const void *a, const void *b){
	Data *A = (Data*)a, *B = (Data*)b;
	return A->l - B->l;
}
Node *insert_tree(Node *root, int data){
    Node *current;
    if(root == NULL){
        current = (Node *)malloc(sizeof(Node));
        current->data = data;
        current->left = NULL;
        current->right = NULL;
        return current;
    }
 
    if(data < root->data)
        root->left = insert_tree(root->left, data);
    else
        root->right = insert_tree(root->right, data);
    return root;
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
int main(){
	int n, ad, bd, p;
	Data data[1050];
	scanf("%d", &n);
	for(int i = 0; i < n; i++)
		scanf("%d%d", &data[i].d, &data[i].l);
	qsort(data, n, sizeof(Data), cmp);

	Node *root = NULL, *ptr;
	for(int i = 0; i < n; i++)
		root = insert_tree(root, data[i].d);
	//print_all_paths(root);

	scanf("%d", &p);
	int al, bl, ans;
	while(p--){
		ptr = root;
		scanf("%d%d", &ad, &bd);
		for(int i = 0; i < n; i++){
			if(ad == data[i].d)  al = data[i].l;
			if(bd == data[i].d)  bl = data[i].l;
		}

		ans = al + bl;
		while(1){
			ans -= 2;
			if(ad < ptr->data && bd < ptr->data)
				ptr = ptr->left;
			else if(ad > ptr->data && bd > ptr->data)
				ptr = ptr->right;
			else  break;
		}
		printf("%d\n", ans);
	}

	return 0;
}