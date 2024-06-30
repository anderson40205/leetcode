int hammingWeight(int n) {
    int sum = 0;
    while(n)
    {
        sum += (n&0x1);
        n>>=1;
    }
    return sum;
}