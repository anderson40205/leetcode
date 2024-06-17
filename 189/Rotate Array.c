void rotate(int* nums, int numsSize, int k) {
    int answer[numsSize];
    int count = 0;
    if(numsSize<k)
    {
        int position = (k%numsSize);
        for(int j=position;j<numsSize;j++)
        {
            answer[j] = nums[count++];
        }
        for(int j=0;j<position;j++)
        {
            answer[j] = nums[count++];
        }
    }
    else
    {
        for(int i=numsSize-k;i<numsSize;i++)
        {
            answer[count++] = nums[i];
        }
        for(int i=0;i<numsSize-k;i++)
        {
            answer[count++] = nums[i];
        }
    }
    for(int i=0;i<numsSize;i++) nums[i] = answer[i];
}