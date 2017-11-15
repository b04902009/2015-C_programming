#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct employee{
    int id;
    char first_name[32];
    char last_name[32];
    int boss_id;
};
typedef struct employee Employee;
void init_storage(Employee **storage, int n){
    (*storage) = (Employee *)malloc(sizeof(Employee) * n);
}
void free_storage(Employee **storage){
    free(*storage);
    *storage = 0;
}
Employee* find_employee_by_id(Employee *set, int n, int id){
    for(int i = 0; i < n; i++)
        if(set[i].id == id)  return &set[i];
}
Employee* find_employee_by_name(Employee *set, int n, const char *first_name, const char *last_name){
    for(int i = 0; i < n; i++)
        if(strcmp(set[i].first_name, first_name) == 0 && strcmp(set[i].last_name, last_name) == 0)  return &set[i];
}
Employee* find_root_boss(Employee *set, int n, Employee *employee){
    Employee *boss;
    boss = find_employee_by_id(set, n, employee->boss_id);
    if(boss == employee)  return boss;
    return find_root_boss(set, n, boss);
}
Employee* boss(Employee *set, int n, Employee *employee){
    return find_employee_by_id(set, n, employee->boss_id);
}
int check_relationship(Employee *set, int n, Employee *A, Employee *B){
    Employee *temp1 = A,*temp2 = B;
    while(temp1 != boss(set, n, temp1)){
        temp1 = boss(set, n, temp1);
        if(temp1 == B)  return 1;
    }
    while(temp2 != boss(set, n, temp2)){
        temp2 = boss(set, n, temp2);
        if(A == temp2)  return 2;
    }
    if(temp1 == temp2)  return 3;
    return 0;
}
int main()
{
    int n, m;
    int i;
    Employee *set = NULL;
 
    scanf("%d", &n);
    init_storage(&set, n);
    for (i = 0 ; i < n ; i++)
        scanf("%d %s %s %d", &(set[i].id), set[i].first_name, set[i].last_name, &(set[i].boss_id));
    char first_name_A[32], first_name_B[32];
    char last_name_A[32], last_name_B[32];
    Employee *A, *B;
    int type;
 
    scanf("%d", &m);
    for (i = 0 ; i < m ; i++){
        scanf("%s %s", first_name_A, last_name_A);
        A = find_employee_by_name(set, n, first_name_A, last_name_A);
        //A = find_root_boss(set, n ,A);
        //printf("A:%s %s\n", A->first_name, A->last_name);
        scanf("%s %s", first_name_B, last_name_B);
        B = find_employee_by_name(set, n, first_name_B, last_name_B);
        /*int id_A;
        scanf("%d", &id_A);
        A = find_employee_by_id(set, n, id_A);
        printf("A:%s %s\n", A->first_name, A->last_name);*/
 
        type = check_relationship(set, n, A, B);
        switch(type){
            case 1:
                printf("subordinate\n"); break;
            case 2:
                printf("supervisor\n"); break;
            case 3:
                printf("colleague\n"); break;
            default:
                printf("unrelated\n"); break;
        }
    }
    free_storage(&set);
    return 0;
}