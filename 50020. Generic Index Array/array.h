typedef struct array{
    int start,end,length;
    int arr[3000];
} ARRAY;
void init(ARRAY *a,  int left, int right);
int set(ARRAY *a, int index, int value);
int get(ARRAY *a, int index);
void print(ARRAY *a);
void sort(ARRAY *a);