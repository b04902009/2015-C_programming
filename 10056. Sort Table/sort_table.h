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
void init(ExamTable *self, int n);
void addrow(ExamTable *self, char *Name, int Score[]);
int cmp(const void* a,const void* b);
void print(ExamTable *self, int order[]);