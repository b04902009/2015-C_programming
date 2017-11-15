#include <stdio.h>
#include <stdlib.h>
typedef unsigned long long ULL;

int cmp(const void *a, const void *b){
	ULL A = *(ULL *)a, B = *(ULL *)b;
	int A1s = 0, B1s = 0;
	for(int i = 0; i < 64; i++){
		A1s += ((A>>i) & (ULL)1);
		B1s += ((B>>i) & (ULL)1);
	}
	if(A1s != B1s)  return A1s-B1s;
	else{
		if(A > B)  return 1;
		else  return -1;
	}
}
int main(){
	ULL a[1005];
	int n = 0;
	while(scanf("%lld", &a[n]) != EOF)  n++;
	qsort(a, n, sizeof(ULL), cmp);
	for(int i = 0; i < n; i++)  printf("%lld\n", a[i]);

	return 0;
}