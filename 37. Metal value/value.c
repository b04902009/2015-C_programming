int gcd(int a,int b)
{
    int temp;
    while(a != 0){
        temp = a;
        a = b % a;
        b = temp;
    }
    return b;
}
int value(int type,int width,int height,int length)
{
    int unit_price,max = gcd(length,gcd(width,height));
    switch(type){
        case 79: unit_price = 30; break;
        case 47: unit_price = 10; break;
        case 29: unit_price = 4; break;
        case 82: unit_price = 5; break;
        case 26: unit_price = 3; break;
        case 22: unit_price = 9; break;
        default: return -1;
    }
    if(width <= 0 || height <= 0 || length <= 0)    return -2;
    int sum = unit_price * width * height * length;
    for(int i = 0;i < 3;i ++)    sum *= max;
    return sum;
}
