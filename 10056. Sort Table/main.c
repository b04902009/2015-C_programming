#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int sco_n,orderarr[256];
typedef struct student{
    char name[32];
    int score[128];
} Student;
typedef struct examtable{
    int dim_n;
    int num;
    Student s[256];
} ExamTable;
void init(ExamTable *self, int n)
{
    self->dim_n = n;
    self->num = 0;
    for(int i = 0;i < 50;i ++)
        for(int j = 0;j < n;j ++)    (self->s[i]).score[j] = 0;
}
void addrow(ExamTable *self, char *Name, int Score[])
{
    strcpy((self->s[self->num]).name,Name);
    int n = self->dim_n;
    for(int i = 0;i < n;i ++)    (self->s[self->num]).score[i] = Score[i];
    self->num ++;
}
int cmp(const void* a,const void* b){
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
   /*
    for(int i = 0;i < sco_n;i ++){
        for(int j = 0;j < stu_n;j ++){
            buffer[j] = (self->s[j]).score[order[i]];
            index[j] = j;
        }
         
        for(int j = 0;j < stu_n-1;j ++)
            for(int k = 0;k < stu_n-j-1;k ++)
                if(buffer[k] < buffer[k+1]){
                    int temp = buffer[k];
                    buffer[k] = buffer[k+1];
                    buffer[k+1] = temp;
                    index[k] = k+1;
                    index[k+1] = k;
                }
        for(int j = 0;j < stu_n;j ++)    printf("%2d ",index[j]);
    }
    puts("");
    */

    puts("----- table begin -----");
    for(int i = 0;i < stu_n;i ++){
        printf("%s,",(self->s[i]).name);
        for(int j = 0;j < sco_n;j ++)
            printf(" %d%c",(self->s[i]).score[j],j == sco_n-1 ? '\n' : ',');
    }
    puts("----- end         -----");
}
int main()
{
    const int MAXETB = 8;
    int etb_n, dim_n;
    int cmds, cmd, tid, score[128], sort_order[128];
    char sid[32];
    ExamTable *etb = (ExamTable*) malloc(sizeof(ExamTable)*MAXETB);
    scanf("%d", &etb_n);
    for (int i = 0; i < etb_n; i++) {
        scanf("%d", &dim_n);
        init(&etb[i], dim_n);
    }
    scanf("%d", &cmds);
    for (int i = 0; i < cmds; i++) {
        scanf("%d %d", &cmd, &tid);
        if (cmd == 1) {
            scanf("%s", sid);
            for (int j = 0; j < etb[tid].dim_n; j++)
                scanf("%d", &score[j]);
            addrow(&etb[tid], sid, score);
        }
        else {
            for (int j = 0; j < etb[tid].dim_n; j++)
                scanf("%d", &sort_order[j]);
            print(&etb[tid], sort_order);
        }
    }
    return 0;
}