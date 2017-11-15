#include <stdio.h>
main()
{
    int n;
    scanf("%d", &n);
    int x1,y1,x2,y2,x3,y3;
    int a,b,c;
    int i;
    for(i = 0;i < n;i ++){
        scanf("%d%d%d%d%d%d", &x1, &y1, &x2, &y2, &x3, &y3);
        a = (x1-x2)*(x1-x2)+(y1-y2)*(y1-y2);
        b = (x2-x3)*(x2-x3)+(y2-y3)*(y2-y3);
        c = (x3-x1)*(x3-x1)+(y3-y1)*(y3-y1);

        int temp = 0;
        if(a >= b && a >= c){
            temp = a;
            a = c;
            c = temp;
        }
        else if(b >= c && b >= a){
            temp = b;
            b = c;
            c = temp;
        }
        else ;
        if(a == b || b == c || c == a)  printf("isosceles\n");
        else if(a + b == c)  printf("right\n");
        else if(a + b <= c)  printf("obtuse\n");
        else  printf("acute\n");
    }
    return 0;
}
