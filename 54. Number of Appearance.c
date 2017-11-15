#include <stdio.h>
main()
{
    char N[3],M[8];
    scanf("%s%s",N,M);
    int i,time;
    for(i = 0;i < 7;i ++)
        if(M[i] == N[0] && M[i+1] == N[1])  time ++;
    printf("%d",time);

    return 0;
}
