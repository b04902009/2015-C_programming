#include <stdio.h>
#include <stdlib.h>
 
#define MAXN 65536
int main() {
    FILE *fin = fopen("test", "rb");
    FILE *fout = fopen("test.enc", "wb");
    int key;
    char buf;
 
    scanf("%d", &key);
 
    while (fscanf(fin, "%c", &buf) != EOF) {
        buf ^= key;
        fprintf(fout, "%c", buf);
    }
    fclose(fout);
    fclose(fin);
    return 0;
}