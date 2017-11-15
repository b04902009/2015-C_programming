int subset(int numbers[], int n, int K, int S)
{
    if(K == 0 && S == 0)    return 1;
    if(S == 0 || K <= 0 || n == 0 || S > n)    return 0;
    return subset(numbers,n-1,K,S) || subset(numbers,n-1,K-numbers[n-1],S-1);
}
