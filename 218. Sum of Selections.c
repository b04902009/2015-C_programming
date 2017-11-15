#include <stdio.h>
int C(int n,int i)
{
    int sum = 1;
    for(int j = n;j > n-i; j --)  sum *= j;
    for(int j = 1;j <= i;j ++)  sum /= j;
    return sum;

}
int main(void)
{
    int n,m,ans = 0;
    scanf("%d%d",&n,&m);
    for(int i = 0;i <= m;i ++)  ans += C(n,i);
    printf("%d",ans);
}
