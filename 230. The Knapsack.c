#include <stdio.h>
struct object{
    int w;
    int v;
};
struct object obj[21];
int max(int a,int b)
{
    if(a > b)    return a;
    else    return b;
}
int knapsack(int W,int n)
{
    if(n < 0 || W <= 0)    return 0;
    if(W-obj[n].w >= 0)    return max(knapsack(W,n-1),knapsack(W-obj[n].w,n-1)+obj[n].v);
    else    return knapsack(W,n-1);
}
int main(void)
{
    int n,W;
    scanf("%d%d",&n,&W);
    for(int i = 0;i < n;i ++)
        scanf("%d%d",&obj[i].w,&obj[i].v);

    printf("%d",knapsack(W,n-1));

    return 0;
}
