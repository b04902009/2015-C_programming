typedef struct{
    int num;
    int co[5000];
} Polynomial;
void init(Polynomial *poly, int coefficient[], int n);
Polynomial add(Polynomial *poly1, Polynomial *poly2);
Polynomial multiply(Polynomial *poly1, Polynomial *poly2);
void print(Polynomial *poly);