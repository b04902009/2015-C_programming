#include <stdio.h>
main()
{
    char a[5],b[5];
    scanf("%s", a);
    scanf("%s", b);
    int A = 0,B = 0,i,j;

    for(i = 0;i < 4;i ++){
        if(a[i] == b[i])  A++;
        for(j = 0;j < 4;j ++)
            if(a[i] == b[j] && i != j)  B++;
    }

    printf("%dA%dB", A, B);


    return 0;
}
