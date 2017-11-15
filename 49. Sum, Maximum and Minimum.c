#include <stdio.h>
main()
{
    int N,m;
    scanf("%d%d",&N,&m);
    int num[N],sum[m],max[m],min[m];
    for(int i = 0;i < m;i ++){
        sum[i] = 0;
        max[i] = 0;
        min[i] = 10000;
    }
    for(int i = 0;i < N;i ++){
        scanf("%d",&num[i]);
        sum[num[i]%m] += num[i];
        if(num[i] > max[num[i]%m])  max[num[i]%m] = num[i];
        if(num[i] < min[num[i]%m])  min[num[i]%m] = num[i];
    }
    for(int i = 0;i < m-1;i ++)  printf("%d %d %d\n",sum[i],max[i],min[i]);
    printf("%d %d %d",sum[m-1],max[m-1],min[m-1]);

    return 0;
}
