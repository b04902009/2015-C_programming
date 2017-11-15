#include <stdio.h>
main()
{
    int t,i,M,j;
    scanf("%d",&t);
    int a[t];
    for(i = 0;i < t;i ++)  scanf("%d",&a[i]);
    scanf("%d",&M);
    int b[M];
    for(i = 0;i < M;i ++)  b[i] = 0;
    for(i = 0;i < t;i ++)  b[a[i]%M] ++;

    for(i = 0;i < M-1;i ++)  printf("%d\n",b[i]);
    printf("%d",b[M-1]);

    return 0;
}
