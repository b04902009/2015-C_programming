#include<stdio.h>
int main(void)
{
    int n;
    double A[17][17],B[17]={0},C[17];
    scanf("%d",&n);
    for(int i = 0;i < n;i ++)
        for(int j = 0;j < n;j ++)
            scanf("%lf",&A[i][j]);
    for(int i = 0;i < n;i ++)
        scanf("%lf",&C[i]);
    for(int i = n-1;i >= 0;i --)
        for(int j = n-1;j >= i;j --){
            if(j > i)    C[i] -= A[i][j] * B[j];
            if(i == j)   B[i] =  C[i] / A[i][j];
        }

    for(int i = 0;i < n;i ++)    printf("%f\n",B[i]);

    return 0;
}
