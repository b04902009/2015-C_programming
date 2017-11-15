#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#define OUTOFBOUND -2147483648
#define HAVENOTSET -2147483647
#define SETSUCCESS 1
typedef struct array{
    int start,end,length;
    int arr[3000];
} ARRAY;
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
void test_specall() {
    int n, l, r;
    int cmds, cmd, aid;
    int index, value;
    scanf("%d", &n);
    ARRAY *a = (ARRAY *) malloc(sizeof(ARRAY)*n);
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &l, &r);
        init(&a[i], l, r);
    }
    scanf("%d", &cmds);
    for (int i = 0; i < cmds; i++) {
        scanf("%d %d", &cmd, &aid);
        if (cmd == 1) {
            print(&a[aid]);
        } else if (cmd == 2) {
            scanf("%d %d", &index, &value);
            int ret = set(&a[aid], index, value);
            printf("ARRAY ID %d, set(%d, %d) %s\n", aid, index, value, 
                ret == SETSUCCESS ? "SUCCESS" : (ret == OUTOFBOUND ? "OUTOFBOUND" : "HAVENOTSET"));
        } else if (cmd == 3) {
            scanf("%d", &index);
            int ret = get(&a[aid], index);
            printf("ARRAY ID %d, get(%d) ", aid, index);
            if (ret == OUTOFBOUND)    
                printf(": OUTOFBOUND\n");
            else if (ret == HAVENOTSET)
                printf(": HAVENOTSET\n");
            else
                printf("= %d\n", ret);
        } else if (cmd == 4) {
            sort(&a[aid]);
        } else {
            assert(0);
        }
    }
}
int main() {
    int spec = 0;
    void (*FUNC[])() = {test_specall};
    FUNC[spec]();
    return 0;
}