#include <stdio.h>
main()
{
    int n,m,f[100],g[100],h[200] = {0};
    scanf("%d",&n);
    for(int i = n-1;i >= 0;i --)  scanf("%d",&f[i]);
    scanf("%d",&m);
    for(int i = m-1;i >= 0;i --)  scanf("%d",&g[i]);

    for(int i = 0;i < n;i ++)
        for(int j = 0;j < m;j ++)
            h[i+j] += f[i] * g[j];

    for(int i = n+m-2;i > 0; i--)  printf("%d ",h[i]);
    printf("%d",h[0]);

    return 0;
}
