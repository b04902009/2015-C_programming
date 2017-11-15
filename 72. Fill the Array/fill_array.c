void fill_array(int *ptr[], int n)
{
    for(int i = 0;i < n;i ++)   *ptr[i] = i;
    for(int i = 0;i < n;i ++)
        for(int j = i;j < n;j ++)
            if(ptr[j] < ptr[i]){
                int *temp = ptr[i];
                ptr[i] = ptr[j];
                ptr[j] = temp;
            }
    for(int i = 0;i < n-1;i ++)
        for(int *j = ptr[i]+1;j < ptr[i+1];j ++)
            *j = *ptr[i] + *ptr[i+1];
}
