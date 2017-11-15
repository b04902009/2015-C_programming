#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef struct student{
    char name[32];
    int score[128];
} Student;
typedef struct examtable{
    int dim_n;
    int num;
    Student s[256];
} ExamTable;
int sco_n,orderarr[256];
void init(ExamTable *self, int n)
{
    self->dim_n = n;
    self->num = 0;
}
void addrow(ExamTable *self, char *Name, int Score[])
{
    strcpy((self->s[self->num]).name,Name);
    int n = self->dim_n;
    for(int i = 0;i < n;i ++)    (self->s[self->num]).score[i] = Score[i];
    self->num ++;
}
int cmp(const void* a,const void* b)
{
    Student *c = (Student *)a;
    Student *d = (Student *)b;
    for(int i = 0;i < sco_n;i ++){
        if(c->score[orderarr[i]] == d->score[orderarr[i]])    continue;
        return d->score[orderarr[i]]-c->score[orderarr[i]];
    }
    return strcmp(c->name,d->name);
}
void print(ExamTable *self, int order[])
{
    int stu_n = self->num;
    sco_n = self->dim_n;
    for(int i = 0;i < sco_n;i ++)
        orderarr[i] = order[i];
    qsort(self->s,stu_n,sizeof(Student),cmp);

    puts("----- table begin -----");
    for(int i = 0;i < stu_n;i ++){
        printf("%s,",(self->s[i]).name);
        for(int j = 0;j < sco_n;j ++)
            printf(" %d%c",(self->s[i]).score[j],j == sco_n-1 ? '\n' : ',');
    }
    puts("----- end         -----");
}