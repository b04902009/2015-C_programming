#include <stdio.h>
#include <stdlib.h>
typedef struct{
	int x, y;
	unsigned long long int d;
} COOR;
int cmp(const void *a, const void *b){
	COOR A = *(COOR *)a, B = *(COOR *)b;
	if(A.d == B.d){
		if(A.x == B.x)  return A.y > B.y;
		return A.x > B.x;
	}
	return A.d > B.d;
}
int main(){
	COOR coor[100005];
	int n = 0;
	while(~scanf("%d%d", &coor[n].x, &coor[n].y)){
		coor[n].d = coor[n].x*coor[n].x + coor[n].y*coor[n].y;
		n++;
	}
	qsort(coor, n, sizeof(COOR), cmp);
	unsigned long long int ans = coor[0].d;
	for(int i = 0; i < n-1; i++){
		ans += (coor[i+1].x-coor[i].x)*(coor[i+1].x-coor[i].x);
		ans += (coor[i+1].y-coor[i].y)*(coor[i+1].y-coor[i].y);
	}
	printf("%lld", ans);
	return 0;
}