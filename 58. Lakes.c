#include <stdio.h>
int visit[402][402] = {{0}};
int lack(int pic[402][402],int r,int c,int N,int M)
{
    if(r < 1 || r > N || c < 1 || c > M)    return 0;
    if(pic[r][c] == 1 && visit[r][c] == 0){
        visit[r][c] = 1;
        return 1+lack(pic,r-1,c,N,M)+lack(pic,r+1,c,N,M)+lack(pic,r,c-1,N,M)+lack(pic,r,c+1,N,M);
    }
    else    return 0;

}
int main(void)
{
	int N,M,pic[402][402],ans[80001],n = 0;
	scanf("%d%d",&N,&M);
	for(int i = 1;i <= N;i ++)
		for(int j = 1;j <= M;j ++)
			scanf("%d",&pic[i][j]);
    for(int i = 1;i <= N;i ++)
		for(int j = 1;j <= M;j ++)
            if(visit[i][j] == 0){
                ans[n] = lack(pic,i,j,N,M);
                if(ans[n] == 0)    n --;
                n ++;
            }
    for(int i = n;i > 0;i --)
        for(int j = 0;j < i;j ++)
            if(ans[j] < ans[j+1]){
                int temp = ans[j+1];
                ans[j+1] = ans[j];
                ans[j] = temp;
            }
    for(int i = 0;i < n;i ++)
        printf("%d\n",ans[i]);

	return 0;
}
