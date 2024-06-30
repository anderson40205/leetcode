int singleNumber(int* nums, int numsSize) {
    int count[32];
    //memset(count,0,32); wrong use about memset
    memset(count,0,sizeof(count));
    for(int i=0;i<numsSize;i++)
    {
        //transfer to binary
        for(int j=0;j<32;j++)
        {
            //check which bit is 1
            count[j] += (nums[i]>>j)&0x1;
        }
    }
    int ans = 0;
    uint32_t temp = 0;   
    
    if(count[31]%3==1)
    {
        for(int i=0;i<32;i++)
        {
            count[i]%=3;
            //printf("%d:%d\n",i,count[i]);
            if(count[i]==0) temp += pow(2,i);
        }
        temp++;
        ans = (-temp);
    }
    else
    {
        for(int i=0;i<32;i++)
        {
            count[i]%=3;
            if(count[i]==1) temp += pow(2,i);
        }
        ans = temp;
    }
    //printf("temp=%d\n",temp);
    //printf("ans=%d\n",ans);
    return ans;
}