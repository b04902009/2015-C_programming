#include "employee.h"
int relation(Employee *employee1, Employee *employee2) {
    Employee *temp1 = employee1,*temp2 = employee2;
    while(temp1 != temp1->boss){
        temp1 = temp1->boss;
        if(temp1 == employee2)    return 1;
    }
    while(temp2 != temp2->boss){
        temp2 = temp2->boss;
        if(employee1 == temp2)    return 2;
    }
    if(temp1 == temp2)    return 3;
    else    return 4;
}