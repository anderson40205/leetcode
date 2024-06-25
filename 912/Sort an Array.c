/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
void merge(int* nums,int numsSize,int left,int middle,int right)
{
    int leftTemp[middle-left+1];
    int rightTemp[right-middle];
    for(int i=0;i<middle-left+1;i++)
    {
        leftTemp[i] = nums[i+left];
    }
    for(int i=0;i<right-middle;i++)
    {
        rightTemp[i] = nums[i+middle+1];
    }
    int tempi=0,tempj=0,k=left;
    while(tempi<middle-left+1 && tempj<right-middle)
    {
        if(leftTemp[tempi]<rightTemp[tempj])
        {
            nums[k++] = leftTemp[tempi++]; 
        }
        else
        {
            nums[k++] = rightTemp[tempj++]; 
        }
    }
    while(tempi<middle-left+1)
    {
        nums[k++] = leftTemp[tempi++]; 
    }
    while(tempj<right-middle)
    {
        nums[k++] = rightTemp[tempj++]; 
    }
}
void mergeSort(int* nums,int numsSize,int left,int right)
{
    if(left<right)
    {
        int middle = (left+right)/2;
        mergeSort(nums,numsSize,left,middle);
        mergeSort(nums,numsSize,middle+1,right);
        merge(nums,numsSize,left,middle,right);
    }
    
}
int* sortArray(int* nums, int numsSize, int* returnSize) {
    mergeSort(nums,numsSize,0,numsSize-1);
    int* answer = (int*)malloc(sizeof(int)*numsSize);
    for(int i=0;i<numsSize;i++)
        answer[i] = nums[i];
    //answer[0] = 1;answer[1] = 2;answer[2] = 3;answer[3] = 5;
    *returnSize = numsSize;
    return answer; 
}