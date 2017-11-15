#include <stdio.h>
#include <stdio.h>
int hasEOF = 0;
int readchar()
{
    static int N = 1<<20;
    static char buf[1<<20];
    static char *p = buf,*end = buf;
    if(p == end) {
        if((end = buf + fread(buf,1,N,stdin)) == buf){
            hasEOF = 1;
            return EOF;
        }
        p = buf;
    }
    return *p++;
}
int ReadInt(int *x)
{
    char c, neg;
    while((c = readchar()) < '-')    if(c == EOF) return 0;
    neg = (c == '-') ? -1 : 1;
    *x = (neg == 1) ? c-'0' : 0;
    while((c = readchar()) >= '0')
        *x = (*x << 3) + (*x << 1) + c-'0';
    *x *= neg;
    return 1;
}
int main(void)
{
    int num,flag,book;
    unsigned long long int bookshelf = 0,judge,move,add;
    while(ReadInt(&book)){
        flag = 1;
        for(int i = 56;i >= 0;i -= 8){
            judge = 255ULL << i;
            if((bookshelf&judge) >> i == book){
                flag = 0;
                move = (1ULL << i) - 1;
                add = (bookshelf&move) << 8;
                move = (1ULL << (i+8)) - 1;
                if(i == 56)    move = ~0ULL;
                bookshelf += add + book - (bookshelf&move);
                break;
            }
        }
        if(flag)    bookshelf = (bookshelf << 8) + book;
    }
    for(int i = 56;i >= 0;i -= 8){
        judge = 255ULL << i;
        printf("%llu",(bookshelf&judge) >> i);
        if(i!= 0)    printf(" ");
    }

    return 0;
}
