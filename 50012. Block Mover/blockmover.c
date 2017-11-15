void printBlock(unsigned long long int *block)
{
    for(int i = 0;i < 64;i ++){
        printf("%lld",(*block>>i)&1ULL);
        if((i & 7) == 7)    printf("\n");
    }
}
void initialize(unsigned long long int *block, int row, int column, int size)
{
    *block = 0;
    unsigned long long add = (1ULL << size) -1;
    for(int i = row;i < row+size;i ++)
        *block |= (unsigned long long)(add << (i*8+column));
    return;
}
int moveLeft(unsigned long long int *block)
{
    if(*block & 0X0101010101010101ULL)    return 0;
    *block >>= 1;
    return 1;
}
int moveRight(unsigned long long int *block)
{
    if(*block & 0X8080808080808080ULL)    return 0;
    *block <<= 1;
    return 1;
}
int moveUp(unsigned long long int *block)
{
    if(*block & 0X00000000000000FFULL)    return 0;
    *block >>= 8;
    return 1;
}
int moveDown(unsigned long long int *block)
{
    if(*block & 0XFF00000000000000ULL)    return 0;
    *block <<= 8;
    return 1;
}
