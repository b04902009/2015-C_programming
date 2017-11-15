#include <stdlib.h>
main()
{
    int a,b,c,d,e,f,flag = 0;
    scanf("%d%d%d",&a,&b,&c);
    for(d = -10000;d < 10000;d ++){
        for(e = -10000;e < 10000;e ++){
            f = a - d - e;
            if(d*e*f == c && d*e+e*f+f*d == b){
                flag = 1;
                break;
            }
        }
        if(flag == 1)  break;
    }
    printf("%d %d %d",d,e,f);

    return 0;
}
