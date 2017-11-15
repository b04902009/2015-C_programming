void intersection(int map[100][100],int result[4])
{
    int n,c[102][102]={{0}};
    for(int i = 0;i < 4;i ++)  result[i] = 0;
    for(int i = 0;i < 100;i ++)
        for(int j = 0;j < 100;j ++)
            c[i+1][j+1] = map[i][j];

    for(int i = 1;i <= 100;i ++)
        for(int j = 1;j <= 100;j ++)
            if(c[i][j]) {
                switch(c[i-1][j] + c[i][j-1] + c[i][j+1] + c[i+1][j]) {
                    case 4: result[0] ++; break;
                    case 3: result[1] ++; break;
                    case 2:  if(!(c[i-1][j] && c[i+1][j]) && !(c[i][j-1] && c[i][j+1])) result[2] ++; break;
                    case 1: result[3] ++; break;
                }
            }
}
