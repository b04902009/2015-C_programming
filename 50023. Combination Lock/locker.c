#include "locker.h"
void init(Lock *lock){
    lock->flag = 0;
}
int lock(Lock *lock, int combination){
    if(lock->flag)    return -1;
    if(combination < 10000 && combination >= 0){
        lock->com = combination;
        lock->flag = 1;
        return combination;
    }
    return 10000;
}
int unlock(Lock *lock, int combination){
    if(!lock->flag)    return -1;
    if(combination == lock->com){
        lock->flag = 0;
        return 0;
    }
    return 1;
}
int isLocked(Lock *lock){
    return lock->flag;
}