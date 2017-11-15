#include <stdio.h>
#include <string.h>
int main(void)
{
    char c[11];
    int w,h,font[15][100];
    while(scanf("%s%d%d",c,&w,&h) != EOF){
        for(int i = 0;i < 15;i ++)
            for(int j = 0;j < 90;j ++)
                font[i][j] = -1;
        for(int n = 0;n < strlen(c);n ++){
            switch(c[n]-'0'){
                case 0:
                    for(int i = 1;i < h-1;i ++)
                        if(i != h/2){
                            font[i][n*w+w-2] = 0;
                            font[i][n*w] = 0;
                        }
                    for(int j = 1;j < w-2;j ++){
                        font[0][n*w+j] = 0;
                        font[h-1][n*w+j] = 0;
                    }
                    break;
                case 1:
                    for(int i = 1;i < h-1;i ++)    if(i != h/2)    font[i][n*w+w-2] = 1;
                    break;
                case 2:
                    for(int i = 1;i < h/2;i ++)    font[i][n*w+w-2] = 2;
                    for(int i = h/2+1;i < h-1;i ++)    font[i][n*w] = 2;
                    for(int j = 1;j < w-2;j ++){
                        font[0][n*w+j] = 2;
                        font[h/2][n*w+j] = 2;
                        font[h-1][n*w+j] = 2;
                    }
                    break;
                case 3:
                    for(int i = 1;i < h-1;i ++)    if(i != h/2)    font[i][n*w+w-2] = 3;
                    for(int j = 1;j < w-2;j ++){
                        font[0][n*w+j] = 3;
                        font[h/2][n*w+j] = 3;
                        font[h-1][n*w+j] = 3;
                    }
                    break;
                case 4:
                    for(int i = 1;i < h-1;i ++)    if(i != h/2)    font[i][n*w+w-2] = 4;
                    for(int i = 1;i < h/2;i ++)    font[i][n*w] = 4;
                    for(int j = 1;j < w-2;j ++)    font[h/2][n*w+j] = 4;
                    break;
                case 5:
                    for(int i = 1;i < h/2;i ++)    font[i][n*w] = 5;
                    for(int i = h/2+1;i < h-1;i ++)    font[i][n*w+w-2] = 5;
                    for(int j = 1;j < w-2;j ++){
                        font[0][n*w+j] = 5;
                        font[h/2][n*w+j] = 5;
                        font[h-1][n*w+j] = 5;
                    }
                    break;
                case 6:
                    for(int i = 1;i < h-1;i ++)    if(i != h/2)    font[i][n*w] = 6;
                    for(int i = h/2+1;i < h-1;i ++)    font[i][n*w+w-2] = 6;
                    for(int j = 1;j < w-2;j ++){
                        font[0][n*w+j] = 6;
                        font[h/2][n*w+j] = 6;
                        font[h-1][n*w+j] = 6;
                    }
                    break;
                case 7:
                    for(int i = 1;i < h-1;i ++)    if(i != h/2)    font[i][n*w+w-2] = 7;
                    for(int i = 1;i < h/2;i ++)    font[i][n*w] = 7;
                    for(int j = 1;j < w-2;j ++)    font[0][n*w+j] = 7;
                    break;
                case 8:
                    for(int i = 1;i < h-1;i ++)
                        if(i != h/2){
                            font[i][n*w+w-2] = 8;
                            font[i][n*w] = 8;
                        }
                    for(int j = 1;j < w-2;j ++){
                        font[0][n*w+j] = 8;
                        font[h/2][n*w+j] = 8;
                        font[h-1][n*w+j] = 8;
                    }
                    break;
                case 9:
                    for(int i = 1;i < h-1;i ++)    if(i != h/2)    font[i][n*w+w-2] = 9;
                    for(int i = 1;i < h/2;i ++)    font[i][n*w] = 9;
                    for(int j = 1;j < w-2;j ++){
                        font[0][n*w+j] = 9;
                        font[h/2][n*w+j] = 9;
                    }
                    break;
            }
        }

        for(int i = 0;i < h;i ++){
            for(int j = 0;j < w*strlen(c)-1;j ++)
                font[i][j] != -1 ? printf("%d",font[i][j]) : printf(" ");
            printf("\n");
        }
    }
    return 0;
}
