#include <stdio.h>
main()
{
    int M,N,X1,Y1,E1,N1,F1,X2,Y2,E2,N2,F2,t = 0;
    scanf("%d%d",&M,&N);
    scanf("%d%d%d%d%d%d%d%d%d%d",&X1,&Y1,&E1,&N1,&F1,&X2,&Y2,&E2,&N2,&F2);
    int temp_N1 = N1,temp_E1 = E1,temp_N2 = N2,temp_E2 = E2;
    while(1){
        if(F1 > 0 && temp_N1 != 0){
            Y1 ++;
            temp_N1 --;
        }
        else if(F1 > 0 && temp_N1 == 0 && temp_E1 != 0){
            X1 ++;
            temp_E1 --;
        }
        if(F1 > 0 && temp_N1 == 0 && temp_E1 == 0){
            temp_N1 = N1;;
            temp_E1 = E1;
        }
        if(X1 == M)  X1 = 0;
        if(Y1 == N)  Y1 = 0;
        F1 --;

        if(F2 > 0 && temp_E2 != 0){
            X2 ++;
            temp_E2 --;
        }
        else if(F2 > 0 && temp_E2 == 0 && temp_N2 != 0){
            Y2 ++;
            temp_N2 --;
        }
        if(F2 > 0 && temp_N2 == 0 && temp_E2 == 0){
            temp_N2 = N2;;
            temp_E2 = E2;
        }
        if(X2 == M)  X2 = 0;
        if(Y2 == N)  Y2 = 0;
        F2 --;
        t ++;

        if(X2 == X1 && Y2 == Y1){
            printf("robots explode at time %d",t);
            break;
        }
        if(F1 <= 0 && F2 <= 0){
            printf("robots will not explode");
            break;
        }
    }

    return 0;
}
