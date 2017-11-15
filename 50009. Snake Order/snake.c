#include "snake.h"
int snake(int *ptr, int *row, int *column)
{
    int len = 1,r,c = 0;
    for(int i = 1;i < 10000;i ++){
        if(ptr[i] == 0)    break;
        len ++;
    }
    for(int i = 0;i < len;i ++)
        if(ptr[i] == i)   c ++;
        else    break;
    r = len / c;
    *row = r;
    *column = c;

    int a[r+1][c+1];
    for(int i = 0;i < r;i ++)
        for(int j = 0;j < c;j ++)
            if(i % 2 == 0)    a[i][j] = ptr[i*c+j];
            else    a[i][c-1-j] = ptr[i*c+j];
    for(int i = 0;i < r;i ++)
        for(int j = 0;j < c;j ++)
            if(a[i][j] != i*c+j){
                *row = i;
                *column = j;
                return 0;
            }
    return 1;
}
