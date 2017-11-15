#include <stdlib.h>
main()
{
    int year,day,n,month,date,i,j,leap = 0;
    scanf("%d%d%d",&year,&day,&n);
    int D[13] = {0,31,28,31,30,31,30,31,31,30,31,30,31};
    if((year % 100 !=0 && year % 4 == 0) || year % 400 == 0)  leap = 1;
    if(leap == 1)   D[2] ++;
    for(i = 0;i < n;i ++){
        scanf("%d%d",&month,&date);
        if(month > 12 || month < 1)  printf("-1\n");
        else if(date > D[month] || date <= 0)  printf("-2\n");
        else{
            for(j = 1;j < month;j ++)   date += D[j];
            if(leap)  printf("%d\n",(date%7+day+6)%7);
            else  printf("%d\n",(date%7+day+6)%7);
        }
    }

    return 0;
}
