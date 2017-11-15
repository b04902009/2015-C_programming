#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct {
    int balance;
    char name[128];
    int gender;
} Account;
int valid(Account a){
    if(a.balance < 0)  return 0;
    if(!(a.gender == 0 || a.gender == 1))  return 0;
    int n = strlen(a.name);
    for(int i = 0; i < n; i++)
        if(!((a.name[i] >= 'A' && a.name[i] <= 'Z') || (a.name[i] >= 'a' && a.name[i] <= 'z') || a.name[i] == ' '))  return 0;
    return 1;
}
int cmp(const void *ca,const void *cb){
    Account a = *(Account*)ca,b = *(Account*)cb;
    return strcmp(a.name,b.name);
}
int main()
{
    char name_in[1024],name_out[1024];
    scanf("%s", name_in);
    scanf("%s", name_out);
    FILE *fin = fopen(name_in, "rb");
    FILE *fout = fopen(name_out, "wb");
    Account a,ans[1024];
    int n = 0;
    while(fread(&a, sizeof(Account), 1, fin) != 0)
        if(valid(a)){
            ans[n] = a;
            n++;
        }
    qsort(ans, n, sizeof(Account), cmp);

    for(int i = 0; i < n; i++)
        fwrite(&ans[i], sizeof(Account), 1, fout);

    fclose(fin);
    fclose(fout);
    return 0;
}
