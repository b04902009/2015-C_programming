#include "array.h"
#include <stdio.h>
void init(ARRAY *a,  int left, int right)
{
    a->start = left;
    a->end = right;
    a->length = right-left+1;
    for(int i = 0;i < a->length;i ++)
        a->arr[i] = -2147483647;
}
int set(ARRAY *a, int index, int value)
{
    if(index >= a->start && index <= a->end){
        a->arr[index-a->start] = value;
        return 1;
    }
    return -2147483648;
}
int get(ARRAY *a, int index)
{
    if(index >= a->start && index <= a->end)
        return a->arr[index-a->start];
    return -2147483648;
}
void print(ARRAY *a)
{
    for(int i = 0;i < a->length;i ++)
        a->arr[i] == -2147483647 ? printf("No value\n") : printf("%d\n",a->arr[i]);
}
int cmp(const void *a,const void *b){
    return *(int*)a > *(int*)b;
}
void sort(ARRAY *a)
{
    qsort(a->arr,a->length,sizeof(int),cmp);
    /* Bubble sort
    for(int i = 0;i < a->length-1;i ++)
        for(int j = 0;j < a->length-1-i;j ++)
            if(a->arr[j] > a->arr[j+1]){
                int temp = a->arr[j];
                a->arr[j] = a->arr[j+1];
                a->arr[j+1] = temp;
            }
    */
    
}