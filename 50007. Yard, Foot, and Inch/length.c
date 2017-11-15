void init(int length[3]) {
    for(int i = 0;i < 3;i ++)
        length[i] = 0;
}
void add(int length[3], int i) {
    length[2] += i;
    if(length[2] < 0){
        length[2] += 12;
        length[1] --;
    }
    if(length[2] > 11){
        length[1] += length[2] / 12;
        length[2] = length[2] % 12;
    }
    if(length[1] > 2){
        length[0] += length[1] / 3;
        length[1] = length[1] % 3;
    }
}
void sum(int lengtha[3], int lengthb[3], int lengthc[3]) {
    for(int i = 0;i < 3;i ++)
        lengthc[i] = lengtha[i] + lengthb[i];
    if(lengthc[2] > 11){
        lengthc[1] += lengthc[2] / 12;
        lengthc[2] = lengthc[2] % 12;
    }
    if(lengthc[2] < 0){
        lengthc[2] += 12;
        lengthc[1] --;
    }
    if(lengthc[1] > 2){
        lengthc[0] += lengthc[1] / 3;
        lengthc[1] = lengthc[1] % 3;
    }
}
void diff(int lengtha[3], int lengthb[3], int lengthc[3]) {
    for(int i = 0;i < 3;i ++)
        lengthc[i] = lengtha[i] - lengthb[i];
    if(lengthc[2] < 0){
        lengthc[2] += 12;
        lengthc[1] --;
    }
    if(lengthc[1] < 0){
        lengthc[1] += 3;
        lengthc[0] --;
    }
    if(lengthc[2] > 11){
        lengthc[1] += lengthc[2] / 12;
        lengthc[2] = lengthc[2] % 12;
    }
    if(lengthc[1] > 2){
        lengthc[0] += lengthc[1] / 3;
        lengthc[1] = lengthc[1] % 3;
    }

}
