int rangeBitwiseAnd(int left, int right) {
    unsigned char xor_result = 0;
    int i;
    if(left==right) return left;
    for(i=31;i>=0;i--)
    {
        xor_result = ((left>>i)&0x1) ^ ((right>>i)&0x1);
        if(xor_result==1) break;
    }
    //printf("i=%d\n",i);
    int highest = 0, ans = 0;
    if(((left>>(i+1))) && ((right>>(i+1))))
    {
        highest = i+1;
        for(int j=highest;j<32;j++)
        {
            if(((left>>j)&0x1 & (right>>j)&0x1)==1)
                ans += pow(2.0,j);
        }
        
    }
    //printf("highest=%d\n",highest);
    //printf("ans=%d\n",ans);
    return ans;
}