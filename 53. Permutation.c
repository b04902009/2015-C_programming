#include<stdio.h>
#include<stdlib.h>
int num,n[10],take[10] = {0},ans[10];
int cmp(const void*a, const void*b)
{
    return *(int *)a-*(int *)b;
}
void permutation(int t)
{
    if(t == num){
        for(int i = 0;i < num;i ++)    printf("%d%c",ans[i],i == t-1? '\n' : ' ');
        return;
    }
    for(int i = 0;i < num;i ++){
        if(take[i] == 0){
            take[i] = 1;
            ans[t] = n[i];
            permutation(t+1);
            take[i] = 0;
        }
    }
}
int main(void)
{
    scanf("%d",&num);
    for(int i = 0;i < num;i ++)    scanf("%d",&n[i]);
    qsort(n,num,sizeof(int),cmp);

    permutation(0);
    return 0;
}
