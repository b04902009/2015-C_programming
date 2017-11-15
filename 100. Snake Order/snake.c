void snake(const int *ptr_array[100][100], int m)
{
    int n = 0;
    const int *index[10000];
    for(int i = 0;i < m;i ++)
        for(int j = 0;j < m;j ++){
            index[n] = ptr_array[i][j];
            n ++;
        }
    for(int i = 0;i < m*m;i ++)
        for(int j = i;j < m*m;j ++)
            if(*index[j] < *index[i]){
                const int *temp = index[i];
                index[i] = index[j];
                index[j] = temp;
            }
    n = 0;
    for(int i = 0;i < m;i ++)
        for(int j = 0;j < m;j ++){
            if(i % 2 == 0)    ptr_array[i][j] = index[n];
            else    ptr_array[i][m-j-1] = index[n];
            n ++;
        }
}
