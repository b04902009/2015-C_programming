#include <stdio.h>
#include <stdlib.h>
#define MAXN 262144
#undef PRINT
typedef struct activity {
    int start;
    int end;
} Activity;
Activity A[MAXN];
int cmp(const void *a, const void *b){
	Activity *A = (Activity*)a, *B = (Activity*)b;
	return A->end > B->end;
}
int select(Activity activities[], int n){
	qsort(activities, n, sizeof(Activity), cmp);
	int num = 0, end = 0;
	for(int i = 0; i < n; i++)
		printf("%d %d\n", activities[i].start, activities[i].end);
	for(int i = 0; i < n; i++)
		if(activities[i].start >= end){
			#ifdef PRINT
			printf("%d %d\n", activities[i].start, activities[i].end);
			#endif
			end = activities[i].end;
			num++;
		}
	return num;
}
int main() {
    int n;
    while (scanf("%d", &n) == 1) {
        for (int i = 0; i < n; i++)
            scanf("%d %d", &A[i].start, &A[i].end);
        int ret = select(A, n);
        printf("%d\n", ret);
    }
    return 0;
}