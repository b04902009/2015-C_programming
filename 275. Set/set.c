typedef unsigned long long Set;
void init(Set *set){
    *set = 0;
}
void add(Set *set, int i){
    *set |= (1ULL << i);
}
void has(Set set, int i)
{
    if((set >> i) & 1ULL)    printf("set has %d\n",i);
    else    printf("set does not have %d\n",i);
}
Set setUnion(Set a, Set b){
    return a | b;
}
Set setIntersect(Set a, Set b){
    return a & b;
}
Set setDifference(Set a, Set b){
    return a ^ b;
}
