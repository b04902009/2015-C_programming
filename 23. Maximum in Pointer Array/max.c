int max(int *iptr[], int n)
{
    int Max = *iptr[0];
    for(int i = 1;i < n;i ++)
        if(*iptr[i] > Max)    Max = *iptr[i];
    return Max;
}
