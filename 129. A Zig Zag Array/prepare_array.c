void prepare_array(int buffer[], int *array[], int row, int column[])
{
    int start = 0;
    for(int i = 0;i < row;i ++){
        array[i] = &buffer[start];
        start += column[i];
    }
}
