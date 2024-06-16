bool isUgly(int n) {
    if(n==0)return false;
    if(n==1)return true;
    int test = n;
    while(1)
    {
        if(test%2==0)
            test/=2;
        else
            break;
    }
    while(1)
    {
        if(test%3==0)
            test/=3;
        else
            break;
    }
    while(1)
    {
        if(test%5==0)
            test/=5;
        else
            break;
    }
    if(test==1)return true;
    else return false;
}