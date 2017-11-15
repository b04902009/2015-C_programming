#include <stdio.h>
int c,r,matrix[20][20],take[20],R[20],C[20],flag;
void fill(int y,int x){
	if(y == r){
		for(int i = 0;i < r;i++)
			for(int j = 0;j < c;j++)
				printf("%d%c",matrix[i][j],j == c-1 ? '\n' : ' ');
		flag = 1;
		return;
	}
	for(int i = 1;i <= r*c;i++){
		if(flag)    break;
		if(!take[i]){
			matrix[y][x] = i;
			if(R[y]-i < 0 || C[x]-i < 0)    continue;
			if(x == c-1 && R[y]-i != 0)    continue;
			if(y == r-1 && C[x]-i != 0)    continue;
			take[i] = 1;
			R[y] -= i;
			C[x] -= i;
			fill(y+(x+1)/c,(x+1)%c);
			take[i] = 0;
			R[y] += i;
			C[x] += i;
		}
	}
	if(!flag && x == 0 && y == 0)    printf("no solution\n");
}
int main()
{
	while(scanf("%d%d",&r,&c) != EOF){
		for(int i = 0;i < r;i++)
			scanf("%d",&R[i]);
		for(int i = 0;i < c;i++)
			scanf("%d",&C[i]);
		flag = 0;
		for(int i = 0;i < 20;i++)
			take[i] = 0;
		fill(0,0);
	}
	
	return 0;
}