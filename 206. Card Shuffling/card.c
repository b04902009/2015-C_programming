void shuffle(int *deck[])
{
    int i = 0,n = 0,*a[5000],*b[5000];
    while(deck[i] != 0){
        n ++;
        i ++;
    }
    for(i = 0;i < (n+1)/2;i ++)    a[i] = deck[i];
    for(i = (n+1)/2;i < n;i ++)    b[i-(n+1)/2] = deck[i];

    for(i = 0;i < n;i ++){
        if(i % 2 == 0)    deck[i] = a[i/2];
        else    deck[i] = b[(i-1)/2];
    }
}
void print(int *deck[])
{
    int i = 0,n = 0;
    while(deck[i] != 0){
        n ++;
        i ++;
    }
    for(i = 0;i < n;i ++){
        printf("%d",*deck[i]);
        if(i != n-1)    printf(" ");
    }
}
