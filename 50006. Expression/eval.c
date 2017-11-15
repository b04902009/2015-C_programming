int eval(int exp[])
{
    int n = exp[0];
    for(int i = 2;i < n;i += 2)
        if(!(exp[i] <= 4 && exp[i] >= 1))    return -2147483646;
    for(int i = 2;i < n;i += 2)
        if(exp[i] == 3){
            exp[i-1] *= exp[i+1];
            exp[i+1] = exp[i-1];
            for(int j = i;j > 0;j -= 2)
                if(exp[j] == 3 || exp[j] == 4)   exp[j-1] = exp[i+1];
                else    break;
        }
        else if(exp[i] == 4){
            if(exp[i+1] == 0)    return -2147483647;
            exp[i-1] /= exp[i+1];
            exp[i+1] = exp[i-1];
            for(int j = i;j > 0;j -= 2)
                if(exp[j] == 3 || exp[j] == 4)   exp[j-1] = exp[i+1];
                else    break;
        }
    for(int i = 2;i < n;i += 2)
        if(exp[i] == 1)    exp[1] += exp[i+1];
        else if(exp[i] == 2)    exp[1] -= exp[i+1];

    return exp[1];
}
