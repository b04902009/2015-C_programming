int evaluate_f(int *iptr[], int n, int *index)
{
    int max = -999999999;
    for(int i = 0;i < n;i ++)
        if(4*(*iptr[i])-6*(*(iptr[i]+1)) > max){
            max = 4*(*iptr[i])-6*(*(iptr[i]+1));
            *index = i;
        }
    return max;
}
