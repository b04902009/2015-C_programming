int bingo(const unsigned long long int *board, int *rowColumn)
{
    unsigned long long int row[8]={0XFF00000000000000,0X00FF000000000000,0X0000FF0000000000,0X000000FF00000000,0X00000000FF000000,0X0000000000FF0000,0X000000000000FF00,0X00000000000000FF};
    unsigned long long int col[8]={0X8080808080808080,0X4040404040404040,0X2020202020202020,0X1010101010101010,0X0808080808080808,0X0404040404040404,0X0202020202020202,0X0101010101010101};

    for(int i = 0;i < 8;i ++)
        if((*board & row[i]) == row[i]){
            *rowColumn = i;
            return 1;
        }
    for(int i = 0;i < 8;i ++)
        if((*board & col[i]) == col[i]){
            *rowColumn = i;
            return 2;
        }
    if((*board & 0X8040201008040201) == 0X8040201008040201){
        *rowColumn = 0;
        return 3;
    }
    if((*board & 0X0102040880402010) == 0X0102040880402010){
        *rowColumn = 1;
        return 3;
    }
    return 0;

}
