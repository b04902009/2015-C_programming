#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "employee.h"
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