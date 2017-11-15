#include <stdio.h>
#include <stdlib.h>
main()
{
    int sp[4],fp[4],lottery,money = 0,i,temp_fp[4];
    for(i = 0;i < 3;i ++)  scanf("%d",&sp[i]);
    for(i = 0;i < 3;i ++)  scanf("%d",&fp[i]);
    while(scanf("%d",&lottery) == 1){
        for(i = 0;i < 3;i ++){
            int temp = lottery;
            temp_fp[i] = fp[i];
            if(temp == sp[i]){
                money += 2000000;
                continue;
            }
            if(temp == temp_fp[i]){
                money += 200000;
                continue;
            }
            temp -= (temp/10000000)*10000000;
            temp_fp[i] -= (temp_fp[i]/10000000)*10000000;
            if(temp == temp_fp[i]){
                money += 40000;
                continue;
            }
            temp -= (temp/1000000)*1000000;
            temp_fp[i] -= (temp_fp[i]/1000000)*1000000;
            if(temp == temp_fp[i]){
                money += 10000;
                continue;
            }
            temp -= (temp/100000)*100000;
            temp_fp[i] -= (temp_fp[i]/100000)*100000;
            if(temp == temp_fp[i]){
                money += 4000;
                continue;
            }
            temp -= (temp/10000)*10000;
            temp_fp[i] -= (temp_fp[i]/10000)*10000;
            if(temp == temp_fp[i]){
                money += 1000;
                continue;
            }
            temp -= (temp/1000)*1000;
            temp_fp[i] -= (temp_fp[i]/1000)*1000;
            if(temp == temp_fp[i]){
                money += 200;
                continue;
            }
        }
    }
    printf("%d",money);

    return 0;
}
