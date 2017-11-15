#include <stdio.h>
#include <stdlib.h>
#include "activity.h"
int cmp(const void *a, const void *b){
	Activity *A = (Activity*)a, *B = (Activity*)b;
	return A->end > B->end;
}
int select(Activity activities[], int n){
	qsort(activities, n, sizeof(Activity), cmp);
	int num = 0, end = 0;
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