#include <stdio.h>
main()
{
    int x,y,min_x = 10000,min_y = 10000,max_x = -10000,max_y = -10000;
    while(scanf("%d%d",&x,&y) == 2){
        if(x < min_x)  min_x = x;
        if(x > max_x)  max_x = x;
        if(y < min_y)  min_y = y;
        if(y > max_y)  max_y = y;
    }

    printf("%d",(max_x-min_x)*(max_y-min_y));

    return 0;
}
