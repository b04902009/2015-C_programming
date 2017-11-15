#include <stdlib.h>
main(){
    int year,month,day,i;
    scanf("%d%d%d",&year,&month,&day);
    int m[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
    if(year % 400 == 0 || (year % 4 == 0 && year % 100 != 0) )  m[2] = 29;
    if(day > 6 || day < 0)  printf("invalid\n");
    else if(month > 12 || month < 1)  printf("invalid\n");
    else{
        printf(" Su Mo Tu We Th Fr Sa\n=====================\n");
        for(i = 0;i < day;i ++)  printf("   ");
        for(i = 1;i <= m[month];i ++){
            printf("%3d",i);
            if((day + i) % 7 == 0 || i == m[month])  printf("\n");
        }
        printf("=====================\n");
    }

    return 0;
}
