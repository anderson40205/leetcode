int maxSubArray(int* nums, int numsSize) 
{
    int accLargest = INT_MIN;
    int realLargest = INT_MIN;
    for(int i=0;i<numsSize;i++)
    {
        //printf("%d ",nums[i]);
        if(accLargest != INT_MIN) accLargest += nums[i];
        if(accLargest < nums[i])
        {
            accLargest = nums[i];
            if(realLargest < accLargest) realLargest = accLargest;
        }
        else if(accLargest >= nums[i])
        {
            if(realLargest < accLargest) realLargest = accLargest;
        }
    }
   // printf("realLargest = %d\n",realLargest);
    return realLargest;
}