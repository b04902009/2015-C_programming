#include <stdio.h>
main()
{
    int n;
    scanf("%d", &n);
    int x1,y1,x2,y2,x3,y3,x4,y4;
    int l[7] = {0};
    int i,j,k;
    for(i = 0;i < n;i ++){
        scanf("%d%d%d%d%d%d%d%d", &x1, &y1, &x2, &y2, &x3, &y3, &x4, &y4);
        l[1] = (x1-x2)*(x1-x2)+(y1-y2)*(y1-y2);
        l[2] = (x2-x3)*(x2-x3)+(y2-y3)*(y2-y3);
        l[3] = (x3-x4)*(x3-x4)+(y3-y4)*(y3-y4);
        l[4] = (x4-x1)*(x4-x1)+(y4-y1)*(y4-y1);
        l[5] = (x3-x1)*(x3-x1)+(y3-y1)*(y3-y1);
        l[6] = (x4-x2)*(x4-x2)+(y4-y2)*(y4-y2);

        int temp;
        for(k = 5;k > 0;k --)
            for(j = 1;j <= k;j ++)
                if(l[j] < l[j+1]){
                    temp = l[j];
                    l[j] = l[j+1];
                    l[j+1] = temp;
                }

        if(l[1]+l[2] == l[3]+l[4]+l[5]+l[6]){
            if(l[1] == 2*l[3])  printf("square\n");
            else if(l[1] == l[3]+l[5])  printf("rectangle\n");
            else  printf("diamond\n");
        }
        else if(l[1]+l[6] == l[2]+l[3]+l[4]+l[5])  printf("diamond\n");
        else  printf("other\n");

    }
    return 0;
}
