#include <stdio.h>
main()
{
    int n;
    scanf("%d", &n);
    int i,num[n+1];
    int a = 0,b = 0,c = 0;
    for(i = 0;i < n;i ++){
        scanf("%d", &num[i]);
        if(num[i] % 3 == 0)  a ++;
        if(num[i] % 3 == 1)  b ++;
        if(num[i] % 3 == 2)  c ++;
    }
    printf("%d %d %d",a,b,c);

    return 0;
}
