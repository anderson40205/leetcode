void moveZeroes(int* nums, int numsSize) 
{
    int* newNums = (int*)malloc(sizeof(int)*numsSize);
    int newNumsIndex = 0, zeroCount = 0;
    for(int i=0;i<numsSize;i++)
    {
        if(nums[i]!=0)
        {
            newNums[newNumsIndex++] = nums[i];
        }
    }
    //printf("zeroCount = %d\n",zeroCount);
    //printf("newNumsIndex = %d\n",newNumsIndex);
    for(int i=0;i<numsSize;i++)
    {
        if(i<newNumsIndex)
            nums[i] = newNums[i];
        else if(i>=newNumsIndex)
            nums[i] = 0;
    }
    free(newNums);
}