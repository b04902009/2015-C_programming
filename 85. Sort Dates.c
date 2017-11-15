#include <stdio.h>
#include <stdlib.h>
typedef struct{
	int y, m, d;
} Date;
int cmp(const void *a, const void *b){
	Date A = *(Date *)a, B = *(Date *)b;
	if(A.y == B.y){
		if(A.m == B.m)  return A.d - B.d;
		return A.m - B.m;
	}
	return A.y - B.y;
}
Date date[1000000];
int main(){
	int n;
	scanf("%d", &n);
	for(int i = 0; i < n; i++)
		scanf("%d%d%d", &date[i].y, &date[i].m, &date[i].d);

	qsort(date, n, sizeof(Date), cmp);
	for(int i = 0; i < n; i++)
		printf("%d %d %d\n", date[i].y, date[i].m, date[i].d);
	
	return 0;
}